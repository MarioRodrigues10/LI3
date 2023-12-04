#include "models/reservation.h"

#include <glib.h>
struct reservation {
  char *reservation_id;
  char *user_id;
  char *hotel_id;
  char *hotel_name;
  int hotel_stars;
  int city_tax;
  char *begin_date;
  char *end_date;
  int price_per_night;
  char *includes_breakfast;
  int rating;
};

// CREATE

ReservationInfo *create_reservation() {
  ReservationInfo *reservation = g_malloc(sizeof(ReservationInfo));

  return reservation;
}

// SETTERS

void set_reservation_id(ReservationInfo *reservation, char *reservation_id) {
  reservation->reservation_id = g_strdup(reservation_id);
}

void set_user_id_reservation(ReservationInfo *reservation, char *user_id) {
  reservation->user_id = g_strdup(user_id);
}

void set_hotel_id(ReservationInfo *reservation, char *hotel_id) {
  reservation->hotel_id = g_strdup(hotel_id);
}

void set_hotel_name(ReservationInfo *reservation, char *hotel_name) {
  reservation->hotel_name = g_strdup(hotel_name);
}

void set_hotel_stars(ReservationInfo *reservation, int hotel_stars) {
  reservation->hotel_stars = hotel_stars;
}

void set_city_tax(ReservationInfo *reservation, int city_tax) {
  reservation->city_tax = city_tax;
}

void set_begin_date(ReservationInfo *reservation, char *begin_date) {
  reservation->begin_date = g_strdup(begin_date);
}

void set_end_date(ReservationInfo *reservation, char *end_date) {
  reservation->end_date = g_strdup(end_date);
}

void set_price_per_night(ReservationInfo *reservation, int price_per_night) {
  reservation->price_per_night = price_per_night;
}

void set_includes_breakfast(ReservationInfo *reservation,
                            char *includes_breakfast) {
  reservation->includes_breakfast = g_strdup(includes_breakfast);
}

void set_rating(ReservationInfo *reservation, int rating) {
  reservation->rating = rating;
}

// GETTERS

char *get_reservation_id(ReservationInfo *reservation) {
  char *reservation_id = g_strdup(reservation->reservation_id);
  return reservation_id;
}

char *get_user_id_reservation(ReservationInfo *reservation) {
  char *user_id = g_strdup(reservation->user_id);
  return user_id;
}

char *get_hotel_id(ReservationInfo *reservation) {
  char *hotel_id = g_strdup(reservation->hotel_id);
  return hotel_id;
}

char *get_hotel_name(ReservationInfo *reservation) {
  char *hotel_name = g_strdup(reservation->hotel_name);
  return hotel_name;
}

int get_hotel_stars(ReservationInfo *reservation) {
  int hotel_stars = reservation->hotel_stars;
  return hotel_stars;
}

int get_city_tax(ReservationInfo *reservation) {
  int city_tax = reservation->city_tax;
  return city_tax;
}

char *get_begin_date(ReservationInfo *reservation) {
  char *begin_date = g_strdup(reservation->begin_date);
  return begin_date;
}

char *get_end_date(ReservationInfo *reservation) {
  char *end_date = g_strdup(reservation->end_date);
  return end_date;
}

int get_price_per_night(ReservationInfo *reservation) {
  int price_per_night = reservation->price_per_night;
  return price_per_night;
}

char *get_includes_breakfast(ReservationInfo *reservation) {
  char *includes_breakfast = g_strdup(reservation->includes_breakfast);
  return includes_breakfast;
}

int get_rating(ReservationInfo *reservation) {
  int rating = reservation->rating;
  return rating;
}

// DESTROYER

void destroy_reservation(ReservationInfo *reservation) {
  g_free(reservation->reservation_id);
  g_free(reservation->user_id);
  g_free(reservation->hotel_id);
  g_free(reservation->hotel_name);
  g_free(reservation->begin_date);
  g_free(reservation->end_date);
  g_free(reservation->includes_breakfast);
  g_free(reservation);
}