#include "../includes/entities/reservations.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_FIELD_SIZE 256

struct reservation {
  char id[MAX_FIELD_SIZE];
  char user_id[MAX_FIELD_SIZE];
  char hotel_id[MAX_FIELD_SIZE];
  char hotel_name[MAX_FIELD_SIZE];
  int hotel_stars;
  double city_tax;
  char address[MAX_FIELD_SIZE];
  char begin_date[MAX_FIELD_SIZE];
  char end_date[MAX_FIELD_SIZE];
  int price_per_night;
  int includes_breakfast;
  char room_details[MAX_FIELD_SIZE];
  int rating;
  char comment[MAX_FIELD_SIZE];
  struct Reservation* next;
};
