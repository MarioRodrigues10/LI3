#include "controllers/flight_controller.h"

#include <glib.h>
#include <stdio.h>

struct flights_data {
  GHashTable *flights;

  GHashTable *flight_stats;

  GHashTable *airport_stats;

  GHashTable *airport_info;
};

// SET UP

FlightsData *flights_data_new() {
  FlightsData *flights_data = malloc(sizeof(FlightsData));

  flights_data->flights = g_hash_table_new_full(
      g_direct_hash, g_direct_equal, NULL, (GDestroyNotify)destroy_flight);

  flights_data->flight_stats =
      g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL,
                            (GDestroyNotify)destroy_flight_stats);

  flights_data->airport_stats = g_hash_table_new_full(
      g_str_hash, g_str_equal, g_free, (GDestroyNotify)destroy_airport_stats);

  flights_data->airport_info =
      g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL,
                            (GDestroyNotify)destroy_airport_info);

  return flights_data;
}

//

GHashTable *get_airport_stats(FlightsData *flights_data) {
  return flights_data->airport_stats;
}

GHashTable *get_airport_info(FlightsData *flights_data) {
  return flights_data->airport_info;
}

// FLIGHT

void add_flight(FlightsData *flights_data, FlightInfo *flight) {
  int flight_id = get_flight_id(flight);
  g_hash_table_insert(flights_data->flights, GINT_TO_POINTER(flight_id),
                      flight);
}

void flights_data_free(FlightsData *flights_data) {
  g_hash_table_destroy(flights_data->flights);
  g_hash_table_destroy(flights_data->flight_stats);
  g_hash_table_destroy(flights_data->airport_stats);
  g_hash_table_destroy(flights_data->airport_info);
  free(flights_data);
}

// FLIGHT STATS

void add_flight_stats_controller(FlightsData *flights_data,
                                 FlightStats *flight_stats) {
  int flight_id = get_flight_id_from_flight_stats(flight_stats);
  g_hash_table_insert(flights_data->flight_stats, GINT_TO_POINTER(flight_id),
                      flight_stats);
}

void update_flight_stats_controller(FlightsData *flights_data, int flight_id,
                                    int number_of_passengers) {
  FlightStats *flight_stats = g_hash_table_lookup(flights_data->flight_stats,
                                                  GINT_TO_POINTER(flight_id));
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

FlightInfo *get_flight_by_flight_id(FlightsData *flights_data, int flight_id) {
  return g_hash_table_lookup(flights_data->flights, GINT_TO_POINTER(flight_id));
}

FlightStats *get_flight_stats_by_flight_id(FlightsData *flights_data,
                                           int flight_id) {
  return g_hash_table_lookup(flights_data->flight_stats,
                             GINT_TO_POINTER(flight_id));
}

// AIRPORT STATS
struct airport_stats {
  char *airport_name;
  GArray delays;
  GArray *airport_flights;
};

// Estrutura temporária
void add_airport_stats_controller(FlightsData *flights_data,
                                  AirportStats *airport_stats) {
  g_hash_table_insert(flights_data->airport_stats, airport_stats->airport_name,
                      airport_stats);
}

void update_airport_stats_controller(FlightsData *flights_data,
                                     char *airport_name, int flight_id,
                                     int delay) {
  AirportStats *airport_stats =
      g_hash_table_lookup(flights_data->airport_stats, airport_name);
  if (airport_stats == NULL) {
    AirportStats *airport_stats =
        create_airport_stats(airport_name, flight_id, delay);
    add_airport_stats_controller(flights_data, airport_stats);
    return;
  }
  update_airport_stats(airport_stats, airport_name, flight_id, delay);
}

// get

AirportStats *get_airport_stats_by_airport_name(FlightsData *flights_data,
                                                char *airport_name) {
  return g_hash_table_lookup(flights_data->airport_stats, airport_name);
}

struct airport_info {
  int year;
  GHashTable *airports_list;
};

GHashTable *get_airports_list(FlightsData *flights_data, int year) {
  AirportInfo *airport_info =
      g_hash_table_lookup(flights_data->airport_info, GINT_TO_POINTER(year));

  return airport_info->airports_list;
}

void add_airport_info_controller(FlightsData *flights_data,
                                 AirportInfo *airport_info) {
  g_hash_table_insert(flights_data->airport_info,
                      GINT_TO_POINTER(airport_info->year), airport_info);
}

void update_airport_info_controller(FlightsData *flights_data, int year,
                                    char *origin, char *destination,
                                    int number_of_passengers) {
  AirportInfo *airport_info =
      g_hash_table_lookup(flights_data->airport_info, GINT_TO_POINTER(year));
  if (airport_info == NULL) {
    AirportInfo *airport_info =
        create_airport_info(year, origin, destination, number_of_passengers);
    add_airport_info_controller(flights_data, airport_info);
    return;
  } else {
    airport_info = update_airport_info(airport_info, origin, destination,
                                       number_of_passengers);
  }
}