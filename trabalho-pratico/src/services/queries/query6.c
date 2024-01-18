#include "services/queries/query6.h"

struct query6_result {
  char *airport;
  int median_delay;
};

void write_query6(bool has_f, FILE *output_file, char **airport_info,
                  int *number_of_passengers, int N) {
  if (has_f) {
    for (int i = 0; i < N; i++) {
      if (i != 0) fprintf(output_file, "\n");
      fprintf(output_file, "--- %d ---\nname: %s\npassengers: %d\n", i + 1,
              airport_info[i], number_of_passengers[i]);
    }

  } else {
    for (int i = 0; i < N; i++) {
      fprintf(output_file, "%s;%d\n", airport_info[i], number_of_passengers[i]);
    }
  }
}

gint compare_passengers(gconstpointer a, gconstpointer b) {
  const struct query6_result *result_a = (const struct query6_result *)a;
  const struct query6_result *result_b = (const struct query6_result *)b;

  if (result_a->median_delay > result_b->median_delay) {
    return -1;
  } else if (result_a->median_delay < result_b->median_delay) {
    return 1;
  }

  return g_strcmp0(result_a->airport, result_b->airport);
}

void query6(bool has_f, char **query_parameters, FlightsData *flights_data,
            FILE *output_file) {
  if (query_parameters[0] == NULL || query_parameters[1] == NULL) return;

  int year = strtol(query_parameters[0], NULL, 10);
  int length = strtol(query_parameters[1], NULL, 10);

  GArray *output = g_array_new(FALSE, FALSE, sizeof(struct query6_result));

  GHashTable *airport = get_airports_list(flights_data, year * 10000);

  if (airport == NULL) return;

  g_hash_table_foreach(airport, (GHFunc)get_airport_info_list, output);

  g_array_sort(output, (GCompareFunc)compare_passengers);

  if (length > (int)output->len) length = output->len;

  char **airport_output = malloc(sizeof(char *) * length);
  int *number_of_passengers = malloc(sizeof(int) * length);

  for (int i = 0; i < length && i < (int)output->len; i++) {
    struct query6_result *result =
        &g_array_index(output, struct query6_result, i);

    airport_output[i] = result->airport;
    number_of_passengers[i] = result->median_delay;
  }

  write_query6(has_f, output_file, airport_output, number_of_passengers,
               length);

  g_array_free(output, TRUE);
  free(airport_output);
  free(number_of_passengers);
}
