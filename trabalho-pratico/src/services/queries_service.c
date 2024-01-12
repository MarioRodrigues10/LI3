#define _DEFAULT_SOURCE

#include "services/queries_service.h"

#include <ctype.h>
#include <glib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "utils/utils.h"

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"
// In this file it is supposed pass to the query functions ONLY THE NEEDED data
// structs, not all of them

void query1(bool has_f, char **query_parameters, FlightsData *flights_data,
            ReservationsData *reservations_data, UsersData *users_data,
            FILE *output_file) {
  char *id = query_parameters[0];

  if (strncmp(id, "Book", 4) == 0) {
    ReservationInfo *reservation_info = get_reservation_by_reservation_id(
        reservations_data, normalize_reservation_id(id));

    if (reservation_info == NULL) return;

    int price_per_night = get_price_per_night(reservation_info);
    char city_tax = get_city_tax(reservation_info);

    int hotel_id_int = get_hotel_id(reservation_info);
    char *hotel_id = malloc(sizeof(char) * 10);
    sprintf(hotel_id, "HTL%d", hotel_id_int);
    char *hotel_name = get_hotel_name(reservation_info);
    char hotel_stars = get_hotel_stars(reservation_info);
    char *begin_date = date_to_string(get_begin_date(reservation_info));
    char *end_date = date_to_string(get_end_date(reservation_info));
    char *breakfast =
        get_includes_breakfast(reservation_info) ? "True" : "False";
    int number_of_nights = calculate_number_of_nights(begin_date, end_date);
    double total_price =
        calculate_total_price(number_of_nights, price_per_night, city_tax);

    write_query1_for_reservation(has_f, output_file, hotel_id, hotel_name,
                                 hotel_stars, begin_date, end_date, breakfast,
                                 number_of_nights, total_price);
    free(begin_date);
    free(end_date);
    free(hotel_id);
    free(hotel_name);
  }

  if (isdigit(id[0]) && isdigit(id[1])) {
    int new_id = strtol(id, NULL, 10);
    FlightInfo *flight_info = get_flight_by_flight_id(flights_data, new_id);

    if (flight_info == NULL) return;

    char *real_departure_date = get_real_departure_date(flight_info);

    char *airline_company = get_airline(flight_info);
    char *plane_model = get_plane_model(flight_info);
    char *origin = get_origin(flight_info);
    char *destination = get_destination(flight_info);
    char *schedule_departure_date = get_schedule_departure_date(flight_info);
    char *schedule_arrival_date = get_schedule_arrival_date(flight_info);
    int passengers = get_number_of_passengers_from_flight_stats(
        get_flight_stats_by_flight_id(flights_data, new_id));
    int delay = calculate_delay(schedule_departure_date, real_departure_date);

    write_query1_for_flight(has_f, output_file, airline_company, plane_model,
                            origin, destination, schedule_departure_date,
                            schedule_arrival_date, passengers, delay);
    free(schedule_departure_date);
    free(schedule_arrival_date);
    free(plane_model);
    free(origin);
    free(destination);
    free(airline_company);
    free(real_departure_date);
  }

  UserInfo *user_info = get_user_by_username(users_data, id);

  if (user_info == NULL) return;

  bool account_status = get_account_status(user_info);

  if (account_status) {
    char *name = get_name(user_info);
    char *sex = get_sex(user_info) ? "M" : "F";
    int age = calculate_age(get_birth_date(user_info));
    char *country_code = get_country_code(user_info);
    char *passport = get_passport(user_info);
    int number_of_flights = get_number_of_flights_from_user_stats(
        get_user_stats_by_user_id(users_data, id));
    int number_of_reservations = get_number_of_reservations_from_user_stats(
        get_user_stats_by_user_id(users_data, id));
    double total_spent = get_total_spent_from_user_stats(
        get_user_stats_by_user_id(users_data, id));

    write_query1_for_user(has_f, output_file, name, sex, age, country_code,
                          passport, number_of_flights, number_of_reservations,
                          total_spent);
    free(name);
    free(country_code);
    free(passport);
  }
}

struct query2_result_helper {
  char *id;
  char *date;
  char *type;
};

struct query2_result {
  GArray *query2_result;
};

void query2(bool has_f, char **query_parameters, FlightsData *flights_data,
            ReservationsData *reservations_data, UsersData *users_data,
            FILE *output_file, int N) {
  char *id = query_parameters[0];
  char *type = "NULL";
  if (N == 2) {
    type = query_parameters[1];
  }

  UserInfo *user = get_user_by_username(users_data, id);

  if (user == NULL) return;

  bool account_status = get_account_status(user);

  if (!account_status) return;

  UserStats *user_stats = get_user_stats_by_user_id(users_data, id);
  if (strcmp(type, "flights") == 0) {
    query2_flights(has_f, user_stats, flights_data, output_file);
  } else if (strcmp(type, "reservations") == 0) {
    query2_reservations(has_f, user_stats, reservations_data, output_file);
  } else {
    query2_both(has_f, user_stats, flights_data, reservations_data,
                output_file);
  }
}

void query2_flights(bool has_f, UserStats *user_stats,
                    FlightsData *flights_data, FILE *output_file) {
  GArray *flights = get_user_flights_from_user_stats(user_stats);
  if (flights == NULL) return;
  int len = flights->len;

  QUERY2_RESULT result = malloc(sizeof(QUERY2_RESULT));
  result->query2_result =
      g_array_new(FALSE, FALSE, sizeof(QUERY2_RESULT_HELPER));

  query2_seed_flights(flights_data, "nada", flights, result->query2_result,
                      len);
  sort_by_date(result, len);
  write_query2(has_f, output_file, result->query2_result);
  for (guint i = 0; i < result->query2_result->len; i++) {
    free(g_array_index(result->query2_result, QUERY2_RESULT_HELPER, i)->id);
    free(g_array_index(result->query2_result, QUERY2_RESULT_HELPER, i)->date);
    free(g_array_index(result->query2_result, QUERY2_RESULT_HELPER, i)->type);
    free(g_array_index(result->query2_result, QUERY2_RESULT_HELPER, i));
  }
  g_array_free(result->query2_result, TRUE);
  free(result);
}

void query2_reservations(bool has_f, UserStats *user_stats,
                         ReservationsData *reservations_data,
                         FILE *output_file) {
  GArray *reservations = get_user_reservations_from_user_stats(user_stats);
  if (reservations == NULL) return;

  int len = reservations->len;
  QUERY2_RESULT result = malloc(sizeof(QUERY2_RESULT));
  result->query2_result =
      g_array_new(FALSE, FALSE, sizeof(QUERY2_RESULT_HELPER));

  query2_seed_reservations(reservations_data, "nada", reservations,
                           result->query2_result, len);
  sort_by_date(result, len);
  write_query2(has_f, output_file, result->query2_result);

  for (guint i = 0; i < result->query2_result->len; i++) {
    free(g_array_index(result->query2_result, QUERY2_RESULT_HELPER, i)->id);
    free(g_array_index(result->query2_result, QUERY2_RESULT_HELPER, i)->date);
    free(g_array_index(result->query2_result, QUERY2_RESULT_HELPER, i)->type);
    free(g_array_index(result->query2_result, QUERY2_RESULT_HELPER, i));
  }
  g_array_free(result->query2_result, TRUE);
  free(result);
}

void query2_both(bool has_f, UserStats *user_stats, FlightsData *flights_data,
                 ReservationsData *reservations_data, FILE *output_file) {
  GArray *flights = get_user_flights_from_user_stats(user_stats);
  GArray *reservations = get_user_reservations_from_user_stats(user_stats);

  if (flights == NULL && reservations == NULL) return;

  int max = flights->len + reservations->len;

  QUERY2_RESULT result = malloc(sizeof(QUERY2_RESULT));
  result->query2_result =
      g_array_new(FALSE, FALSE, sizeof(QUERY2_RESULT_HELPER));

  query2_seed_flights(flights_data, "flight", flights, result->query2_result,
                      flights->len);

  query2_seed_reservations(reservations_data, "reservation", reservations,
                           result->query2_result, reservations->len);

  sort_by_date(result, max);
  write_query2(has_f, output_file, result->query2_result);

  for (guint i = 0; i < result->query2_result->len; i++) {
    free(g_array_index(result->query2_result, QUERY2_RESULT_HELPER, i)->id);
    free(g_array_index(result->query2_result, QUERY2_RESULT_HELPER, i)->date);
    free(g_array_index(result->query2_result, QUERY2_RESULT_HELPER, i)->type);
    free(g_array_index(result->query2_result, QUERY2_RESULT_HELPER, i));
  }
  g_array_free(result->query2_result, TRUE);
  free(result);
}

void query2_seed_flights(FlightsData *flights_data, char *type, GArray *array,
                         GArray *output_array, int len) {
  for (int i = 0; i < len; i++) {
    int id = g_array_index(array, int, i);
    FlightInfo *flight = get_flight_by_flight_id(flights_data, id);
    if (flight == NULL) return;
    QUERY2_RESULT_HELPER result_helper = malloc(sizeof(QUERY2_RESULT_HELPER));
    char *date = get_schedule_departure_date(flight);

    char *flight_id_str = int_to_flight_id(id, count_digits(id));

    result_helper->id = strdup(flight_id_str);
    result_helper->date = strdup(date);
    result_helper->type = strdup(type);

    g_array_append_val(output_array, result_helper);
    free(date);
    free(flight_id_str);
  }
}

void query2_seed_reservations(ReservationsData *reservations_data, char *type,
                              GArray *array, GArray *output_array, int len) {
  for (int i = 0; i < len; i++) {
    int id = g_array_index(array, int, i);
    ReservationInfo *reservation =
        get_reservation_by_reservation_id(reservations_data, id);
    if (reservation == NULL) return;

    QUERY2_RESULT_HELPER result_helper = malloc(sizeof(QUERY2_RESULT_HELPER));
    char *reservation_id = int_to_reservation_id(id);
    char *date = date_to_string(get_begin_date(reservation));

    char *new_date = concatenate_strings(date, " 00:00:00");

    result_helper->id = strdup(reservation_id);
    result_helper->date = strdup(new_date);
    result_helper->type = strdup(type);

    g_array_append_val(output_array, result_helper);
    free(reservation_id);
    free(new_date);
    free(date);
  }
}

void query3(bool has_f, char **query_parameters,
            ReservationsData *reservations_data, FILE *output_file) {
  char *id = query_parameters[0];

  HotelStats *hotel_stats = get_hotel_stats_by_hotel_id(reservations_data, id);

  if (hotel_stats == NULL) return;

  int total_rating = get_total_rating_from_hotel_stats(
      get_hotel_stats_by_hotel_id(reservations_data, id));

  int number_of_clients = get_number_of_clients_from_hotel_stats(
      get_hotel_stats_by_hotel_id(reservations_data, id));

  double media_of_ratings = (double)total_rating / number_of_clients;

  write_query3(has_f, output_file, media_of_ratings);
}

struct query4_result_helper {
  char *reservation_id;
  char *begin_date;
  char *end_date;
  char *user_id;
  double total_price;
  char rating;
};

struct query4_result {
  GArray *query4_result;
};

void query4(bool has_f, char **query_parameters,
            ReservationsData *reservations_data, FILE *output_file) {
  char *id = query_parameters[0];
  HotelStats *hotel_stats = get_hotel_stats_by_hotel_id(reservations_data, id);
  if (hotel_stats == NULL) return;
  GArray *reservations = get_hotel_reservations(hotel_stats);
  if (reservations == NULL) return;

  QUERY4_RESULT result = malloc(sizeof(struct query4_result));
  result->query4_result =
      g_array_new(FALSE, FALSE, sizeof(QUERY4_RESULT_HELPER));

  guint i = 0;
  int j = 0;
  for (i = 0; i < reservations->len; i++) {
    int reservation_id = g_array_index(reservations, int, i);
    if (reservation_id > 0) {
      QUERY4_RESULT_HELPER result_helper =
          malloc(sizeof(struct query4_result_helper));
      ReservationInfo *reservation =
          get_reservation_by_reservation_id(reservations_data, reservation_id);
      char *begin_date = date_to_string(get_begin_date(reservation));
      char *end_date = date_to_string(get_end_date(reservation));
      char rating = get_rating(reservation);
      int price_per_night = get_price_per_night(reservation);
      double total_price = calculate_total_price(
          calculate_number_of_nights(begin_date, end_date), price_per_night,
          get_city_tax(reservation));
      char *user_id = get_user_id_reservation(reservation);
      char *id = int_to_reservation_id(reservation_id);
      result_helper->reservation_id = strdup(id);
      result_helper->begin_date = strdup(begin_date);
      result_helper->end_date = strdup(end_date);
      result_helper->user_id = strdup(user_id);
      result_helper->rating = rating;
      result_helper->total_price = total_price;
      g_array_append_val(result->query4_result, result_helper);
      j++;
      free(id);
      free(begin_date);
      free(end_date);
      free(user_id);
    }
  }
  int N = j--;

  sort_by_date_and_value(result, N);
  write_query4(has_f, output_file, result->query4_result);

  for (int i = 0; i < N; i++) {
    free(g_array_index(result->query4_result, QUERY4_RESULT_HELPER, i)
             ->reservation_id);
    free(g_array_index(result->query4_result, QUERY4_RESULT_HELPER, i)
             ->begin_date);
    free(g_array_index(result->query4_result, QUERY4_RESULT_HELPER, i)
             ->end_date);
    free(
        g_array_index(result->query4_result, QUERY4_RESULT_HELPER, i)->user_id);
    free(g_array_index(result->query4_result, QUERY4_RESULT_HELPER, i));
  }

  g_array_free(result->query4_result, TRUE);
  free(result);
}

struct query5_result_helper {
  char *flight_id;
  char *departure_date;
  char *destination;
  char *airline;
  char *plane_model;
};

struct query5_result {
  GArray *query5_result;
};

void query5(bool has_f, char **query_parameters, FlightsData *flights_data,
            FILE *output_file) {
  char *id = query_parameters[0];

  if (query_parameters[1] == NULL || query_parameters[2] == NULL ||
      query_parameters[3] == NULL || query_parameters[4] == NULL)
    return;

  char *begin_date =
      concatenate_and_modify_strings(query_parameters[1], query_parameters[2]);
  char *end_date =
      concatenate_and_modify_strings(query_parameters[3], query_parameters[4]);

  AirportStats *airport_stats =
      get_airport_stats_by_airport_name(flights_data, id);

  if (airport_stats == NULL) return;

  GArray *flights = get_airport_flights_from_airport_stats(airport_stats);

  if (flights == NULL) return;

  QUERY5_RESULT result = malloc(sizeof(struct query5_result));
  result->query5_result =
      g_array_new(FALSE, FALSE, sizeof(QUERY5_RESULT_HELPER));

  for (guint i = 0; i < flights->len; ++i) {
    int flight_id = g_array_index(flights, int, i);
    FlightInfo *flight = get_flight_by_flight_id(flights_data, flight_id);
    char *departure_date = get_schedule_departure_date(flight);
    char *destination = get_destination(flight);
    char *airline = get_airline(flight);
    char *plane_model = get_plane_model(flight);

    char *flight_id_str = int_to_flight_id(flight_id, count_digits(flight_id));
    if (strcmp(departure_date, begin_date) >= 0 &&
        strcmp(departure_date, end_date) <= 0) {
      QUERY5_RESULT_HELPER result_helper =
          malloc(sizeof(struct query5_result_helper));
      result_helper->flight_id = strdup(flight_id_str);
      result_helper->departure_date = strdup(departure_date);
      result_helper->destination = strdup(destination);
      result_helper->airline = strdup(airline);
      result_helper->plane_model = strdup(plane_model);
      g_array_append_val(result->query5_result, result_helper);
    }
    free(flight_id_str);
    free(departure_date);
    free(destination);
    free(airline);
    free(plane_model);
  }
  int N = result->query5_result->len;
  sort_by_departure_date(result, N);

  write_query5(has_f, output_file, result->query5_result);

  for (int i = 0; i < N; i++) {
    free(g_array_index(result->query5_result, QUERY5_RESULT_HELPER, i)
             ->flight_id);
    free(g_array_index(result->query5_result, QUERY5_RESULT_HELPER, i)
             ->departure_date);
    free(g_array_index(result->query5_result, QUERY5_RESULT_HELPER, i)
             ->destination);
    free(
        g_array_index(result->query5_result, QUERY5_RESULT_HELPER, i)->airline);
    free(g_array_index(result->query5_result, QUERY5_RESULT_HELPER, i)
             ->plane_model);
    free(g_array_index(result->query5_result, QUERY5_RESULT_HELPER, i));
  }

  g_array_free(result->query5_result, TRUE);
  free(begin_date);
  free(end_date);
  free(result);
}

struct query7_result {
  char *airport;
  int median_delay;
};
struct airport_info {
  int year;
  GHashTable *airports_list;
};
void query6(bool has_f, char **query_parameters, FlightsData *flights_data,
            FILE *output_file) {
  if (query_parameters[0] == NULL || query_parameters[1] == NULL) return;

  int year = strtol(query_parameters[0], NULL, 10);
  int length = strtol(query_parameters[1], NULL, 10);

  GArray *output = g_array_new(FALSE, FALSE, sizeof(struct query7_result));

  GHashTable *airport = get_airports_list(flights_data, year * 10000);

  if (airport == NULL) return;

  g_hash_table_foreach(airport, (GHFunc)get_airport_info_list, output);

  g_array_sort(output, (GCompareFunc)compare_median);

  if (length > (int)output->len) length = output->len;

  char **airport_output = malloc(sizeof(char *) * length);
  int *number_of_passengers = malloc(sizeof(int) * length);

  for (int i = 0; i < length && i < (int)output->len; i++) {
    struct query7_result *result =
        &g_array_index(output, struct query7_result, i);

    airport_output[i] = result->airport;
    number_of_passengers[i] = result->median_delay;
  }

  write_query6(has_f, output_file, airport_output, number_of_passengers,
               length);

  g_array_free(output, TRUE);
  free(airport_output);
  free(number_of_passengers);
}

void query7(bool has_f, char **query_parameters, FlightsData *flights_data,
            FILE *output_file) {
  guint length = strtol(query_parameters[0], NULL, 10);
  GArray *medians = g_array_new(FALSE, FALSE, sizeof(struct query7_result));

  GHashTable *airport = get_airport_stats(flights_data);

  if (airport == NULL) return;

  g_hash_table_foreach(airport, (GHFunc)calculate_median_for_airport, medians);

  g_array_sort(medians, (GCompareFunc)compare_median);

  if (length > medians->len) length = medians->len;

  char **airport_result = malloc(sizeof(char *) * length);
  int *medians_result = malloc(sizeof(int) * length);

  for (guint i = 0; i < length && i < medians->len; i++) {
    struct query7_result *result =
        &g_array_index(medians, struct query7_result, i);

    airport_result[i] = result->airport;
    medians_result[i] = result->median_delay;
  }

  write_query7(has_f, output_file, airport_result, medians_result, length);
  for (guint i = 0; i < length; i++) {
    g_free(airport_result[i]);
  }
  free(airport_result);
  free(medians_result);

  g_array_free(medians, TRUE);
}

void query8(bool has_f, char **query_parameters,
            ReservationsData *reservations_data, FILE *output_file) {
  char *id = query_parameters[0];
  char *begin_date_str = query_parameters[1];
  char *end_date_str = query_parameters[2];
  HotelStats *hotel_stats = get_hotel_stats_by_hotel_id(reservations_data, id);
  if (hotel_stats == NULL) return;
  GArray *reservations = get_hotel_reservations(hotel_stats);
  if (reservations == NULL) return;

  double revenue = 0;

  int begin_date = normalize_date(begin_date_str);
  int end_date = normalize_date(end_date_str);

  for (guint i = 0; i < reservations->len; i++) {
    int reservation_id = g_array_index(reservations, int, i);
    ReservationInfo *reservation =
        get_reservation_by_reservation_id(reservations_data, reservation_id);

    int begin_date_reservation = (get_begin_date(reservation));
    int end_date_reservation = (get_end_date(reservation));

    if (begin_date_reservation <= end_date &&
        end_date_reservation >= begin_date) {
      int min_date = (begin_date_reservation > begin_date)
                         ? begin_date_reservation
                         : begin_date;

      int max_date =
          (end_date_reservation < end_date) ? end_date_reservation : end_date;

      int num_nights =
          (max_date - min_date) + ((max_date < end_date_reservation) ? 1 : 0);

      if (num_nights > 0) {
        int price_per_night = get_price_per_night(reservation);
        revenue += price_per_night * num_nights;
      }
    }
  }

  write_query8(has_f, output_file, revenue);
}

struct user_info {
  char *user_id;
  char *user_name;
};

void query9(bool has_f, char **query_parameters, UsersData *users_data,
            StatsUserInfo *users_stats, FILE *output_file, int num_parameters) {
  if (query_parameters[0] == NULL) return;
  char *prefix = create_prefix(query_parameters, num_parameters);

  if (prefix == NULL) return;
  GArray *stats_user = get_stats_user_info(users_stats);
  if (stats_user == NULL) return;
  char **user_ids = malloc(sizeof(char *) * stats_user->len);
  char **user_names = malloc(sizeof(char *) * stats_user->len);
  GArray *respond = g_array_new(FALSE, FALSE, sizeof(UserInfoStats *));

  g_array_sort(stats_user, (GCompareFunc)compare);

  guint matched_index;
  gboolean aux = g_array_binary_search(
      stats_user, prefix, (GCompareFunc)check_prefix, &matched_index);

  if (aux) {
    UserInfoStats *matched_user =
        g_array_index(stats_user, UserInfoStats *, matched_index);
    for (int i = matched_index; i >= 0 && strncmp(matched_user->user_name,
                                                  prefix, strlen(prefix)) == 0;
         i--) {
      bool account_status = get_account_status(
          get_user_by_username(users_data, matched_user->user_id));

      if (account_status) {
        g_array_prepend_val(respond,
                            g_array_index(stats_user, UserInfoStats *, i));
      }
      matched_user = g_array_index(stats_user, UserInfoStats *, i - 1);
    }

    matched_user =
        g_array_index(stats_user, UserInfoStats *, matched_index + 1);

    for (guint j = matched_index + 1;
         j < stats_user->len &&
         strncmp(matched_user->user_name, prefix, strlen(prefix)) == 0;
         j++) {
      bool account_status = get_account_status(
          get_user_by_username(users_data, matched_user->user_id));
      if (account_status) {
        g_array_append_val(respond,
                           g_array_index(stats_user, UserInfoStats *, j));
      }
      matched_user = g_array_index(stats_user, UserInfoStats *, j + 1);
    }

    g_array_sort(respond, (GCompareFunc)compare_respond);

    for (int k = 0; k < (int)respond->len; k++) {
      UserInfoStats *user =
          (UserInfoStats *)(g_array_index(respond, void *, k));

      user_ids[k] = (user->user_id);
      user_names[k] = (user->user_name);
    }
  }
  write_query9(has_f, output_file, user_ids, user_names, respond->len);
  g_array_free(respond, TRUE);
  free(user_names);
  free(user_ids);
}

void query10(bool has_f, char **query_parameters, int num_parameters,
             GeneralData *general_data, FILE *output_file) {
  char *parameter = query_parameters[0];
  if (num_parameters == 1 && !isdigit(parameter[0])) {
    int pos = 0;
    int years_array[14];
    int number_of_users_array[14];
    int number_of_flights_array[14];
    int number_of_passengers_array[14];
    int number_of_reservations_array[14];
    int number_of_unique_passengers_array[14];
    for (int year = 2010; year < 2024; year++) {
      int date_temp = year * 10000;
      GeneralStats *general_stats =
          get_general_stats_by_key(general_data, date_temp);
      if (general_stats != NULL) {
        int number_of_users = get_users_from_general_stats(general_stats);
        int number_of_flights =
            get_number_of_flights_from_general_stats(general_stats);
        int number_of_passengers =
            get_number_of_passengers_from_general_stats(general_stats);
        int number_of_unique_passengers =
            get_unique_passengers_from_general_stats(general_stats);
        int number_of_reservations =
            get_reservations_from_general_stats(general_stats);

        years_array[pos] = year;
        number_of_users_array[pos] = number_of_users;
        number_of_flights_array[pos] = number_of_flights;
        number_of_passengers_array[pos] = number_of_passengers;
        number_of_reservations_array[pos] = number_of_reservations;
        number_of_unique_passengers_array[pos] =
            number_of_unique_passengers - 1;
      }
      pos++;
    }
    write_query10(has_f, output_file, years_array, number_of_users_array,
                  number_of_flights_array, number_of_passengers_array,
                  number_of_unique_passengers_array,
                  number_of_reservations_array, "year", pos);
  } else if (num_parameters == 1 && isdigit(parameter[0])) {
    int year = strtol(query_parameters[0], NULL, 10);
    int months_array[12];
    int number_of_users_array[12];
    int number_of_flights_array[12];
    int number_of_passengers_array[12];
    int number_of_reservations_array[12];
    int number_of_unique_passengers_array[12];
    int month, pos = 0;
    for (month = 1; month < 13; month++) {
      int date_temp = year * 10000 + month * 100;
      GeneralStats *general_stats =
          get_general_stats_by_key(general_data, date_temp);
      if (general_stats != NULL) {
        int number_of_users = get_users_from_general_stats(general_stats);
        int number_of_flights =
            get_number_of_flights_from_general_stats(general_stats);
        int number_of_passengers =
            get_number_of_passengers_from_general_stats(general_stats);
        int number_of_unique_passengers =
            get_unique_passengers_from_general_stats(general_stats);
        int number_of_reservations =
            get_reservations_from_general_stats(general_stats);

        months_array[pos] = month;
        number_of_users_array[pos] = number_of_users;
        number_of_flights_array[pos] = number_of_flights;
        number_of_passengers_array[pos] = number_of_passengers;
        number_of_reservations_array[pos] = number_of_reservations;
        number_of_unique_passengers_array[pos] =
            number_of_unique_passengers - 1;
        pos++;
      } else
        break;
    }
    write_query10(has_f, output_file, months_array, number_of_users_array,
                  number_of_flights_array, number_of_passengers_array,
                  number_of_unique_passengers_array,
                  number_of_reservations_array, "month", pos);
  } else if (num_parameters == 2) {
    int year = strtol(query_parameters[0], NULL, 10),
        month = strtol(query_parameters[1], NULL, 10), pos = 0;
    int days_array[31], number_of_users_array[31], number_of_flights_array[31],
        number_of_passengers_array[31], number_of_reservations_array[31],
        number_of_unique_passengers_array[31];

    for (int day = 1; day < 32; day++) {
      int date_temp = year * 10000 + month * 100 + day;
      GeneralStats *general_stats =
          get_general_stats_by_key(general_data, date_temp);
      if (general_stats != NULL) {
        int number_of_users = get_users_from_general_stats(general_stats);
        int number_of_flights =
            get_number_of_flights_from_general_stats(general_stats);
        int number_of_passengers =
            get_number_of_passengers_from_general_stats(general_stats);
        int number_of_unique_passengers =
            get_unique_passengers_from_general_stats(general_stats);
        int number_of_reservations =
            get_reservations_from_general_stats(general_stats);

        days_array[pos] = day;
        number_of_users_array[pos] = number_of_users;
        number_of_flights_array[pos] = number_of_flights;
        number_of_passengers_array[pos] = number_of_passengers;
        number_of_reservations_array[pos] = number_of_reservations;
        number_of_unique_passengers_array[pos] =
            number_of_unique_passengers - 1;
        pos++;
      }
    }
    write_query10(has_f, output_file, days_array, number_of_users_array,
                  number_of_flights_array, number_of_passengers_array,
                  number_of_unique_passengers_array,
                  number_of_reservations_array, "day", pos);
  }
}

void query_manager(char *line, FlightsData *flights_data,
                   ReservationsData *reservations_data,
                   GeneralData *general_data, UsersData *users_data,
                   StatsUserInfo *users_stats, FILE *output_file) {
  int query_type;
  char modifier;
  char *parameters = malloc(sizeof(char) * 100);
  sscanf(line, "%d%c %[^\n]", &query_type, &modifier, parameters);

  bool has_f = (modifier == 'F');

  char **query_parameters = NULL;
  int num_parameters = 0;
  char *parameters_copy = parameters;

  char *token = strsep(&parameters_copy, " ");
  while (token != NULL) {
    query_parameters =
        realloc(query_parameters, (num_parameters + 1) * sizeof(char *));
    query_parameters[num_parameters] = malloc(strlen(token) + 1);
    strcpy(query_parameters[num_parameters], token);
    num_parameters++;
    token = strsep(&parameters_copy, " ");
  }
  free(parameters_copy);
  free(parameters);

  switch (query_type) {
    case 1:
      query1(has_f, query_parameters, flights_data, reservations_data,
             users_data, output_file);
      break;
    case 2:
      query2(has_f, query_parameters, flights_data, reservations_data,
             users_data, output_file, num_parameters);
      break;
    case 3:
      query3(has_f, query_parameters, reservations_data, output_file);
      break;
    case 4:
      query4(has_f, query_parameters, reservations_data, output_file);
      break;
    case 5:
      query5(has_f, query_parameters, flights_data, output_file);
      break;
    case 6:
      query6(has_f, query_parameters, flights_data, output_file);
      break;
    case 7:
      query7(has_f, query_parameters, flights_data, output_file);
      break;
    case 8:
      query8(has_f, query_parameters, reservations_data, output_file);
      break;
    case 9:
      query9(has_f, query_parameters, users_data, users_stats, output_file,
             num_parameters);
      break;
    case 10:
      query10(has_f, query_parameters, num_parameters, general_data,
              output_file);
      break;
    default:
      // This is not supposed to happen
      printf("Error choosing the query\n");
      break;
  }

  for (int i = 0; i < num_parameters; ++i) {
    free(query_parameters[i]);
  }
  free(query_parameters);
}

void write_input(bool has_f, int query_type, int line, double time) {
  if (has_f) {
    if (line == 0) {
      printf(GREEN "Query %dF is correct\n" RESET, query_type);
    } else {
      printf(RED "Query %dF is wrong\n", query_type);
      printf(RED "Diferença na linha %d\n" RESET, line);
    }
  } else {
    if (line == 0) {
      printf(GREEN "Query %d is correct\n" RESET, query_type);
    } else {
      printf(RED "Query %d is wrong\n", query_type);
      printf(RED "Diferença na linha %d\n" RESET, line);
    }
  }
  printf(YELLOW "This Query took %f seconds to execute \n" RESET, time);
}

void query_manager_test(char *line, FlightsData *flights_data,
                        ReservationsData *reservations_data,
                        GeneralData *general_data, UsersData *users_data,
                        StatsUserInfo *users_stats, FILE *output_file,
                        FILE *output_file_expected) {
  int query_type;
  char modifier;
  char *parameters = malloc(sizeof(char) * 100);
  sscanf(line, "%d%c %[^\n]", &query_type, &modifier, parameters);

  bool has_f = (modifier == 'F');

  char **query_parameters = NULL;
  int num_parameters = 0;
  char *parameters_copy = parameters;

  char *token = strsep(&parameters_copy, " ");
  while (token != NULL) {
    query_parameters =
        realloc(query_parameters, (num_parameters + 1) * sizeof(char *));
    query_parameters[num_parameters] = malloc(strlen(token) + 1);
    strcpy(query_parameters[num_parameters], token);
    num_parameters++;
    token = strsep(&parameters_copy, " ");
  }
  free(parameters_copy);
  free(parameters);

  clock_t start_time, end_time;
  double time_taken;
  int lineNum;

  switch (query_type) {
    case 1:
      start_time = clock();
      query1(has_f, query_parameters, flights_data, reservations_data,
             users_data, output_file);

      end_time = clock();
      time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

      lineNum = compare_files(output_file, output_file_expected);
      write_input(has_f, query_type, lineNum, time_taken);

      break;
    case 2:
      start_time = clock();

      query2(has_f, query_parameters, flights_data, reservations_data,
             users_data, output_file, num_parameters);
      end_time = clock();
      time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

      lineNum = compare_files(output_file, output_file_expected);
      write_input(has_f, query_type, lineNum, time_taken);
      break;
    case 3:
      start_time = clock();

      query3(has_f, query_parameters, reservations_data, output_file);
      end_time = clock();
      time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

      lineNum = compare_files(output_file, output_file_expected);
      write_input(has_f, query_type, lineNum, time_taken);
      break;

    case 4:
      start_time = clock();

      query4(has_f, query_parameters, reservations_data, output_file);
      end_time = clock();
      time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

      lineNum = compare_files(output_file, output_file_expected);
      write_input(has_f, query_type, lineNum, time_taken);
      break;
    case 5:
      start_time = clock();

      query5(has_f, query_parameters, flights_data, output_file);
      end_time = clock();
      time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

      lineNum = compare_files(output_file, output_file_expected);
      write_input(has_f, query_type, lineNum, time_taken);
      break;
    case 6:
      start_time = clock();

      query6(has_f, query_parameters, flights_data, output_file);

      end_time = clock();
      time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

      lineNum = compare_files(output_file, output_file_expected);
      write_input(has_f, query_type, lineNum, time_taken);

      break;
    case 7:
      start_time = clock();

      query7(has_f, query_parameters, flights_data, output_file);

      end_time = clock();
      time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

      lineNum = compare_files(output_file, output_file_expected);
      write_input(has_f, query_type, lineNum, time_taken);

      break;
    case 8:
      start_time = clock();

      query8(has_f, query_parameters, reservations_data, output_file);

      end_time = clock();
      time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

      lineNum = compare_files(output_file, output_file_expected);
      write_input(has_f, query_type, lineNum, time_taken);
      break;
    case 9:
      start_time = clock();

      query9(has_f, query_parameters, users_data, users_stats, output_file,
             num_parameters);
      end_time = clock();
      time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

      lineNum = compare_files(output_file, output_file_expected);
      write_input(has_f, query_type, lineNum, time_taken);
      break;
    case 10:
      start_time = clock();

      query10(has_f, query_parameters, num_parameters, general_data,
              output_file);

      end_time = clock();
      time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

      lineNum = compare_files(output_file, output_file_expected);
      write_input(has_f, query_type, lineNum, time_taken);

      break;
    default:
      // This is not suppose\d to happen
      printf("Error choosing the query\n");
      break;
  }

  for (int i = 0; i < num_parameters; ++i) {
    free(query_parameters[i]);
  }
  free(query_parameters);
}
