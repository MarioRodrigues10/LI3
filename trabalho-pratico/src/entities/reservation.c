#include "entities/reservation.h"

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct reservation {
  gpointer *id;
  gpointer *user_id;
  gpointer *hotel_id;
  char *hotel_name;
  int hotel_start;
  double city_tax;
  char *address;
  char *begin_date;
  char *end_date;
  int price_per_ninght;
  char *include_breakfast;
  char *room_detail;
  int rating;
  char *comment;
};

int verify_reservation_input(char **parameters) {
  if (!parameters[0]) return 0;
  if (!parameters[1]) return 0;
  if (!parameters[2]) return 0;
  if (!parameters[3]) return 0;
  if (!parameters[4]) return 0;
  if (!parameters[5]) return 0;
  if (!parameters[6]) return 0;
  if (!parameters[7]) return 0;
  if (!parameters[8]) return 0;
  if (!parameters[9]) return 0;
  if (!parameters[10]) return 0;  // breakfast  can be null
  if (!parameters[11]) return 0;
  if (!parameters[12]) return 0;
  if (!parameters[13]) return 0;
  if (!parameters[14]) return 0;

  return 1;
}

RESERVATION create_reservation() {
  RESERVATION new_reservation = g_malloc(sizeof(struct reservation));
  new_reservation->id = NULL;

  return new_reservation;
}

void set_reservation_id(RESERVATION reservation, char *id) {
  gpointer id_pointer = id;
  reservation->id = id_pointer;
}

void set_reservation_user_id(RESERVATION reservation, char *id) {
  int id_int = string_to_int(id);
  gpointer id_pointer = GINT_TO_POINTER(id_int);
  reservation->user_id = id_pointer;
}

void set_reservation_hotel_id(RESERVATION reservation, char *id) {
  l int id_int = string_to_int(id);
  gpointer id_pointer = GINT_TO_POINTER(id_int);
  reservation->hotel_id = id_pointer;
}

void set_reservation_hotel_name(RESERVATION reservation, char *hotel_name) {
  reservation->hotel_name = g_strdup(hotel_name);
}

void set_reservation_hotel_starts(RESERVATION reservation, int starts) {
  reservation->hotel_start = starts;
}

void set_reservation_city_tax(RESERVATION reservation, int tax) {
  reservation->city_tax = tax;
}

void set_reservation_address(RESERVATION reservation, char *address) {
  reservation->address = g_strdup(address);
}

void set_reservation_begin_date(RESERVATION reservation, char *begin_date) {
  reservation->begin_date = g_strdup(begin_date);
}

void set_reservation_end_date(RESERVATION reservation, char *end_date) {
  reservation->end_date = g_strdup(end_date);
}

void set_reservation_price_per_night(RESERVATION reservation,
                                     int price_per_ninght) {
  reservation->price_per_ninght = price_per_ninght;
}

void set_reservation_include_breakfast(RESERVATION reservation,
                                       char *include_breakfast) {
  reservation->include_breakfast = g_strdup(include_breakfast);
}

void set_reservation_room_detail(RESERVATION reservation, char *room_detail) {
  reservation->room_detail = g_strdup(room_detail);
}

void set_reservation_rating(RESERVATION reservation, int rating) {
  reservation->rating = rating;
}

void set_reservation_comment(RESERVATION reservation, char *comment) {
  reservation->comment = g_strdup(comment);
}

void free_reservation(RESERVATION reservation) {
  g_free(reservation->hotel_name);
  g_free(reservation->address);
  g_free(reservation->begin_date);
  g_free(reservation->end_date);
  g_free(reservation->include_breakfast);
  g_free(reservation->room_detail);
  g_free(reservation->comment);
}

int get_user_id(RESERVATION reservation) {
  int id = GPOINTER_TO_INT(reservation->user_id);
  return id
}

int get_hotel_id(RESERVATION reservation) {
  int id = GPOINTER_TO_INT(reservation->hotel_id);
  return id
}

int get_reservation_id(RESERVATION reservation) {
  int id = GPOINTER_TO_INT(reservation->id);
  return id
}

char *get_reservation_hotel_name(RESERVATION reservation) {
  char *hotel_name = strdup(reservation->hotel_name);
  return hotel_name;
}

int get_reservation_hotel_starts(RESERVATION reservation) {
  int starts = reservation->hotel_start;
  return starts;
}

double get_reservation_city_tax(RESERVATION reservation) {
  double tax = reservation->city_tax;
  return tax;
}

char *get_reservation_address(RESERVATION reservation) {
  char *address = strdup(reservation->address);
  return address;
}

char *get_reservation_begin_date(RESERVATION reservation) {
  char *begin_date = strdup(reservation->begin_date);
  return begin_date;
}

char *get_reservation_end_date(RESERVATION reservation) {
  char *end_date = strdup(reservation->end_date);
  return end_date;
}

int get_reservation_price_per_night(RESERVATION reservation) {
  int price_per_ninght = reservation->price_per_ninght;
  return price_per_ninght;
}

char *get_reservation_include_breakfast(RESERVATION reservation) {
  char *include_breakfast = strdup(reservation->include_breakfast);
  return include_breakfast;
}

char *get_reservation_room_detail(RESERVATION reservation) {
  char *room_detail = strdup(reservation->room_detail);
  return room_detail;
}

int get_reservation_rating(RESERVATION reservation) {
  int rating = reservation->rating;
  return rating;
}

char *get_reservation_comment(RESERVATION reservation) {
  char *comment = strdup(reservation->comment);
  return comment;
}
