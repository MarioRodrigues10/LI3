#include "base/query_manager.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *query_manager(char *line, FLIGHTS_CATALOG flights_catalog,
                    PASSENGERS_CATALOG passengers_catalog,
                    RESERVATIONS_CATALOG reservations_catalog,
                    USERS_CATALOG users_catalog) {
  char **query_parameters = malloc(sizeof(char *) * MAX_LINE_SIZE);
  char *token = strtok(line, " ");
  int query_type;
  if ((strncmp(line, "10 ", 3) == 0) || (strncmp(line, "10F", 3) == 0)) {
    query_type = 9;
  } else if ((isdigit(line[0]) == 2048) && (line[1] == ' ' || line[1] == 'F')) {
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

void *query2(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog) {
  return NULL;
}

void *query3(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog) {
  return NULL;
}

void *query4(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog) {
  return NULL;
}

void *query5(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog) {
  return NULL;
}

void *query6(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog) {
  return NULL;
}

void *query7(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog) {
  return NULL;
}

void *query8(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog) {
  return NULL;
}

void *query9(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog) {
  return NULL;
}

void *query10(char **query_params, FLIGHTS_CATALOG flights_catalog,
              PASSENGERS_CATALOG passengers_catalog,
              RESERVATIONS_CATALOG reservations_catalog,
              USERS_CATALOG users_catalog) {
  return NULL;
}