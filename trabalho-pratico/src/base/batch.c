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

  char *queries_filename = argv[2];
  FILE *queries_file = fopen(queries_filename, "r");
  if (queries_file == NULL) {
    return -1;
  }

  char *line = NULL;
  size_t len = 0;
  while (getline(&line, &len, queries_file) != -1) {
    line[strlen(line) - 1] = '\0';
    void *result = query_manager(line, flights_catalog, passengers_catalog,
                                 reservations_catalog, users_catalog);
  }

  fclose(queries_file);
  free_flights_catalog(flights_catalog);
  free_passengers_catalog(passengers_catalog);
  free_reservations_catalog(reservations_catalog);
  free_users_catalog(users_catalog);
  return 0;
}
