#define _GNU_SOURCE
#include "base/batch.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int batch(char **argv) {
  FLIGHTS_CATALOG flights_catalog = create_flights_catalog();
  PASSENGERS_CATALOG passengers_catalog = create_passengers_catalog();
  RESERVATIONS_CATALOG reservations_catalog = create_reservations_catalog();
  USERS_CATALOG users_catalog = create_users_catalog();

  STATS stats = create_stats();

  // Create results directory
  if (create_directory("Resultados") != 0) {
    return ERR_CREATING_DIRECTORY;
  }

  if (setup_catalogs_and_stats(argv[1], flights_catalog, passengers_catalog,
                               reservations_catalog, users_catalog,
                               stats) == -1) {
    return -1;
  }

  // Open queries file
  char *queries_filename = argv[2];
  FILE *queries_file = fopen(queries_filename, "r");
  if (queries_file == NULL) {
    return -1;
  }

  char *line = NULL;
  size_t len = 0;
  int number_of_queries = 1;

  while (getline(&line, &len, queries_file) != -1) {
    // Remove '\n' from line
    line[strlen(line) - 1] = '\0';

    void *result = query_manager(line, flights_catalog, passengers_catalog,
                                 reservations_catalog, users_catalog, stats);

    FILE *output_file = create_output_file(number_of_queries);
    if (output_file == NULL) {
      return ERR_OPENING_OUTPUT_FILE;
    }

    write_query_result(output_file, result, line[0]);
    free_query_result(result, line[0]);

    fclose(output_file);
    number_of_queries++;
  }

  free(line);
  fclose(queries_file);

  free_flights_catalog(flights_catalog);
  free_passengers_catalog(passengers_catalog);
  free_reservations_catalog(reservations_catalog);
  free_users_catalog(users_catalog);
  free_stats(stats);

  return 0;
}
