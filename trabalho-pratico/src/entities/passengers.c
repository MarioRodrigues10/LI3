#include "../includes/entities/passengers.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_FIELD_SIZE 256

struct passenger {
  long long int flight_id;
  char user_id[MAX_FIELD_SIZE];
  struct Passenger* next;
};