#include "base/query_manager.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *query_manager(char *line, FLIGHTS_CATALOG flights_catalog,
                    PASSENGERS_CATALOG passengers_catalog,
                    RESERVATIONS_CATALOG reservations_catalog,
                    USERS_CATALOG users_catalog) {
  char **query_parameters = malloc(sizeof(char *) * MAX_LINE_SIZE);
  char *token = strtok(line, " ");
  char query_type = line[0];
  token = strtok(NULL, " ");
  for (int i = 0; token != NULL; i++) {
    query_parameters[i] = token;
    token = strtok(NULL, " ");
  }
  static query_function_pointer table[] = {query1};
  void *result = table[query_type - '1'](query_parameters, flights_catalog,
                                         passengers_catalog,
                                         reservations_catalog, users_catalog);

  free(query_parameters);

  return result;
}

void *query1(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog) {
  return NULL;
}