#include "entities/flights.h"

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct flights{
    gpoint id;
    char *arline;
    char *plane_model;
    int  total_seats;
    char *origin;
    char *destination;
    char *schedule_departure_date;
    char *schedule_arrival_date;
    char +real_departure_date;
    char *real_arrival_date;
    char *pilot;
    char *copilot;
    char *notes;
};
