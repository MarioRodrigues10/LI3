#include "services/queries/query2.h"

#include <glib.h>
#include <locale.h>
#include <stdbool.h>

struct query2_result_helper {
  char *id;
  char *date;
  char *type;
};

struct query2_result {
  GArray *query2_result;
};

int compare_query2_result(const void *a, const void *b) {
  setlocale(LC_COLLATE, "en_US.UTF-8");
  const QUERY2_RESULT_HELPER *query2_result_a = (const QUERY2_RESULT_HELPER *)a;
  const QUERY2_RESULT_HELPER *query2_result_b = (const QUERY2_RESULT_HELPER *)b;

  int dateComparison =
      strcoll((*query2_result_b)->date, (*query2_result_a)->date);

  if (dateComparison != 0) {
    return dateComparison;
  } else {
    return strcoll((*query2_result_a)->id, (*query2_result_b)->id);
  }
}

void sort_by_date(void *result, int N) {
  QUERY2_RESULT *query_result = (QUERY2_RESULT *)result;

  qsort((*query_result)->query2_result, N, sizeof(QUERY2_RESULT),
        compare_query2_result);
}

void write_query2(bool has_f, FILE *output_file, GArray *query_result_array) {
  int j;
  for (guint i = 0; i < query_result_array->len; i++) {
    QUERY2_RESULT_HELPER query_result =
        g_array_index(query_result_array, QUERY2_RESULT_HELPER, i);

    char *date = query_result->date;

    int year, month, day, hour, minute, second;
    sscanf(date, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute,
           &second);

    char *new_date = format_date(year, month, day);

    j = i + 1;
    if (strcmp(query_result->type, "nada") == 0) {
      if (has_f) {
        if (i != 0) fprintf(output_file, "\n");
        fprintf(output_file, "--- %d ---\nid: %s\ndate: %s\n", j,
                query_result->id, new_date);
      } else {
        fprintf(output_file, "%s;%s\n", query_result->id, new_date);
      }
    } else {
      if (has_f) {
        if (i != 0) fprintf(output_file, "\n");
        fprintf(output_file, "--- %d ---\nid: %s\ndate: %s\ntype: %s\n", j,
                query_result->id, new_date, query_result->type);
      } else {
        fprintf(output_file, "%s;%s;%s\n", query_result->id, new_date,
                query_result->type);
      }
    }
    free(new_date);
  }
}

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

    result_helper->id = g_strdup(flight_id_str);
    result_helper->date = g_strdup(date);
    result_helper->type = g_strdup(type);

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

    result_helper->id = g_strdup(reservation_id);
    result_helper->date = g_strdup(new_date);
    result_helper->type = g_strdup(type);

    g_array_append_val(output_array, result_helper);
    free(reservation_id);
    free(new_date);
    free(date);
  }
}
