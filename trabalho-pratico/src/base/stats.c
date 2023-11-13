
#include "base/stats.h"

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>

struct stats {
  GHashTable *hotel;

  GHashTable *flight;

  GHashTable *user;
};

// OVERALL STATS

STATS create_stats() {
  STATS new_stats = malloc(sizeof(struct stats));
  new_stats->hotel = g_hash_table_new_full(g_str_hash, g_str_equal, NULL,
                                           (GDestroyNotify)free_hotel_stats);

  new_stats->flight = g_hash_table_new_full(g_str_hash, g_str_equal, NULL,
                                            (GDestroyNotify)free_flight_stats);

  new_stats->user = g_hash_table_new_full(g_str_hash, g_str_equal, NULL,
                                          (GDestroyNotify)free_user_stats);
  return new_stats;
}

void free_stats(STATS stats) {
  g_hash_table_destroy(stats->hotel);
  g_free(stats);
}

// HOTEL_STATS

struct hotel_stats {
  char *hotel_id;
  int total_rating;
  int total_clients;
};

HOTEL_STATS create_hotel_stats(char *hotel_id, int hotel_stars,
                               int total_clients) {
  HOTEL_STATS new_hotel_stats = malloc(sizeof(struct hotel_stats));
  new_hotel_stats->hotel_id = hotel_id;
  new_hotel_stats->total_rating = hotel_stars;
  new_hotel_stats->total_clients = total_clients;

  return new_hotel_stats;
}

void update_hotel_stats(STATS stats, char *hotel_id, int hotel_rating) {
  HOTEL_STATS hotel_stats = g_hash_table_lookup(stats->hotel, hotel_id);

  if (hotel_stats != NULL) {
    hotel_stats->total_rating += hotel_rating;
    hotel_stats->total_clients++;
  } else {
    HOTEL_STATS hotel_stats = create_hotel_stats(hotel_id, hotel_rating, 1);
    g_hash_table_insert(stats->hotel, hotel_id, hotel_stats);
  }
}

HOTEL_STATS get_hotel_stats_by_hotel_id(STATS stats, char *hotel_id) {
  return g_hash_table_lookup(stats->hotel, hotel_id);
}

int get_total_clients(STATS stats, char *hotel_id) {
  HOTEL_STATS hotel_stats = g_hash_table_lookup(stats->hotel, hotel_id);
  return hotel_stats->total_clients;
}

double media_of_ratings(STATS stats, char *hotel_id) {
  HOTEL_STATS hotel_stats = g_hash_table_lookup(stats->hotel, hotel_id);
  return (double)hotel_stats->total_rating / (double)hotel_stats->total_clients;
}

void free_hotel_stats(HOTEL_STATS hotel_stats) {
  free(hotel_stats->hotel_id);
  free(hotel_stats);
}

// FLIGHT_STATS

struct flight_stats {
  char *flight_id;
  int total_passengers;
};

FLIGHT_STATS create_flight_stats(char *flight_id, int total_passengers) {
  FLIGHT_STATS new_flight_stats = malloc(sizeof(struct flight_stats));
  new_flight_stats->flight_id = flight_id;
  new_flight_stats->total_passengers = total_passengers;

  return new_flight_stats;
}

void update_flight_stats(STATS stats, char *flight_id) {
  FLIGHT_STATS flight_stats = g_hash_table_lookup(stats->flight, flight_id);

  if (flight_stats != NULL) {
    flight_stats->total_passengers++;
  } else {
    FLIGHT_STATS flight_stats = create_flight_stats(flight_id, 1);
    g_hash_table_insert(stats->flight, flight_id, flight_stats);
  }
}

FLIGHT_STATS get_flight_stats_by_flight_id(STATS stats, char *flight_id) {
  return g_hash_table_lookup(stats->flight, flight_id);
}

int get_total_passengers(STATS stats, char *flight_id) {
  FLIGHT_STATS flight_stats = g_hash_table_lookup(stats->flight, flight_id);
  return flight_stats->total_passengers;
}

void free_flight_stats(FLIGHT_STATS flight_stats) {
  free(flight_stats->flight_id);
  free(flight_stats);
}

// USER STATS

struct user_stats {
  char *user_id;
  int number_of_flights;
  int number_of_reservations;
  double total_spent;
};

USER_STATS create_user_stats(char *user_id, int number_of_flights,
                             int number_of_reservations, double total_spent) {
  USER_STATS new_user_stats = malloc(sizeof(struct user_stats));
  new_user_stats->user_id = user_id;
  new_user_stats->number_of_flights = number_of_flights;
  new_user_stats->number_of_reservations = number_of_reservations;
  new_user_stats->total_spent = total_spent;

  return new_user_stats;
}

void update_user_stats_number_of_flights(STATS stats, char *user_id) {
  USER_STATS user_stats = g_hash_table_lookup(stats->user, user_id);

  if (user_stats != NULL) {
    user_stats->number_of_flights++;
  } else {
    USER_STATS user_stats = create_user_stats(user_id, 1, 0, 0);
    g_hash_table_insert(stats->user, user_id, user_stats);
  }
}

void update_user_stats_number_of_reservations(STATS stats, char *user_id) {
  USER_STATS user_stats = g_hash_table_lookup(stats->user, user_id);

  if (user_stats != NULL) {
    user_stats->number_of_reservations++;
  } else {
    USER_STATS user_stats = create_user_stats(user_id, 0, 1, 0);
    g_hash_table_insert(stats->user, user_id, user_stats);
  }
}

void update_user_stats_total_spent(STATS stats, char *user_id,
                                   double total_spent) {
  USER_STATS user_stats = g_hash_table_lookup(stats->user, user_id);

  if (user_stats != NULL) {
    user_stats->total_spent += total_spent;
  } else {
    USER_STATS user_stats = create_user_stats(user_id, 0, 0, total_spent);
    g_hash_table_insert(stats->user, user_id, user_stats);
  }
}

USER_STATS get_user_stats_by_user_id(STATS stats, char *user_id) {
  return g_hash_table_lookup(stats->user, user_id);
}

int get_number_of_flights(STATS stats, char *user_id) {
  USER_STATS user_stats = g_hash_table_lookup(stats->user, user_id);
  return user_stats->number_of_flights;
}

int get_number_of_reservations(STATS stats, char *user_id) {
  USER_STATS user_stats = g_hash_table_lookup(stats->user, user_id);
  return user_stats->number_of_reservations;
}

double get_total_spent(STATS stats, char *user_id) {
  USER_STATS user_stats = g_hash_table_lookup(stats->user, user_id);
  return user_stats->total_spent;
}

void free_user_stats(USER_STATS user_stats) {
  free(user_stats->user_id);
  free(user_stats);
}