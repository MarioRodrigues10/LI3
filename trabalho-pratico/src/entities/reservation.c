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

int verifyReservationInput(char **parameters) {
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

Reservation createReservation() {
  Reservation new_reservation = g_malloc(sizeof(struct reservation));
  new_reservation->id = NULL;

  return new_reservation;
}

void setReservationId(Reservation reservation, char *id) {
  gpointer id_pointer = id;
  reservation->id = id_pointer;
}

void setReservationUserId(Reservation reservation, char *id) {
  int id_int = string_to_int(id);
  gpointer id_pointer = GINT_TO_POINTER(id_int);
  reservation->user_id = id_pointer;
}

void setReservationHotelId(Reservation reservation, char *id) {
  l int id_int = string_to_int(id);
  gpointer id_pointer = GINT_TO_POINTER(id_int);
  reservation->hotel_id = id_pointer;
}

void setReservationHotelName(Reservation reservation, char *hotel_name) {
  reservation->hotel_name = g_strdup(hotel_name);
}

void setReservationHotelStarts(Reservation reservation, int starts) {
  reservation->hotel_start = starts;
}

void setReservationCityTax(Reservation reservation, int tax) {
  reservation->city_tax = tax;
}

void setReservationAddress(Reservation reservation, char *address) {
  reservation->address = g_strdup(address);
}

void setReservationBeginDate(Reservation reservation, char *begin_date) {
  reservation->begin_date = g_strdup(begin_date);
}

void setReservationEndDate(Reservation reservation, char *end_date) {
  reservation->end_date = g_strdup(end_date);
}

void setReservationPricePerNight(Reservation reservation,
                                 int price_per_ninght) {
  reservation->price_per_ninght = price_per_ninght;
}

void setReservationIncludeBreakfast(Reservation reservation,
                                    char *include_breakfast) {
  reservation->include_breakfast = g_strdup(include_breakfast);
}

void setReservationRoomDetail(Reservation reservation, char *room_detail) {
  reservation->room_detail = g_strdup(room_detail);
}

void setReservationRating(Reservation reservation, int rating) {
  reservation->rating = rating;
}

void setReservationComment(Reservation reservation, char *comment) {
  reservation->comment = g_strdup(comment);
}

void freeReservation(Reservation reservation) {
  g_free(reservation->hotel_name);
  g_free(reservation->address);
  g_free(reservation->begin_date);
  g_free(reservation->end_date);
  g_free(reservation->include_breakfast);
  g_free(reservation->room_detail);
  g_free(reservation->comment);
}

int getUserId(Reservation reservation) {
  int id = GPOINTER_TO_INT(reservation->user_id);
  return id
}

int getHotelId(Reservation reservation) {
  int id = GPOINTER_TO_INT(reservation->hotel_id);
  return id
}

int getReservationId(Reservation reservation) {
  int id = GPOINTER_TO_INT(reservation->id);
  return id
}

char *getReservationHotelName(Reservation reservation) {
  char *hotel_name = strdup(reservation->hotel_name);
  return hotel_name;
}

int getReservationHotelStarts(Reservation reservation) {
  int starts = reservation->hotel_start;
  return starts;
}

double getReservationCityTax(Reservation reservation) {
  double tax = reservation->city_tax;
  return tax;
}

char *getReservationAddress(Reservation reservation) {
  char *address = strdup(reservation->address);
  return address;
}

char *getReservationBeginDate(Reservation reservation) {
  char *begin_date = strdup(reservation->begin_date);
  return begin_date;
}

char *getReservationEndDate(Reservation reservation) {
  char *end_date = strdup(reservation->end_date);
  return end_date;
}

int getReservationPricePerNight(Reservation reservation) {
  int price_per_ninght = reservation->price_per_ninght;
  return price_per_ninght;
}

char *getReservationIncludeBreakfast(Reservation reservation) {
  char *include_breakfast = strdup(reservation->include_breakfast);
  return include_breakfast;
}

char *getReservationRoomDetail(Reservation reservation) {
  char *room_detail = strdup(reservation->room_detail);
  return room_detail;
}

int getReservationRating(Reservation reservation) {
  int rating = reservation->rating;
  return rating;
}

char *getReservationComment(Reservation reservation) {
  char *comment = strdup(reservation->comment);
  return comment;
}
