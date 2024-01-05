#include "stats/airport_stats.h"

#include <glib.h>
#include <stdio.h>
struct airport_stats {
  char *airport_name;
  GArray *delays;
  GArray *airport_flights;
};

// SETTERS

void set_airport_name_of_airport_stats(AirportStats *airport_stats,
                                       char *airport_name) {
  airport_stats->airport_name = g_strdup(airport_name);
}

// GETTERS

char *get_airport_name_from_airport_stats(AirportStats *airport_stats) {
  char *airport_name = g_strdup(airport_stats->airport_name);
  return airport_name;
}

GArray *get_airport_flights_from_airport_stats(AirportStats *airport_stats) {
  return airport_stats->airport_flights;
}

GArray *get_delays(AirportStats *airport_stats) {
  return airport_stats->delays;
}

// SET UP

AirportStats *create_airport_stats(char *airport_name, int flight_id,
                                   int delay) {
  AirportStats *new_airport_stats = malloc(sizeof(AirportStats));
  set_airport_name_of_airport_stats(new_airport_stats, airport_name);
  new_airport_stats->airport_flights = g_array_new(FALSE, FALSE, sizeof(int));
  g_array_append_val(new_airport_stats->airport_flights, flight_id);

  new_airport_stats->delays = g_array_new(FALSE, FALSE, sizeof(int));

  g_array_append_val(new_airport_stats->delays, delay);
  return new_airport_stats;
}

AirportStats *update_airport_stats(AirportStats *airport_stats,
                                   char *airport_name, int flight_id,
                                   int delay) {
  if (airport_stats != NULL) {
    g_array_append_val(airport_stats->airport_flights, flight_id);
    g_array_append_val(airport_stats->delays, delay);
    return airport_stats;
  } else {
    AirportStats *new_airport_stats =
        create_airport_stats(airport_name, flight_id, delay);

    return new_airport_stats;
  }
}

// DESTROYER
void destroy_airport_stats(AirportStats *airport_stats) {
  if (airport_stats) {
    g_array_free(airport_stats->airport_flights, TRUE);
    g_free(airport_stats);
  }
}
