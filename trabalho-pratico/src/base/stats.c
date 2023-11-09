
#include "base/stats.h"

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>

struct stats {
  GHashTable *hotel;
};

struct hotel_stats {
  gpointer id;
  int total_rating;
  int total_clients;
};

STATS creat_stats() {
  STATS new_stats = malloc(sizeof(struct stats));
  new_stats->hotel = g_hash_table_new_full(NULL, g_direct_equal, NULL,
                                           (GDestroyNotify)free_stats);
  return new_stats;
}

HOTEL_STATS create_hotel_stats(gpointer id, double total_rating,
                               int total_clients) {
  HOTEL_STATS new_hotel_stats = malloc(sizeof(struct hotel_stats));
  new_hotel_stats->id = id;
  new_hotel_stats->total_rating = total_rating;
  new_hotel_stats->total_clients = total_clients;

  return new_hotel_stats;
}

void update_hotel_stats(STATS stats, gpointer id, double total_rating) {
  HOTEL_STATS hotel_stats = g_hash_table_lookup(stats->hotel, id);

  if (hotel_stats) {
    hotel_stats->total_rating += total_rating;
    hotel_stats->total_clients++;
  } else {
    hotel_stats = create_hotel_stats(id, total_rating, 1);
    g_hash_table_insert(stats->hotel, id, hotel_stats);
  }
}

int get_total_rating(STATS stats, gpointer id) {
  HOTEL_STATS hotel_stats = g_hash_table_lookup(stats->hotel, id);
  return hotel_stats->total_rating;
}

int get_total_clients(STATS stats, gpointer id) {
  HOTEL_STATS hotel_stats = g_hash_table_lookup(stats->hotel, id);
  return hotel_stats->total_clients;
}

double media_of_ratings(STATS stats, gpointer id) {
  HOTEL_STATS hotel_stats = g_hash_table_lookup(stats->hotel, id);
  return hotel_stats->total_rating / hotel_stats->total_clients;
}

void free_stats(STATS stats) {
  g_hash_table_destroy(stats->hotel);
  g_free(stats);
}