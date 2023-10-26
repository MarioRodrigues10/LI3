#include "entities/passengers.h"

#include <glib.h>
#include <stdlib.h>
#include <string.h>

struct passenger {
  gpointer flight_id;
  gpointer user_id;
};

int verify_passenger_input(char **parameters) {
  if (!parameters[0]) return 0;
  if (!parameters[1]) return 0;

  return 1;
}

PASSENGER create_passenger() {
  PASSENGER new_passenger = g_malloc(sizeof(struct passenger));
  new_passenger->flight_id = NULL;
  new_passenger->user_id = NULL;

  return new_passenger;
}

void set_passenger_flight_id(PASSENGER passenger, char *id) {
  int id_int = string_to_int(id);
  gpointer id_pointer = GINT_TO_POINTER(id_int);
  passenger->flight_id = id_pointer;
}

void set_passenger_user_id(PASSENGER passenger, char *id) {
  int id_int = string_to_init(id);
  gpointer id_pointer = GINT_TO_POINTER(id_int);
  passenger->user_id = id_pointer;
}

void free_passenger(PASSENGER passenger) { g_free(passenger); }

int get_passenger_flight_id(PASSENGER passenger) {
  int id = GPOINTER_TO_INT(passenger->flight_id);
  return id
}

int get_passenger_user_id(PASSENGER passenger) {
  int id = GPOINTER_TO_INT(passenger->user_id);
  return id;
}