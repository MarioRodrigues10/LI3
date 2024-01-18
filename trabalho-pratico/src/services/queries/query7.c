#include "services/queries/query7.h"

struct query7_result {
  char *airport;
  int median_delay;
};

void write_query7(bool has_f, FILE *output_file, char **airport, int *delays,
                  int N) {
  if (has_f) {
    for (int i = 0; i < N; i++) {
      if (i != 0) fprintf(output_file, "\n");
      fprintf(output_file, "--- %d ---\nname: %s\nmedian: %d\n", i + 1,
              airport[i], delays[i]);
    }

  } else {
    for (int i = 0; i < N; i++) {
      fprintf(output_file, "%s;%d\n", airport[i], delays[i]);
    }
  }
}

void swap(GArray *array, int i, int j) {
  int temp = g_array_index(array, int, i);
  g_array_index(array, int, i) = g_array_index(array, int, j);
  g_array_index(array, int, j) = temp;
}

int partition(GArray *array, int left, int right) {
  int pivotValue = g_array_index(array, int, right);
  int i = left;
  for (int j = left; j < right; j++) {
    if (g_array_index(array, int, j) < pivotValue) {
      swap(array, i, j);
      i++;
    }
  }
  swap(array, i, right);
  return i;
}

int quickselect(GArray *array, int k) {
  int left = 0, right = array->len - 1;
  while (left <= right) {
    int pivotIndex = partition(array, left, right);
    if (pivotIndex == k) {
      return g_array_index(array, int, pivotIndex);
    } else if (pivotIndex < k) {
      left = pivotIndex + 1;
    } else {
      right = pivotIndex - 1;
    }
  }
  return -1;
}

double calculate_median(GArray *delays) {
  int n = delays->len;
  if (n % 2 == 0) {
    int mid1 = quickselect(delays, n / 2 - 1);
    int mid2 = quickselect(delays, n / 2);
    return (double)((mid1 + mid2) / 2);
  } else {
    return quickselect(delays, n / 2);
  }
}

void calculate_median_for_airport(gpointer key, gpointer value,
                                  gpointer user_data) {
  AirportStats *airport = (AirportStats *)value;

  GArray *delays = get_delays(airport);
  int median = calculate_median(delays);

  struct query7_result result_entry;
  result_entry.airport = (char *)key;
  result_entry.median_delay = median;

  g_array_append_val((GArray *)user_data, result_entry);
}

gint compare_median(gconstpointer a, gconstpointer b) {
  const struct query7_result *result_a = (const struct query7_result *)a;
  const struct query7_result *result_b = (const struct query7_result *)b;

  if (result_a->median_delay > result_b->median_delay) {
    return -1;
  } else if (result_a->median_delay < result_b->median_delay) {
    return 1;
  }

  return g_strcmp0(result_a->airport, result_b->airport);
}

void query7(bool has_f, char **query_parameters, FlightsData *flights_data,
            FILE *output_file) {
  guint length = strtol(query_parameters[0], NULL, 10);
  GArray *medians = g_array_new(FALSE, FALSE, sizeof(struct query7_result));

  GHashTable *airport = get_airport_stats(flights_data);

  if (airport == NULL) {
    g_array_free(medians, TRUE);
    return;
  }

  g_hash_table_foreach(airport, (GHFunc)calculate_median_for_airport, medians);

  g_array_sort(medians, (GCompareFunc)compare_median);

  if (length > medians->len) length = medians->len;

  char **airport_result = malloc(sizeof(char *) * length);
  int *medians_result = malloc(sizeof(int) * length);

  for (guint i = 0; i < length && i < medians->len; i++) {
    struct query7_result *result =
        &g_array_index(medians, struct query7_result, i);

    airport_result[i] = g_strdup(result->airport);
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
