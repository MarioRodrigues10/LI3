#include "models/reservation.h"

#include <glib.h>
#include <stdbool.h>

struct reservation {
  char *user_id;
  int reservation_id;
  int hotel_id;
  int begin_date;
  int end_date;
  int price_per_night;
  char hotel_name;
  char hotel_stars;
  char city_tax;
  char rating;
  bool includes_breakfast;
};

// CREATE

ReservationInfo *create_reservation() {
  ReservationInfo *reservation = g_malloc(sizeof(ReservationInfo));

  return reservation;
}

// SETTERS

void set_reservation_id(ReservationInfo *reservation, int reservation_id) {
  reservation->reservation_id = reservation_id;
}

void set_user_id_reservation(ReservationInfo *reservation, char *user_id) {
  reservation->user_id = g_strdup(user_id);
}

void set_hotel_id(ReservationInfo *reservation, int hotel_id) {
  reservation->hotel_id = hotel_id;
}

void set_hotel_name(ReservationInfo *reservation, char hotel_name) {
  reservation->hotel_name = hotel_name;
}

void set_hotel_stars(ReservationInfo *reservation, char hotel_stars) {
  reservation->hotel_stars = hotel_stars;
}

void set_city_tax(ReservationInfo *reservation, char city_tax) {
  reservation->city_tax = city_tax;
}

void set_begin_date(ReservationInfo *reservation, int begin_date) {
  reservation->begin_date = begin_date;
}

void set_end_date(ReservationInfo *reservation, int end_date) {
  reservation->end_date = end_date;
}

void set_price_per_night(ReservationInfo *reservation, int price_per_night) {
  reservation->price_per_night = price_per_night;
}

void set_includes_breakfast(ReservationInfo *reservation,
                            bool includes_breakfast) {
  reservation->includes_breakfast = includes_breakfast;
}

void set_rating(ReservationInfo *reservation, char rating) {
  reservation->rating = rating;
}

// GETTERS

int get_reservation_id(ReservationInfo *reservation) {
  int reservation_id = reservation->reservation_id;
  return reservation_id;
}

char *get_user_id_reservation(ReservationInfo *reservation) {
  char *user_id = g_strdup(reservation->user_id);
  return user_id;
}

int get_hotel_id(ReservationInfo *reservation) { return reservation->hotel_id; }

char get_hotel_name(ReservationInfo *reservation) {
  char hotel_name = reservation->hotel_name;
  return hotel_name;
}

char get_hotel_stars(ReservationInfo *reservation) {
  char hotel_stars = reservation->hotel_stars;
  return hotel_stars;
}

char get_city_tax(ReservationInfo *reservation) {
  char city_tax = reservation->city_tax;
  return city_tax;
}

int get_begin_date(ReservationInfo *reservation) {
  return reservation->begin_date;
}

int get_end_date(ReservationInfo *reservation) { return reservation->end_date; }

int get_price_per_night(ReservationInfo *reservation) {
  int price_per_night = reservation->price_per_night;
  return price_per_night;
}

bool get_includes_breakfast(ReservationInfo *reservation) {
  return reservation->includes_breakfast;
}

char get_rating(ReservationInfo *reservation) {
  char rating = reservation->rating;
  return rating;
}

// DESTROYER

void destroy_reservation(ReservationInfo *reservation) {
  g_free(reservation->user_id);
  g_free(reservation);
}