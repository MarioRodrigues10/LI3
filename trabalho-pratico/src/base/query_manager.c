#define _GNU_SOURCE
#include "base/query_manager.h"

#include <ctype.h>
#include <glib.h>
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
    query_parameters[i] = strdup("F");
    i++;
  }

  token = strtok(NULL, " ");
  while (token != NULL) {
    query_parameters[i] = strdup(token);
    token = strtok(NULL, " ");
    i++;
  }
  query_parameters[i] = NULL;
  static query_function_pointer table[] = {query1, query2, query3, query4,
                                           query5, query6, query7, query8,
                                           query9, query10};
  void *result =
      table[query_type](query_parameters, flights_catalog, passengers_catalog,
                        reservations_catalog, users_catalog, stats);

  for (int j = 0; j < i; j++) {
    free(query_parameters[j]);
  }
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
  if (strncmp(id, "Book", 4) == 0) {
    RESERVATION reservation = get_reservation_by_id(reservations_catalog, id);

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

struct query2_result {
  char **id;
  char **date;
  char **type;
  int iterator;
  bool has_f;
};

void *query2(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog, STATS stats) {
  bool has_f = false;

  char *id = NULL;
  char *type = "NULO";

  if (strcmp(query_params[0], "F") == 0) {
    has_f = true;
    id = query_params[1];

    if (query_params[2] != NULL) {
      if ((strcmp(query_params[2], "reservations") == 0) ||
          (strcmp(query_params[2], "flights") == 0)) {
        type = query_params[2];
      }
    }
  } else {
    has_f = false;
    id = query_params[0];
    if (query_params[1] != NULL &&
        ((strcmp(query_params[1], "reservations") == 0) ||
         (strcmp(query_params[1], "flights") == 0))) {
      type = query_params[1];
    }
  }

  QUERY2_RESULT result = malloc(sizeof(struct query2_result));
  if (strcmp(type, "flights") == 0) {
    GArray *flights = get_user_flights(stats, id);
    USER user = get_user_by_username(users_catalog, id);
    char *account_status = get_user_account_status(user);
    if (account_status != NULL && strcmp(account_status, "ACTIVE") == 0) {
      result->id = malloc(sizeof(char *) * flights->len);
      result->date = malloc(sizeof(char *) * flights->len);
      result->type = malloc(sizeof(char *) * flights->len);

      int i = 0;
      for (i = 0; i < flights->len; i++) {
        char *id = g_array_index(flights, char *, i);
        char *date = get_flight_schedule_departure_date(
            get_flight_by_id(flights_catalog, id));

        int year, month, day, hour, minute, second;
        sscanf(date, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute,
               &second);

        result->id[i] = id;
        result->date[i] = format_date(year, month, day);
        ;
        result->type[i] = NULL;
      }
      result->iterator = i;
      result->has_f = has_f;

      sort_by_date(result, result->iterator);
    }
    return (void *)result;

  } else if (strcmp(type, "reservations") == 0) {
    GArray *reservations = get_user_reservations(stats, id);
    USER user = get_user_by_username(users_catalog, id);
    char *account_status = get_user_account_status(user);
    if (account_status != NULL && strcmp(account_status, "ACTIVE") == 0) {
      result->id = malloc(sizeof(char *) * reservations->len);
      result->date = malloc(sizeof(char *) * reservations->len);
      result->type = malloc(sizeof(char *) * reservations->len);

      int i = 0;
      for (i = 0; i < reservations->len; i++) {
        char *id = g_array_index(reservations, char *, i);
        RESERVATION reservation =
            get_reservation_by_id(reservations_catalog, id);

        char *date = get_reservation_begin_date(reservation);
        int year, month, day, hour, minute, second;
        sscanf(date, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute,
               &second);

        result->id[i] = id;
        result->date[i] = format_date(year, month, day);
        ;
        result->type[i] = NULL;
      }
      result->iterator = i;
      result->has_f = has_f;

      sort_by_date(result, result->iterator);
    }
    return (void *)result;
  } else {
    GArray *flights = get_user_flights(stats, id);
    GArray *reservations = get_user_reservations(stats, id);
    USER user = get_user_by_username(users_catalog, id);
    char *account_status = get_user_account_status(user);
    if (account_status != NULL && strcmp(account_status, "ACTIVE") == 0) {
      if (flights == NULL && reservations == NULL)
        return NULL;
      else if (flights == NULL) {
        result->id = malloc(sizeof(char *) * reservations->len);
        result->date = malloc(sizeof(char *) * reservations->len);
        result->type = malloc(sizeof(char *) * reservations->len);
        int i = 0;
        for (i; i < reservations->len; i++) {
          char *id = g_array_index(reservations, char *, i);
          RESERVATION reservation =
              get_reservation_by_id(reservations_catalog, id);
          char *date = get_reservation_begin_date(reservation);
          int year, month, day, hour, minute, second;
          sscanf(date, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute,
                 &second);

          result->id[i] = id;
          result->date[i] = format_date(year, month, day);
          ;
          result->type[i] = NULL;
        }
        result->iterator = i;
        result->has_f = has_f;

        sort_by_date(result, result->iterator);
        return (void *)result;
      } else if (reservations == NULL) {
        result->id = malloc(sizeof(char *) * flights->len);
        result->date = malloc(sizeof(char *) * flights->len);
        result->type = malloc(sizeof(char *) * flights->len);
        int i = 0;
        for (i; i < flights->len; i++) {
          char *id = g_array_index(flights, char *, i);
          FLIGHT flight = get_flight_by_id(flights_catalog, id);
          char *date = get_flight_schedule_departure_date(flight);
          int year, month, day, hour, minute, second;
          sscanf(date, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute,
                 &second);

          result->id[i] = id;
          result->date[i] = format_date(year, month, day);
          ;
          result->type[i] = "flight";
        }
        result->iterator = i;
        result->has_f = has_f;

        sort_by_date(result, result->iterator);
        return (void *)result;
      } else {
        int max = flights->len + reservations->len;

        result->id = malloc(sizeof(char *) * max);
        result->date = malloc(sizeof(char *) * max);
        result->type = malloc(sizeof(char *) * max);

        int i = 0;

        while (i < flights->len) {
          char *id = g_array_index(flights, char *, i);
          FLIGHT flight = get_flight_by_id(flights_catalog, id);
          char *date = get_flight_schedule_departure_date(flight);
          int year, month, day, hour, minute, second;
          sscanf(date, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute,
                 &second);

          result->id[i] = id;
          result->date[i] = format_date(year, month, day);
          result->type[i] = "flight";
          i++;
        }
        int j = i;
        i = 0;
        while (j < max) {
          char *id = g_array_index(reservations, char *, i);
          RESERVATION reservation =
              get_reservation_by_id(reservations_catalog, id);
          char *date = get_reservation_begin_date(reservation);

          int year, month, day, hour, minute, second;
          sscanf(date, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute,
                 &second);

          result->id[j] = id;
          result->date[j] = format_date(year, month, day);
          result->type[j] = "reservation";
          i++;
          j++;
        }
        result->iterator = max;
        result->has_f = has_f;

        sort_by_date(result, result->iterator);
        return (void *)result;
      }
    }
  }
  return NULL;
}

struct query3_result {
  double media_of_ratings;
  bool has_f;
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
  bool has_f = false;

  char *id = NULL;

  if (strcmp(query_params[0], "F") == 0) {
    has_f = true;
    id = query_params[1];
  } else {
    has_f = false;
    id = query_params[0];
  }

  HOTEL_STATS hotel_stats = get_hotel_stats_by_hotel_id(stats, id);

  if (hotel_stats == NULL) {
    return NULL;
  }

  QUERY3_RESULT result = malloc(sizeof(struct query3_result));
  result->media_of_ratings = media_of_ratings(stats, id);
  result->has_f = has_f;

  return (void *)result;
}

struct query4_result {
  char **reservation_id;
  char **begin_date;
  char **end_date;
  char **user_id;
  int *rating;
  float *total_price;
  int iterator;
  bool has_f;
};

void *query4(char **query_params, FLIGHTS_CATALOG flights_catalog,
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

  GArray *reservations = get_hotel_reservations(stats, id);
  if (reservations == NULL) return NULL;
  QUERY4_RESULT result = malloc(sizeof(struct query4_result));
  result->reservation_id = malloc(sizeof(char *) * reservations->len);
  result->begin_date = malloc(sizeof(char *) * reservations->len);
  result->end_date = malloc(sizeof(char *) * reservations->len);
  result->user_id = malloc(sizeof(char *) * reservations->len);
  result->rating = malloc(sizeof(int) * reservations->len);
  result->total_price = malloc(sizeof(int) * reservations->len);

  for (int i = 0; i < reservations->len; i++) {
    char *reservation_id = g_array_index(reservations, char *, i);
    RESERVATION reservation =
        get_reservation_by_id(reservations_catalog, reservation_id);
    char *begin_date = get_reservation_begin_date(reservation);
    char *end_date = get_reservation_end_date(reservation);
    char *user_id = get_user_id_from_reservation(reservation);
    int rating = get_reservation_rating(reservation);
    int price_per_night = get_reservation_price_per_night(reservation);
    float total_price = calculate_total_price(
        calculate_number_of_nights(begin_date, end_date), price_per_night,
        get_reservation_city_tax(reservation));
    result->reservation_id[i] = reservation_id;
    result->begin_date[i] = begin_date;
    result->end_date[i] = end_date;
    result->user_id[i] = user_id;
    result->rating[i] = rating;
    result->total_price[i] = total_price;
  }
  result->iterator = reservations->len;
  result->has_f = has_f;

  sort_by_date_and_value(result, result->iterator);
  return (void *)result;
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

struct query8_result {
  double revenue;
  bool has_f;
};

void *query8(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog, STATS stats) {
  bool has_f = false;
  char *id = NULL;
  char *begin_date = NULL;
  char *end_date = NULL;

  if (strcmp(query_params[0], "F") == 0) {
    has_f = true;
    id = query_params[1];
    begin_date = query_params[2];
    end_date = query_params[3];
  } else {
    has_f = false;
    id = query_params[0];
    begin_date = query_params[1];
    end_date = query_params[2];
  }

  GArray *reservations = get_hotel_reservations(stats, id);
  if (reservations == NULL) return NULL;
  QUERY8_RESULT result = malloc(sizeof(struct query8_result));
  double revenue = 0, total_price;
  for (int i = 0; i < reservations->len; i++) {
    char *reservation_id = g_array_index(reservations, char *, i);
    RESERVATION reservation =
        get_reservation_by_id(reservations_catalog, reservation_id);
    char *begin_date_reservation = get_reservation_begin_date(reservation);
    char *end_date_reservation = get_reservation_end_date(reservation);
    int price_per_night = get_reservation_price_per_night(reservation);
    if (strcmp(begin_date, begin_date_reservation) <= 0 &&
        strcmp(end_date, end_date_reservation) >= 0) {
      revenue = revenue + calculate_total_price(
                              calculate_number_of_nights(begin_date_reservation,
                                                         end_date_reservation),
                              price_per_night, 0);
    }
  }
  result->revenue = revenue;
  result->has_f = has_f;
  return (void *)result;
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