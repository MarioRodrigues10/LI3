#include "../includes/entities/passengers.h"

#include <stdio.h>
#include <stdlib.h>

struct passenger {
  long long int flight_id;
  char user_id[MAX_FIELD_SIZE];
};