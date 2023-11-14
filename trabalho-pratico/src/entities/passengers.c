#include "entities/passengers.h"

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct passenger {
  char *flight_id;
  char *user_id;
};

int verify_passenger_input(char **parameters) {
  if (!parameters[0]) return 0;
  if (!parameters[1]) return 0;

  return 1;
}

PASSENGER create_passenger() {
  PASSENGER new_passenger = malloc(sizeof(struct passenger));

  return new_passenger;
}

void build_passenger(char **passenger_params, void *catalog, STATS stats) {
  if (!verify_passenger_input(passenger_params)) return;

  PASSENGER passenger = create_passenger();
  PASSENGERS_CATALOG passengers_catalog = (PASSENGERS_CATALOG)catalog;

  set_passenger_flight_id(passenger, passenger_params[0]);
  set_passenger_user_id(passenger, passenger_params[1]);

  // What is the id for each passenger, user_id and flight_id can be repeated
  add_to_passengers_catalog(passengers_catalog, passenger, passenger->user_id);

  update_flight_stats(stats, passenger_params[0]);
  update_user_stats_number_of_flights(stats, passenger_params[1],
                                      passenger_params[0]);
}

void set_passenger_flight_id(PASSENGER passenger, char *id) {
  passenger->flight_id = g_strdup(id);
}

void set_passenger_user_id(PASSENGER passenger, char *id) {
  passenger->user_id = g_strdup(id);
}

void free_passenger(PASSENGER passenger) { free(passenger); }

char *get_passenger_flight_id(PASSENGER passenger) {
  char *id = passenger->flight_id;
  return id;
}

char *get_passenger_user_id(PASSENGER passenger) {
  char *id = passenger->user_id;
  return id;
}
