#include "entities/reservations.h"

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct reservations {
    gpointer *id;
    gpointer *user_id;
    gpointer *hotel_id;
    char *hotel_name;
    int hotel_starts;
    double city_tax;
    char *adress;
    char *begin_date;
    char *end_date;
    int price_per_ninght;
    int include_breakfast;
    char *room_details;
    int rating;
    char *comment;
};

