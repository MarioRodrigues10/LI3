#include "stats/airport_stats.h"

#include <glib.h>

struct airport_info {
  char *flight_id;
  char *departure_date;
  char *destination;
  char *airline;
  char *plane_model;
};

struct airport_stats {
  char *airport_name;
  GArray *airport_flights;
};

// SETTERS

void set_flight_id_of_airport_info(AirportInfo *airport_info, char *flight_id) {
  airport_info->flight_id = g_strdup(flight_id);
}

void set_departure_date_of_airport_info(AirportInfo *airport_info,
                                        char *departure_date) {
  airport_info->departure_date = g_strdup(departure_date);
}

void set_destination_of_airport_info(AirportInfo *airport_info,
                                     char *destination) {
  airport_info->destination = g_strdup(destination);
}

void set_airline_of_airport_info(AirportInfo *airport_info, char *airline) {
  airport_info->airline = g_strdup(airline);
}

void set_plane_model_of_airport_info(AirportInfo *airport_info,
                                     char *plane_model) {
  airport_info->plane_model = g_strdup(plane_model);
}

void set_airport_name_of_airport_stats(AirportStats *airport_stats,
                                       char *airport_name) {
  airport_stats->airport_name = g_strdup(airport_name);
}

// GETTERS

char *get_flight_id_from_airport_info(AirportInfo *airport_info) {
  char *flight_id = g_strdup(airport_info->flight_id);
  return flight_id;
}

char *get_departure_date_from_airport_info(AirportInfo *airport_info) {
  char *departure_date = g_strdup(airport_info->departure_date);
  return departure_date;
}

char *get_destination_from_airport_info(AirportInfo *airport_info) {
  char *destination = g_strdup(airport_info->destination);
  return destination;
}

char *get_airline_from_airport_info(AirportInfo *airport_info) {
  char *airline = g_strdup(airport_info->airline);
  return airline;
}

char *get_plane_model_from_airport_info(AirportInfo *airport_info) {
  char *plane_model = g_strdup(airport_info->plane_model);
  return plane_model;
}

char *get_airport_name_from_airport_stats(AirportStats *airport_stats) {
  char *airport_name = g_strdup(airport_stats->airport_name);
  return airport_name;
}

GArray *get_airport_flights_from_airport_stats(AirportStats *airport_stats) {
  return airport_stats->airport_flights;
}

// ADDER

// Temporáriamente isto não é necessário
void add_airport_info(AirportStats *airport_stats, AirportInfo *airport_info) {
  AirportInfo copy_info;
  copy_info.flight_id = g_strdup(airport_info->flight_id);
  copy_info.departure_date = g_strdup(airport_info->departure_date);
  copy_info.destination = g_strdup(airport_info->destination);
  copy_info.airline = g_strdup(airport_info->airline);
  copy_info.plane_model = g_strdup(airport_info->plane_model);

  g_array_append_val(airport_stats->airport_flights, copy_info);
}

// SET UP

AirportInfo *create_airport_info(char *flight_id, char *departure_date,
                                 char *destination, char *airline,
                                 char *plane_model) {
  AirportInfo *new_airport_info = malloc(sizeof(AirportInfo));

  new_airport_info->flight_id = flight_id;
  new_airport_info->departure_date = departure_date;
  new_airport_info->destination = destination;
  new_airport_info->airline = airline;
  new_airport_info->plane_model = plane_model;

  return new_airport_info;
}

AirportStats *create_airport_stats(char *airport_name,
                                   AirportInfo *airport_info) {
  AirportStats *new_airport_stats = malloc(sizeof(AirportStats));
  set_airport_name_of_airport_stats(new_airport_stats, airport_name);
  // new_airport_stats->airport_name = airport_name;
  new_airport_stats->airport_flights =
      g_array_new(FALSE, FALSE, sizeof(AirportInfo));
  g_array_append_val(new_airport_stats->airport_flights, *airport_info);
  // add_airport_info(new_airport_stats, airport_info);
  return new_airport_stats;
}

AirportStats *update_airport_stats(AirportStats *airport_stats,
                                   char *airport_name,
                                   AirportInfo *airport_info) {
  if (airport_stats != NULL) {
    // airport_stats->airport_name = airport_name;
    g_array_append_val(airport_stats->airport_flights, *airport_info);
    // add_airport_info(airport_stats, airport_info);
    return airport_stats;
  } else {
    AirportStats *new_airport_stats =
        create_airport_stats(airport_name, airport_info);
    return new_airport_stats;
  }
}

// DESTROYER

// Esta função tem de ser revista
void destroy_airport_info(AirportInfo *airport_info) {
  if (airport_info) {
    g_free(airport_info->flight_id);
    g_free(airport_info->departure_date);
    g_free(airport_info->destination);
    g_free(airport_info->plane_model);
    g_free(airport_info);
  }
}

void destroy_airport_stats(AirportStats *airport_stats) {
  if (airport_stats) {
    // g_free(airport_stats->airport_name);
    g_array_free(airport_stats->airport_flights, TRUE);
    g_free(airport_stats);
  }
}

// ACCESS

AirportInfo *get_airport_info_by_index(AirportStats *airport_stats, int index) {
  return g_array_index(airport_stats->airport_flights, AirportInfo *, index);
}

// SORT

void sort_airport_info_by_departure_date(AirportStats *airport_stats) {
  g_array_sort(airport_stats->airport_flights,
               (GCompareFunc)compare_airport_info_by_departure_date);
}

// COMPARE

int compare_airport_info_by_departure_date(gconstpointer a, gconstpointer b) {
  AirportInfo *info1 = (AirportInfo *)a;
  AirportInfo *info2 = (AirportInfo *)b;

  int dateComparison = strcmp(info1->departure_date, info2->departure_date);

  if (dateComparison != 0) {
    return -dateComparison;
  } else {
    return strcmp(info1->flight_id, info2->flight_id);
  }
}
