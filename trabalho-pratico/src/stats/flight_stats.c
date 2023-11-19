#include "stats/flight_stats.h"

#include <glib.h>
#include <stdio.h>

struct flight_stats {
  char *flight_id;
  int number_of_passengers;
};

// SETTERS

void set_flight_id_from_flight_stats(FlightStats *flight_stats,
                                     char *flight_id) {
  flight_stats->flight_id = g_strdup(flight_id);
}

void set_number_of_passengers_from_flight_stats(FlightStats *flight_stats,
                                                int number_of_passengers) {
  flight_stats->number_of_passengers = number_of_passengers;
}

// GETTERS

char *get_flight_id_from_flight_stats(FlightStats *flight_stats) {
  char *flight_id = g_strdup(flight_stats->flight_id);
  return flight_id;
}

int get_number_of_passengers_from_flight_stats(FlightStats *flight_stats) {
  int number_of_passengers = flight_stats->number_of_passengers;
  return number_of_passengers;
}

// SET UP

FlightStats *create_flight_stats(char *flight_id, int number_of_passengers) {
  FlightStats *new_flight_stats = malloc(sizeof(FlightStats));
  new_flight_stats->flight_id = flight_id;
  new_flight_stats->number_of_passengers = number_of_passengers;
  return new_flight_stats;
}

FlightStats *update_flight_stats(FlightStats *flight_stats, char *id,
                                 int passengers) {
  if (flight_stats != NULL) {
    flight_stats->number_of_passengers += passengers;
    return flight_stats;
  } else {
    FlightStats *new_flight_stats = create_flight_stats(id, passengers);
    return new_flight_stats;
  }
}

// DESTROYER

void destroy_flight_stats(FlightStats *flight_stats) { g_free(flight_stats); }
