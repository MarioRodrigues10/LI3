#include "services/queries/query5.h"

#include <glib.h>
#include <locale.h>

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

void write_query5(bool has_f, FILE *output_file, GArray *query_result_array) {
  int j;
  for (guint i = 0; i < query_result_array->len; i++) {
    QUERY5_RESULT_HELPER query_result =
        g_array_index(query_result_array, QUERY5_RESULT_HELPER, i);
    j = i + 1;
    if (has_f) {
      if (i != 0) fprintf(output_file, "\n");
      fprintf(output_file,
              "--- %d ---\nid: %s\nschedule_departure_date: %s\ndestination: "
              "%s\nairline: %s\nplane_model: %s\n",
              j, query_result->flight_id, query_result->departure_date,
              query_result->destination, query_result->airline,
              query_result->plane_model);
    } else {
      fprintf(output_file, "%s;%s;%s;%s;%s\n", query_result->flight_id,
              query_result->departure_date, query_result->destination,
              query_result->airline, query_result->plane_model);
    }
  }
}

int compare_query5_result(const void *a, const void *b) {
  setlocale(LC_COLLATE, "en_US.UTF-8");
  const QUERY5_RESULT_HELPER *query5_result_a = (const QUERY5_RESULT_HELPER *)a;
  const QUERY5_RESULT_HELPER *query5_result_b = (const QUERY5_RESULT_HELPER *)b;
  int dateComparison = strcoll((*query5_result_b)->departure_date,
                               (*query5_result_a)->departure_date);

  if (dateComparison != 0) {
    return dateComparison;
  } else {
    return strcoll((*query5_result_a)->flight_id,
                   (*query5_result_b)->flight_id);
  }
}

void sort_by_departure_date(void *result, int N) {
  QUERY5_RESULT *query_result = (QUERY5_RESULT *)result;

  qsort((*query_result)->query5_result, N, sizeof(QUERY5_RESULT),
        compare_query5_result);
}

void query5(bool has_f, char **query_parameters, FlightsData *flights_data,
            Maping *map, FILE *output_file) {
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
    char *departure_date =
        seconds_to_datetime(get_schedule_departure_date(flight));
    char *destination = get_destination(flight);
    char *airline = char_to_string(map, get_airline(flight));
    char *plane_model = char_to_string(map, get_plane_model(flight));

    char *flight_id_str = int_to_flight_id(flight_id, count_digits(flight_id));
    if (strcmp(departure_date, begin_date) >= 0 &&
        strcmp(departure_date, end_date) <= 0) {
      QUERY5_RESULT_HELPER result_helper =
          malloc(sizeof(struct query5_result_helper));
      result_helper->flight_id = g_strdup(flight_id_str);
      result_helper->departure_date = g_strdup(departure_date);
      result_helper->destination = g_strdup(destination);
      result_helper->airline = g_strdup(airline);
      result_helper->plane_model = g_strdup(plane_model);
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
