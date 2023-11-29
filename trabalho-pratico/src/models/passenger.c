#include "models/passenger.h"

#include <glib.h>

struct passenger {
  char *flight_id;
  char *user_id;
};

// CREATE

PassengerInfo *create_passenger() {
  PassengerInfo *passenger = g_malloc(sizeof(PassengerInfo));

  return passenger;
}

// SETTERS

void set_flight_id_passenger(PassengerInfo *passenger, char *flight_id) {
  passenger->flight_id = g_strdup(flight_id);
}

void set_user_id_passenger(PassengerInfo *passenger, char *user_id) {
  passenger->user_id = g_strdup(user_id);
}

// GETTERS

char *get_flight_id_passenger(PassengerInfo *passenger) {
  char *flight_id = g_strdup(passenger->flight_id);
  return flight_id;
}

char *get_user_id_passenger(PassengerInfo *passenger) {
  char *user_id = g_strdup(passenger->user_id);
  return user_id;
}

// DESTROYER

void destroy_passenger(PassengerInfo *passenger) {
  if (passenger == NULL) return;
  g_free(passenger->flight_id);
  g_free(passenger->user_id);
  g_free(passenger);
}
