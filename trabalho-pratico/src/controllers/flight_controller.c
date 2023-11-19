#include "controllers/flight_controller.h"

#include <glib.h>

struct flights_data {
  GHashTable *flights;

  GHashTable *flight_stats;
};

// SET UP

FlightsData *flights_data_new() {
  FlightsData *flights_data = malloc(sizeof(FlightsData));
  flights_data->flights = g_hash_table_new_full(g_str_hash, g_str_equal, g_free,
                                                (GDestroyNotify)destroy_flight);
  flights_data->flight_stats = g_hash_table_new_full(
      g_str_hash, g_str_equal, g_free, (GDestroyNotify)destroy_flight_stats);
  return flights_data;
}

// FLIGHT

void add_flight(FlightsData *flights_data, FlightInfo *flight) {
  char *flight_id = get_flight_id(flight);
  g_hash_table_insert(flights_data->flights, flight_id, flight);
}

void flights_data_free(FlightsData *flights_data) {
  g_hash_table_destroy(flights_data->flights);
  g_hash_table_destroy(flights_data->flight_stats);
  free(flights_data);
}

// FLIGHT STATS

void add_flight_stats_controller(FlightsData *flights_data,
                                 FlightStats *flight_stats) {
  char *flight_id = get_flight_id_from_flight_stats(flight_stats);
  g_hash_table_insert(flights_data->flight_stats, flight_id, flight_stats);
}

void update_flight_stats_controller(FlightsData *flights_data, char *flight_id,
                                    int number_of_passengers) {
  FlightStats *flight_stats =
      g_hash_table_lookup(flights_data->flight_stats, flight_id);
  if (flight_stats == NULL) {
    FlightStats *flight_stats =
        create_flight_stats(flight_id, number_of_passengers);
    add_flight_stats_controller(flights_data, flight_stats);
    return;
  }
  flight_stats =
      update_flight_stats(flight_stats, flight_id, number_of_passengers);
}

// ACCESS

FlightInfo *get_flight_by_flight_id(FlightsData *flights_data,
                                    char *flight_id) {
  return g_hash_table_lookup(flights_data->flights, flight_id);
}

FlightStats *get_flight_stats_by_flight_id(FlightsData *flights_data,
                                           char *flight_id) {
  return g_hash_table_lookup(flights_data->flight_stats, flight_id);
}
