#include "base/query_manager.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *query_manager(char *line, FLIGHTS_CATALOG flights_catalog,
                    PASSENGERS_CATALOG passengers_catalog,
                    RESERVATIONS_CATALOG reservations_catalog,
                    USERS_CATALOG users_catalog, STATS stats) {
  char **query_parameters = malloc(sizeof(char *) * MAX_LINE_SIZE);
  char *token = strtok(line, " ");
  int query_type;
  if ((strncmp(line, "10 ", 3) == 0) || (strncmp(line, "10F", 3) == 0)) {
    query_type = 9;
  } else if ((isdigit(line[0]) == 2048) && (line[1] == 0 || line[1] == 'F')) {
    query_type = line[0] - '1';
  } else
    return NULL;

  int i = 0;
  if (line[1] == 'F' || line[2] == 'F') {
    query_parameters[0] = "F";
    i = 1;
  }

  token = strtok(NULL, " ");
  while (token != NULL) {
    query_parameters[i] = token;
    token = strtok(NULL, " ");
    i++;
  }
  static query_function_pointer table[] = {query1, query2, query3, query4,
                                           query5, query6, query7, query8,
                                           query9, query10};
  void *result =
      table[query_type](query_parameters, flights_catalog, passengers_catalog,
                        reservations_catalog, users_catalog, stats);

  free(query_parameters);

  return result;
}

struct query1_result {
  char *hotel_id;
  char *hotel_name;
  int hotel_stars;
  char *begin_date;
  char *end_date;
  char *includes_breakfast;
  int number_of_nights;
  double total_price;

  char *airline_company;
  char *plane_model;
  char *origin;
  char *destination;
  char *schedule_departure_date;
  char *schedule_arrival_date;
  int passengers;
  int delay;

  char *name;
  char *sex;
  char *age;
  char *country_code;
  char *passport;
  int number_of_flights;
  int number_of_reservations;
  double total_spent;

  char *type;

  bool has_f;
};

void *query1(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog, STATS stats) {
  bool has_f = false;

  char *id = NULL;

  if (strcmp(query_params[0], "F") == 0) {
    has_f = true;
    id = query_params[1];
  } else {
    has_f = false;
    id = query_params[0];
  }

  if (id[0] == 'B' && id[1] == 'o' && id[2] == 'o' && id[3] == 'k') {
    RESERVATION reservation =
        get_reservation_by_id(reservations_catalog, id + 4);

    if (reservation == NULL) {
      return NULL;
    }

    QUERY1_RESULT result = malloc(sizeof(struct query1_result));

    int price_per_night = get_reservation_price_per_night(reservation);
    int city_tax = get_reservation_city_tax(reservation);

    result->hotel_id = get_reservation_hotel_id(reservation);
    result->hotel_name = get_reservation_hotel_name(reservation);
    result->hotel_stars = get_reservation_hotel_stars(reservation);
    result->begin_date = get_reservation_begin_date(reservation);
    result->end_date = get_reservation_end_date(reservation);
    result->includes_breakfast =
        (strcmp(get_reservation_includes_breakfast(reservation), "false") == 0)
            ? "False"
            : "True";
    result->number_of_nights =
        calculate_number_of_nights(result->begin_date, result->end_date);
    result->total_price = calculate_total_price(result->number_of_nights,
                                                price_per_night, city_tax);

    result->type = "RESERVATION";

    result->has_f = has_f;

    return (void *)result;
  }

  if (isdigit(id[0]) && isdigit(id[1])) {
    FLIGHT flight = get_flight_by_id(flights_catalog, id);

    if (flight == NULL) {
      return NULL;
    }

    QUERY1_RESULT result = malloc(sizeof(struct query1_result));

    char *real_departure_date = get_flight_real_departure_date(flight);

    result->airline_company = get_flight_airline(flight);
    result->plane_model = get_flight_plane_model(flight);
    result->origin = get_flight_origin(flight);
    result->destination = get_flight_destination(flight);
    result->schedule_departure_date =
        get_flight_schedule_departure_date(flight);
    result->schedule_arrival_date = get_flight_schedule_arrival_date(flight);
    result->passengers = get_total_passengers(stats, id);
    result->delay =
        calculate_delay(result->schedule_departure_date, real_departure_date);

    result->type = "FLIGHT";

    result->has_f = has_f;

    return (void *)result;
  }

  USER user = get_user_by_username(users_catalog, id);

  if (user == NULL) {
    return NULL;
  }

  char *account_status = get_user_account_status(user);

  if (strcmp(account_status, "ACTIVE") == 0) {
    QUERY1_RESULT result = malloc(sizeof(struct query1_result));

    result->name = get_user_name(user);
    result->sex = get_user_sex(user);
    result->age = calculate_age(get_user_birth_date(user));
    result->country_code = get_user_country_code(user);
    result->passport = get_user_passport(user);
    result->number_of_flights = get_number_of_flights(stats, id);
    result->number_of_reservations = get_number_of_reservations(stats, id);
    result->total_spent = get_total_spent(stats, id);

    result->type = "USER";

    result->has_f = has_f;

    return (void *)result;
  }

  return NULL;
}

void *query2(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog, STATS stats) {
  return NULL;
}

struct query3_result {
  double media_of_ratings;
};

struct hotel_stats {
  char *hotel_id;
  int total_rating;
  int total_clients;
};

void *query3(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog, STATS stats) {
  HOTEL_STATS hotel_stats = get_hotel_stats_by_hotel_id(stats, query_params[0]);

  if (hotel_stats == NULL) {
    return NULL;
  }

  QUERY3_RESULT result = malloc(sizeof(struct query3_result));

  result->media_of_ratings = media_of_ratings(stats, query_params[0]);

  return (void *)result;
}

void *query4(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog, STATS stats) {
  return NULL;
}

void *query5(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog, STATS stats) {
  return NULL;
}

void *query6(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog, STATS stats) {
  return NULL;
}

void *query7(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog, STATS stats) {
  return NULL;
}

void *query8(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog, STATS stats) {
  return NULL;
}

void *query9(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog, STATS stats) {
  return NULL;
}

void *query10(char **query_params, FLIGHTS_CATALOG flights_catalog,
              PASSENGERS_CATALOG passengers_catalog,
              RESERVATIONS_CATALOG reservations_catalog,
              USERS_CATALOG users_catalog, STATS stats) {
  return NULL;
}

void free_query_result(void *result, char query_type) {
  static free_query_result_function_pointer table[] = {
      free_query1_result, free_query2_result, free_query3_result,
      free_query4_result, free_query5_result, free_query6_result,
      free_query7_result, free_query8_result, free_query9_result,
      free_query10_result};

  table[query_type - '1'](result);
}

void free_query1_result(void *result) {
  QUERY1_RESULT query1_result = (QUERY1_RESULT)result;
  free(query1_result);
}

void free_query2_result(void *result) { return; }

void free_query3_result(void *result) { return; }

void free_query4_result(void *result) { return; }

void free_query5_result(void *result) { return; }

void free_query6_result(void *result) { return; }

void free_query7_result(void *result) { return; }

void free_query8_result(void *result) { return; }

void free_query9_result(void *result) { return; }

void free_query10_result(void *result) { return; }