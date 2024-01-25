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
  airport_stats->airport_name = airport_name;
}

// GETTERS

char *get_airport_name_from_airport_stats(AirportStats *airport_stats) {
  char *airport_name = g_strdup(airport_stats->airport_name);
  return airport_name;
}

GArray *get_airport_flights_from_airport_stats(AirportStats *airport_stats) {
  return g_array_copy(airport_stats->airport_flights);
}

GArray *get_delays(AirportStats *airport_stats) {
  return g_array_copy(airport_stats->delays);
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
    g_array_free(airport_stats->delays, TRUE);
    g_free(airport_stats);
  }
}

// AIRPORT INFO

struct airport_info {
  int year;
  GHashTable *airports_list;
};

struct airport_info_list {
  char *airport;
  int number_of_passengers;
};
// SETTERS

void set_year_of_airport_info(AirportInfo *airport_info, int year) {
  airport_info->year = year;
}
// GETTERS

int get_year_from_airport_info(AirportInfo *airport_info) {
  return airport_info->year;
}

GHashTable *get_airports_list_from_airport_info(AirportInfo *airport_info) {
  return airport_info->airports_list;
}

int get_number_of_passengers_from_airport_info_list(
    AirportInfoList *airport_info_list) {
  return airport_info_list->number_of_passengers;
}

void get_airport_info_list(gpointer key, gpointer value, gpointer user_data) {
  AirportInfoList *airport_info_list = (AirportInfoList *)value;

  struct airport_info_list result_entry;
  result_entry.airport = key;
  result_entry.number_of_passengers = airport_info_list->number_of_passengers;

  g_array_append_val((GArray *)user_data, result_entry);
}

AirportInfo *create_airport_info(int year, char *origin, char *destination,
                                 int number_of_passengers) {
  AirportInfo *new_airport_info = malloc(sizeof(AirportInfo));
  new_airport_info->year = year;
  new_airport_info->airports_list =
      g_hash_table_new_full(g_str_hash, g_str_equal, g_free,
                            (GDestroyNotify)destroy_airport_info_list);

  if (origin != NULL) {
    AirportInfoList *new_airport_info_list = malloc(sizeof(AirportInfoList));
    char *origin_copy = g_strdup(origin);
    new_airport_info_list->airport = origin_copy;
    new_airport_info_list->number_of_passengers = number_of_passengers;
    g_hash_table_insert(new_airport_info->airports_list, origin_copy,
                        new_airport_info_list);
  }
  if (destination != NULL) {
    AirportInfoList *new_airport_info_list = malloc(sizeof(AirportInfoList));
    char *destination_copy = g_strdup(destination);
    new_airport_info_list->airport = destination_copy;
    new_airport_info_list->number_of_passengers = number_of_passengers;
    g_hash_table_insert(new_airport_info->airports_list, destination_copy,
                        new_airport_info_list);
  }
  return new_airport_info;
}

AirportInfo *update_airport_info(AirportInfo *airport_info, char *origin,
                                 char *destination, int number_of_passengers) {
  // Check if the airport_info is not NULL
  if (airport_info != NULL) {
    // Check if the airport is not NULL
    if (origin != NULL && destination != NULL) {
      AirportInfoList *airport_info_list_o =
          g_hash_table_lookup(airport_info->airports_list, origin);

      if (airport_info_list_o != NULL) {
        // Airport already exists, update the number_of_passengers
        airport_info_list_o->number_of_passengers += number_of_passengers;
      } else {
        // Airport doesn't exist, create a new entry
        char *origin_copy = g_strdup(origin);
        AirportInfoList *new_airport_info_list =
            g_malloc(sizeof(AirportInfoList));
        new_airport_info_list->airport = origin_copy;
        new_airport_info_list->number_of_passengers = number_of_passengers;

        // Insert the new entry into the hash table
        g_hash_table_insert(airport_info->airports_list,
                            new_airport_info_list->airport,
                            new_airport_info_list);
      }

      AirportInfoList *airport_info_list_d =
          g_hash_table_lookup(airport_info->airports_list, destination);
      if (airport_info_list_d != NULL) {
        airport_info_list_d->number_of_passengers += number_of_passengers;
      } else {
        char *destination_copy = g_strdup(destination);
        AirportInfoList *new_airport_info_list =
            g_malloc(sizeof(AirportInfoList));
        new_airport_info_list->airport = destination_copy;
        new_airport_info_list->number_of_passengers = number_of_passengers;

        // Insert the new entry into the hash table
        g_hash_table_insert(airport_info->airports_list,
                            new_airport_info_list->airport,
                            new_airport_info_list);
      }
    }
  }
  return airport_info;
}

// DESTROYER

void destroy_airport_info_list(AirportInfoList *airport_info_list) {
  if (airport_info_list) {
    // g_free(airport_info_list->airport);
    g_free(airport_info_list);
  }
}

void destroy_airport_info(AirportInfo *airport_info) {
  if (airport_info != NULL) {
    g_hash_table_destroy(airport_info->airports_list);
    g_free(airport_info);
  }
}
