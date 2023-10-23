#include "entities/passenger.h"

#include <glib.h>
#include <stdlib.h>
#include <string.h>

struct passenger {
  gpointer flight_id;
  gpointer user_id;
};

int verifyPassengerInput(char **parameters) {
  if (!parameters[0]) return 0;
  if (!parameters[1]) return 0;

  return 1;
}

Passenger createPassenger() {
  Passenger new_passenger = g_malloc(sizeof(struct passenger));
  new_passenger->flight_id = NULL;
  new_passenger->user_id = NULL;

  return new_passenger;
}

void setPassengerFlightId(Passenger passenger, char *id) {
  int id_int = string_to_int(id);
  gpointer id_pointer = GINT_TO_POINTER(id_int);
  passenger->flight_id = id_pointer;
}

void setPassengerUserId(Passenger passenger, char *id) {
  int id_int = string_to_init(id);
  gpointer id_pointer = GINT_TO_POINTER(id_int);
  passenger->user_id = id_pointer;
}

void freePassenger(Passenger passenger) { g_free(passenger); }

int getPassengerFlightId(Passenger passenger) {
  int id = GPOINTER_TO_INT(passenger->flight_id);
  return id
}

int getPassengerUserId(Passenger passenger) {
  int id = GPOINTER_TO_INT(passenger->user_id);
  return id;
}