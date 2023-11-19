#include "controllers/reservation_controller.h"

#include <glib.h>

struct reservations_data {
  GHashTable *reservations;

  GHashTable *hotel_stats;
};

// SET UP

ReservationsData *reservations_data_new() {
  ReservationsData *reservations_data = malloc(sizeof(ReservationsData));
  reservations_data->reservations = g_hash_table_new_full(
      g_str_hash, g_str_equal, g_free, (GDestroyNotify)destroy_reservation);
  reservations_data->hotel_stats = g_hash_table_new_full(
      g_str_hash, g_str_equal, g_free, (GDestroyNotify)destroy_hotel_stats);
  return reservations_data;
}

// RESERVATION

void add_reservation(ReservationsData *reservations_data,
                     ReservationInfo *reservation) {
  char *reservation_id = get_reservation_id(reservation);
  g_hash_table_insert(reservations_data->reservations, reservation_id,
                      reservation);
}

void reservations_data_free(ReservationsData *reservations_data) {
  g_hash_table_destroy(reservations_data->reservations);
  g_hash_table_destroy(reservations_data->hotel_stats);
  free(reservations_data);
}

// HOTEL STATS

void add_hotel_stats_controller(ReservationsData *reservations_data,
                                HotelStats *hotel_stats) {
  char *hotel_id = get_hotel_id_from_hotel_stats(hotel_stats);
  g_hash_table_insert(reservations_data->hotel_stats, hotel_id, hotel_stats);
}

void update_hotel_stats_controller(ReservationsData *reservations_data,
                                   char *hotel_id, int rating,
                                   char *reservation_id) {
  HotelStats *hotel_stats =
      g_hash_table_lookup(reservations_data->hotel_stats, hotel_id);
  if (hotel_stats == NULL) {
    HotelStats *hotel_stats =
        create_hotel_stats(hotel_id, rating, 1, reservation_id);
    add_hotel_stats_controller(reservations_data, hotel_stats);
    return;
  }
  hotel_stats =
      update_hotel_stats(hotel_stats, hotel_id, rating, reservation_id);
}

// ACCESS

ReservationInfo *get_reservation_by_reservation_id(
    ReservationsData *reservations_data, char *reservation_id) {
  return g_hash_table_lookup(reservations_data->reservations, reservation_id);
}

HotelStats *get_hotel_stats_by_hotel_id(ReservationsData *reservations_data,
                                        char *hotel_id) {
  return g_hash_table_lookup(reservations_data->hotel_stats, hotel_id);
}
