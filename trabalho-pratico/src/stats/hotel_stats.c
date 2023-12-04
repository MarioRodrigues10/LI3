#include "stats/hotel_stats.h"

#include <glib.h>
#include <stdio.h>

struct hotel_stats {
  char *hotel_id;
  int total_rating;
  int number_of_clients;

  GArray *hotel_reservations;
};

// SETTERS

void set_hotel_id_from_hotel_stats(HotelStats *hotel_stats, char *hotel_id) {
  hotel_stats->hotel_id = g_strdup(hotel_id);
}

void set_total_rating_from_hotel_stats(HotelStats *hotel_stats,
                                       int total_rating) {
  hotel_stats->total_rating = total_rating;
}

void set_number_of_clients_from_hotel_stats(HotelStats *hotel_stats,
                                            int number_of_clients) {
  hotel_stats->number_of_clients = number_of_clients;
}

// GETTERS

char *get_hotel_id_from_hotel_stats(HotelStats *hotel_stats) {
  char *hotel_id = g_strdup(hotel_stats->hotel_id);
  return hotel_id;
}

int get_total_rating_from_hotel_stats(HotelStats *hotel_stats) {
  int total_rating = hotel_stats->total_rating;
  return total_rating;
}

int get_number_of_clients_from_hotel_stats(HotelStats *hotel_stats) {
  int number_of_clients = hotel_stats->number_of_clients;
  return number_of_clients;
}

GArray *get_hotel_reservations(HotelStats *hotel_stats) {
  if (hotel_stats == NULL) return NULL;
  GArray *hotel_reservations = hotel_stats->hotel_reservations;
  return hotel_reservations;
}

// SET UP

HotelStats *create_hotel_stats(char *hotel_id, int total_rating,
                               int number_of_clients, char *reservation_id) {
  HotelStats *new_hotel_stats = malloc(sizeof(HotelStats));
  new_hotel_stats->hotel_id = hotel_id;
  new_hotel_stats->total_rating = total_rating;
  new_hotel_stats->number_of_clients = number_of_clients;
  new_hotel_stats->hotel_reservations =
      g_array_new(FALSE, FALSE, sizeof(char *));
  if (reservation_id != NULL)
    g_array_append_val(new_hotel_stats->hotel_reservations, reservation_id);
  return new_hotel_stats;
}

HotelStats *update_hotel_stats(HotelStats *hotel_stats, char *id, int rating,
                               char *reservation_id) {
  if (hotel_stats != NULL) {
    g_array_append_val(hotel_stats->hotel_reservations, reservation_id);
    hotel_stats->total_rating += rating;
    hotel_stats->number_of_clients++;
    return hotel_stats;
  } else {
    HotelStats *new_hotel_stats =
        create_hotel_stats(id, rating, 1, reservation_id);
    return new_hotel_stats;
  }
}

// DESTROYER

void destroy_hotel_stats(HotelStats *hotel_stats) {
  g_array_free(hotel_stats->hotel_reservations, TRUE);
  g_free(hotel_stats);
}