#define _DEFAULT_SOURCE
#include "services/queries_service.h"

#include <ctype.h>
#include <glib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// In this file it is supposed pass to the query functions ONLY THE NEEDED data
// structs, not all of them

void query1(bool has_f, char **query_parameters, FlightsData *flights_data,
            PassengersData *passengers_data,
            ReservationsData *reservations_data, UsersData *users_data,
            FILE *output_file) {
  char *id = query_parameters[0];

  if (strncmp(id, "Book", 4) == 0) {
    ReservationInfo *reservation_info =
        get_reservation_by_reservation_id(reservations_data, id);

    if (reservation_info == NULL) return;

    int price_per_night = get_price_per_night(reservation_info);
    int city_tax = get_city_tax(reservation_info);

    char *hotel_id = get_hotel_id(reservation_info);
    char *hotel_name = get_hotel_name(reservation_info);
    int hotel_stars = get_hotel_stars(reservation_info);
    char *begin_date = get_begin_date(reservation_info);
    char *end_date = get_end_date(reservation_info);
    char *breakfast = get_includes_breakfast(reservation_info);
    char *includes_breakfast =
        (strcmp(breakfast, "false") == 0) ? "False" : "True";
    int number_of_nights = calculate_number_of_nights(begin_date, end_date);
    double total_price =
        calculate_total_price(number_of_nights, price_per_night, city_tax);

    write_query1_for_reservation(
        has_f, output_file, hotel_id, hotel_name, hotel_stars, begin_date,
        end_date, includes_breakfast, number_of_nights, total_price);
    free(begin_date);
    free(end_date);
    free(hotel_id);
    free(hotel_name);
    free(breakfast);
  }

  if (isdigit(id[0]) && isdigit(id[1])) {
    FlightInfo *flight_info = get_flight_by_flight_id(flights_data, id);

    if (flight_info == NULL) return;

    char *real_departure_date = get_real_departure_date(flight_info);

    char *airline_company = get_airline(flight_info);
    char *plane_model = get_plane_model(flight_info);
    char *origin = get_origin(flight_info);
    char *destination = get_destination(flight_info);
    char *schedule_departure_date = get_schedule_departure_date(flight_info);
    char *schedule_arrival_date = get_schedule_arrival_date(flight_info);
    int passengers = get_number_of_passengers_from_flight_stats(
        get_flight_stats_by_flight_id(flights_data, id));
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

  char *account_status = get_account_status(user_info);

  if (strcmp(account_status, "ACTIVE") == 0) {
    char *name = get_name(user_info);
    char *sex = get_sex(user_info);
    char *birth_date = get_birth_date(user_info);
    char *age = calculate_age(birth_date);
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
    free(sex);
    free(country_code);
    free(passport);
    free(birth_date);
  }
  free(account_status);
}

void query2(bool has_f, char **query_parameters, FlightsData *flights_data,
            PassengersData *passengers_data,
            ReservationsData *reservations_data, UsersData *users_data,
            FILE *output_file, int N) {
  char *id = query_parameters[0];
  char *type = "NULL";
  if (N == 2) {
    type = query_parameters[1];
  }

  UserInfo *user = get_user_by_username(users_data, id);
  char *account_status = get_account_status(user);
  if (account_status == NULL || strlen(account_status) <= 0 ||
      strcmp(account_status, "ACTIVE") != 0) {
    free(account_status);
    return;
  }
  free(account_status);
  UserStats *user_stats = get_user_stats_by_user_id(users_data, id);
  if (strcmp(type, "flights") == 0) {
    GArray *flights = get_user_flights_from_user_stats(user_stats);
    char **flight_ids = malloc(sizeof(char *) * flights->len);
    char **flight_dates = malloc(sizeof(char *) * flights->len);
    char **flight_types = malloc(sizeof(char *) * flights->len);

    int i = 0;
    for (i = 0; i < flights->len; i++) {
      char *id = g_array_index(flights, char *, i);
      FlightInfo *flight = get_flight_by_flight_id(flights_data, id);
      if (flight == NULL) return;
      char *date = get_schedule_departure_date(flight);

      int year, month, day, hour, minute, second;
      sscanf(date, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute,
             &second);
      flight_ids[i] = id;
      flight_dates[i] = format_date(year, month, day);
      flight_types[i] = NULL;
      free(date);
    }
    sort_by_date(flight_ids, flight_dates, flight_types, i);
    write_query2(has_f, output_file, flight_ids, flight_dates, flight_types, i);
    free(flight_ids);
    for (i = 0; i < flights->len; i++) {
      free(flight_dates[i]);
    }
    free(flight_dates);
    free(flight_types);
  } else if (strcmp(type, "reservations") == 0) {
    GArray *reservations = get_user_reservations_from_user_stats(user_stats);
    char **reservation_ids = malloc(sizeof(char *) * reservations->len);
    char **reservation_dates = malloc(sizeof(char *) * reservations->len);
    char **reservation_types = malloc(sizeof(char *) * reservations->len);
    int i = 0;
    for (i = 0; i < reservations->len; i++) {
      char *id = g_array_index(reservations, char *, i);
      ReservationInfo *reservation =
          get_reservation_by_reservation_id(reservations_data, id);
      if (reservation == NULL) return;
      char *date = get_begin_date(reservation);

      int year, month, day, hour, minute, second;
      sscanf(date, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute,
             &second);
      reservation_ids[i] = id;
      reservation_dates[i] = format_date(year, month, day);
      reservation_types[i] = NULL;
      free(date);
    }
    sort_by_date(reservation_ids, reservation_dates, reservation_types, i);
    write_query2(has_f, output_file, reservation_ids, reservation_dates,
                 reservation_types, i);
    free(reservation_ids);
    for (i = 0; i < reservations->len; i++) {
      free(reservation_dates[i]);
    }
    free(reservation_dates);
    free(reservation_types);
  } else {
    GArray *flights = get_user_flights_from_user_stats(user_stats);
    GArray *reservations = get_user_reservations_from_user_stats(user_stats);
    if (flights == NULL && reservations == NULL) {
      return;
    } else if (flights == NULL) {
      char **reservation_ids = malloc(sizeof(char *) * reservations->len);
      char **reservation_dates = malloc(sizeof(char *) * reservations->len);
      char **reservation_types = malloc(sizeof(char *) * reservations->len);
      int i = 0;
      for (i; i < reservations->len; i++) {
        char *id = g_array_index(reservations, char *, i);
        ReservationInfo *reservation =
            get_reservation_by_reservation_id(reservations_data, id);
        if (reservation == NULL) return;
        char *date = get_begin_date(reservation);
        int year, month, day, hour, minute, second;
        sscanf(date, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute,
               &second);
        reservation_ids[i] = id;
        reservation_dates[i] = format_date(year, month, day);
        reservation_types[i] = NULL;
      }

      sort_by_date(reservation_ids, reservation_dates, reservation_types, i);
      write_query2(has_f, output_file, reservation_ids, reservation_dates,
                   reservation_types, i);
      free(reservation_ids);
      for (i = 0; i < reservations->len; i++) {
        free(reservation_dates[i]);
      }
      free(reservation_dates);
      free(reservation_types);
    } else if (reservations == NULL) {
      char **flight_ids = malloc(sizeof(char *) * flights->len);
      char **flight_dates = malloc(sizeof(char *) * flights->len);
      char **flight_types = malloc(sizeof(char *) * flights->len);
      int i = 0;
      for (i; i < flights->len; i++) {
        char *id = g_array_index(flights, char *, i);
        FlightInfo *flight = get_flight_by_flight_id(flights_data, id);
        if (flight == NULL) return;
        char *date = get_schedule_departure_date(flight);
        int year, month, day, hour, minute, second;
        sscanf(date, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute,
               &second);

        flight_ids[i] = id;
        flight_dates[i] = format_date(year, month, day);
        flight_types[i] = "flight";
        free(date);
      }

      sort_by_date(flight_ids, flight_dates, flight_types, i);
      write_query2(has_f, output_file, flight_ids, flight_dates, flight_types,
                   i);
    } else {
      int max = flights->len + reservations->len;
      char **all_ids = malloc(sizeof(char *) * max);
      char **all_dates = malloc(sizeof(char *) * max);
      char **all_types = malloc(sizeof(char *) * max);

      int i = 0;

      while (i < flights->len) {
        char *id = g_array_index(flights, char *, i);
        FlightInfo *flight = get_flight_by_flight_id(flights_data, id);
        if (flight == NULL) return;
        char *date = get_schedule_departure_date(flight);
        int year, month, day, hour, minute, second;
        sscanf(date, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute,
               &second);

        all_ids[i] = id;
        all_dates[i] = format_date(year, month, day);
        all_types[i] = "flight";
        i++;
        free(date);
      }
      for (int k = 0; k < flights->len; k++) {
        free(all_dates[k]);
      }

      int j = i;
      i = 0;
      while (j < max) {
        char *id = g_array_index(reservations, char *, i);
        ReservationInfo *reservation =
            get_reservation_by_reservation_id(reservations_data, id);
        if (reservation == NULL) return;
        char *date = get_begin_date(reservation);

        int year, month, day, hour, minute, second;
        sscanf(date, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute,
               &second);

        all_ids[j] = id;
        all_dates[j] = format_date(year, month, day);
        all_types[j] = "reservation";
        j++;
        i++;
        free(date);
      }
      sort_by_date(all_ids, all_dates, all_types, max);
      write_query2(has_f, output_file, all_ids, all_dates, all_types, max);
      free(all_ids);
      for (i = 0; i < max; i++) {
        free(all_dates[i]);
      }
      free(all_dates);
      free(all_types);
    }
  }
}
void query3(bool has_f, char **query_parameters, FlightsData *flights_data,
            PassengersData *passengers_data,
            ReservationsData *reservations_data, UsersData *users_data,
            FILE *output_file) {
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

struct query4_result {
  char **reservation_id;
  char **begin_date;
  char **end_date;
  char **user_id;
  int *rating;
  float *total_price;
  int iterator;
};

void query4(bool has_f, char **query_parameters, FlightsData *flights_data,
            PassengersData *passengers_data,
            ReservationsData *reservations_data, UsersData *users_data,
            FILE *output_file) {
  char *id = query_parameters[0];
  HotelStats *hotel_stats = get_hotel_stats_by_hotel_id(reservations_data, id);
  GArray *reservations = get_hotel_reservations(hotel_stats);
  if (reservations == NULL) return;
  QUERY4_RESULT result = malloc(sizeof(struct query4_result));
  result->reservation_id = malloc(sizeof(char *) * reservations->len);
  result->begin_date = malloc(sizeof(char *) * reservations->len);
  result->end_date = malloc(sizeof(char *) * reservations->len);
  result->user_id = malloc(sizeof(char *) * reservations->len);
  result->rating = malloc(sizeof(int) * reservations->len);
  result->total_price = malloc(sizeof(int) * reservations->len);
  int i = 0;
  int j = 0;
  char *begin_date, *end_date, *user_id;
  for (i = 0; i < reservations->len; i++) {
    char *reservation_id = g_array_index(reservations, char *, i);
    if (strncmp(reservation_id, "Book", 4) == 0) {
      ReservationInfo *reservation =
          get_reservation_by_reservation_id(reservations_data, reservation_id);
      begin_date = get_begin_date(reservation);
      end_date = get_end_date(reservation);
      user_id = get_user_id_reservation(reservation);
      int rating = get_rating(reservation);
      int price_per_night = get_price_per_night(reservation);
      float total_price = calculate_total_price(
          calculate_number_of_nights(begin_date, end_date), price_per_night,
          get_city_tax(reservation));
      result->reservation_id[j] = reservation_id;
      result->begin_date[j] = strdup(begin_date);
      result->end_date[j] = strdup(end_date);
      result->user_id[j] = strdup(user_id);
      result->rating[j] = rating;
      result->total_price[j] = total_price;
      j++;
      free(begin_date);
      free(end_date);
      free(user_id);
    }
  }
  result->iterator = j--;
  sort_by_date_and_value(result, result->iterator);
  write_query4(has_f, output_file, result);
  for (int i = 0; i < result->iterator; i++) {
    free(result->begin_date[i]);
    free(result->end_date[i]);
    free(result->user_id[i]);
  }
  free(result->reservation_id);
  free(result->begin_date);
  free(result->end_date);
  free(result->user_id);
  free(result->rating);
  free(result->total_price);
  free(result);
}

void query5(bool has_f, char **query_parameters, FlightsData *flights_data,
            PassengersData *passengers_data,
            ReservationsData *reservations_data, UsersData *users_data,
            FILE *output_file) {}

void query6(bool has_f, char **query_parameters, FlightsData *flights_data,
            PassengersData *passengers_data,
            ReservationsData *reservations_data, UsersData *users_data,
            FILE *output_file) {}

void query7(bool has_f, char **query_parameters, FlightsData *flights_data,
            PassengersData *passengers_data,
            ReservationsData *reservations_data, UsersData *users_data,
            FILE *output_file) {}

void query8(bool has_f, char **query_parameters, FlightsData *flights_data,
            PassengersData *passengers_data,
            ReservationsData *reservations_data, UsersData *users_data,
            FILE *output_file) {
  char *id = query_parameters[0];
  char *begin_date = query_parameters[1];
  char *end_date = query_parameters[2];
  HotelStats *hotel_stats = get_hotel_stats_by_hotel_id(reservations_data, id);
  GArray *reservations = get_hotel_reservations(hotel_stats);
  if (reservations == NULL) return;

  double revenue = 0, total_price;
  for (int i = 0; i < reservations->len; i++) {
    char *reservation_id = g_array_index(reservations, char *, i);
    ReservationInfo *reservation =
        get_reservation_by_reservation_id(reservations_data, reservation_id);
    if (strncmp(reservation_id, "Book", 4) != 0) break;
    char *begin_date_reservation = get_begin_date(reservation);
    char *end_date_reservation = get_end_date(reservation);
    int price_per_night = get_price_per_night(reservation);
    if (strcmp(begin_date, end_date) == 0 &&
        (strcmp(begin_date, begin_date_reservation) == 0 ||
         strcmp(end_date, end_date_reservation) == 0)) {
      revenue += 1 * price_per_night;
    } else if (calculate_number_of_nights(begin_date, end_date) == 1 &&
               (strcmp(begin_date, begin_date_reservation) == 0 ||
                strcmp(begin_date, end_date_reservation) == 0 ||
                strcmp(end_date, end_date_reservation) == 0 ||
                strcmp(end_date, begin_date_reservation) == 0)) {
      if (strcmp(begin_date_reservation, end_date_reservation) == 0)
        revenue += 1 * price_per_night;
      else
        revenue += 2 * price_per_night;
    } else if (strcmp(begin_date, begin_date_reservation) <= 0 &&
               strcmp(end_date, end_date_reservation) >= 0) {
      revenue += calculate_number_of_nights(begin_date_reservation,
                                            end_date_reservation) *
                 price_per_night;
    }
    free(begin_date_reservation);
    free(end_date_reservation);
  }
  write_query8(has_f, output_file, revenue);
}

struct user_info {
  char *user_id;
  char *user_name;
};

void query9(bool has_f, char **query_parameters, FlightsData *flights_data,
            PassengersData *passengers_data,
            ReservationsData *reservations_data, UsersData *users_data,
            StatsUserInfo *users_stats, FILE *output_file, int num_parameters) {
  if (query_parameters[0] == NULL) return;
  char *prefix = create_prefix(query_parameters, num_parameters);

  if (prefix == NULL) return;
  GArray *stats_user = get_stats_user_info(users_stats);
  char **user_ids = malloc(sizeof(char *) * stats_user->len);
  char **user_names = malloc(sizeof(char *) * stats_user->len);

  int j, i;
  for (i = 0, j = 0; i < stats_user->len; i++) {
    UserInfoStats *user =
        (UserInfoStats *)(g_array_index(stats_user, void *, i));
    char *account_status =
        get_account_status(get_user_by_username(users_data, user->user_id));
    if (strncmp(user->user_name, prefix, strlen(prefix)) == 0 &&
        strcmp(account_status, "ACTIVE") == 0) {
      user_ids[j] = (user->user_id);
      user_names[j] = (user->user_name);
      j++;
    }
    free(account_status);
  }
  sort_by_name_and_id(user_ids, user_names, j);
  write_query9(has_f, output_file, user_ids, user_names, j);
  free(user_names);
  free(user_ids);
}

void query10(bool has_f, char **query_parameters, int num_parameters,
             FlightsData *flights_data, PassengersData *passengers_data,
             ReservationsData *reservations_data, UsersData *users_data,
             FILE *output_file) {}

void query_manager(char *line, FlightsData *flights_data,
                   PassengersData *passengers_data,
                   ReservationsData *reservations_data, UsersData *users_data,
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
      query1(has_f, query_parameters, flights_data, passengers_data,
             reservations_data, users_data, output_file);
      break;
    case 2:
      query2(has_f, query_parameters, flights_data, passengers_data,
             reservations_data, users_data, output_file, num_parameters);
      break;
    case 3:
      query3(has_f, query_parameters, flights_data, passengers_data,
             reservations_data, users_data, output_file);
      break;
    case 4:
      query4(has_f, query_parameters, flights_data, passengers_data,
             reservations_data, users_data, output_file);
      break;
    case 5:
      query5(has_f, query_parameters, flights_data, passengers_data,
             reservations_data, users_data, output_file);
      break;
    case 6:
      query6(has_f, query_parameters, flights_data, passengers_data,
             reservations_data, users_data, output_file);
      break;
    case 7:
      query7(has_f, query_parameters, flights_data, passengers_data,
             reservations_data, users_data, output_file);
      break;
    case 8:
      query8(has_f, query_parameters, flights_data, passengers_data,
             reservations_data, users_data, output_file);
      break;
    case 9:
      query9(has_f, query_parameters, flights_data, passengers_data,
             reservations_data, users_data, users_stats, output_file,
             num_parameters);
      break;
    case 10:
      query10(has_f, query_parameters, num_parameters, flights_data,
              passengers_data, reservations_data, users_data, output_file);
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
