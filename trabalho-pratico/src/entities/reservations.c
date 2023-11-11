#include "entities/reservations.h"

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/utils.h"

struct reservation {
  gpointer id;
  gpointer user_id;
  gpointer hotel_id;
  char *hotel_name;
  int hotel_stars;
  double city_tax;
  char *address;
  char *begin_date;
  char *end_date;
  int price_per_night;
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

void build_reservation(char **reservation_params, void *catalog) {
  if (!verify_reservation_input(reservation_params)) return;

  RESERVATION reservation = create_reservation();
  RESERVATIONS_CATALOG reservations_catalog = (RESERVATIONS_CATALOG)catalog;

  set_reservation_id(reservation, reservation_params[0]);
  set_reservation_user_id(reservation, reservation_params[1]);
  set_reservation_hotel_id(reservation, reservation_params[2]);
  set_reservation_hotel_name(reservation, reservation_params[3]);
  set_reservation_hotel_stars(reservation,
                              string_to_int(reservation_params[4]));
  set_reservation_city_tax(reservation, string_to_int(reservation_params[5]));
  set_reservation_address(reservation, reservation_params[6]);
  set_reservation_begin_date(reservation, reservation_params[7]);
  set_reservation_end_date(reservation, reservation_params[8]);
  set_reservation_price_per_night(reservation,
                                  string_to_int(reservation_params[9]));
  set_reservation_include_breakfast(reservation, reservation_params[10]);
  set_reservation_room_details(reservation, reservation_params[11]);
  set_reservation_rating(reservation, string_to_int(reservation_params[12]));

  if (!reservation_params[13])
    set_reservation_comment(reservation, reservation_params[13]);
  add_reservation_to_catalog(reservations_catalog, reservation,
                             reservation->id);
}

void set_reservation_id(RESERVATION reservation, char *id) {
  char *id_without_book = id + 4;
  gpointer id_pointer = id_without_book;
  reservation->id = id_pointer;
}

void set_reservation_user_id(RESERVATION reservation, char *id) {
  gpointer id_pointer = g_strdup(id);
  reservation->user_id = id_pointer;
}

void set_reservation_hotel_id(RESERVATION reservation, char *id) {
  gpointer id_pointer = GINT_TO_POINTER(extract_number(id));
  reservation->hotel_id = id_pointer;
}

void set_reservation_hotel_name(RESERVATION reservation, char *hotel_name) {
  reservation->hotel_name = g_strdup(hotel_name);
}

void set_reservation_hotel_stars(RESERVATION reservation, int stars) {
  reservation->hotel_stars = stars;
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
                                     int price_per_night) {
  reservation->price_per_night = price_per_night;
}

void set_reservation_include_breakfast(RESERVATION reservation,
                                       char *include_breakfast) {
  reservation->include_breakfast = g_strdup(include_breakfast);
}

void set_reservation_room_details(RESERVATION reservation, char *room_details) {
  reservation->room_detail = g_strdup(room_details);
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

int get_id_reservation(RESERVATION reservation) {
  int id = GPOINTER_TO_INT(reservation->id);
  return id;
}

char *get_user_id(RESERVATION reservation) {
  char *id = g_strdup(reservation->user_id);
  return id;
}

int get_hotel_id(RESERVATION reservation) {
  int id = GPOINTER_TO_INT(reservation->hotel_id);
  return id;
}

int get_reservation_id(RESERVATION reservation) {
  int id = GPOINTER_TO_INT(reservation->id);
  return id;
}

char *get_reservation_hotel_name(RESERVATION reservation) {
  char *hotel_name = g_strdup(reservation->hotel_name);
  return hotel_name;
}

int get_reservation_hotel_stars(RESERVATION reservation) {
  int stars = reservation->hotel_stars;
  return stars;
}

double get_reservation_city_tax(RESERVATION reservation) {
  double tax = reservation->city_tax;
  return tax;
}

char *get_reservation_address(RESERVATION reservation) {
  char *address = g_strdup(reservation->address);
  return address;
}

char *get_reservation_begin_date(RESERVATION reservation) {
  char *begin_date = g_strdup(reservation->begin_date);
  return begin_date;
}

char *get_reservation_end_date(RESERVATION reservation) {
  char *end_date = g_strdup(reservation->end_date);
  return end_date;
}

int get_reservation_price_per_night(RESERVATION reservation) {
  int price_per_ninght = reservation->price_per_night;
  return price_per_ninght;
}

char *get_reservation_include_breakfast(RESERVATION reservation) {
  char *include_breakfast = g_strdup(reservation->include_breakfast);
  return include_breakfast;
}

char *get_reservation_room_detail(RESERVATION reservation) {
  char *room_detail = g_strdup(reservation->room_detail);
  return room_detail;
}

int get_reservation_rating(RESERVATION reservation) {
  int rating = reservation->rating;
  return rating;
}

char *get_reservation_comment(RESERVATION reservation) {
  char *comment = g_strdup(reservation->comment);
  return comment;
}
