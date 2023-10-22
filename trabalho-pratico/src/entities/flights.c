#include "../includes/entities/flights.h"

#include <stdio.h>
#include <stdlib.h>

struct flight {
  long long int id;
  char airline[MAX_FIELD_SIZE];
  char plane_model[MAX_FIELD_SIZE];
  int total_seats;
  char origin[MAX_FIELD_SIZE];
  char destination[MAX_FIELD_SIZE];
  char schedule_departure_date[MAX_FIELD_SIZE];
  char schedule_arrival_date[MAX_FIELD_SIZE];
  char real_departure_date[MAX_FIELD_SIZE];
  char real_arrival_date[MAX_FIELD_SIZE];
  char pilot[MAX_FIELD_SIZE];
  char copilot[MAX_FIELD_SIZE];
  char notes[MAX_FIELD_SIZE];
  struct Flight* next;
};