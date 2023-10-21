#include "entities/flight.h"

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct flight{
    gpointer id;
    char *arline;
    char *plane_model;
    int  total_seats;
    char *origin;
    char *destination;
    char *schedule_departure_date;
    char *schedule_arrival_date;
    char *real_departure_date;
    char *real_arrival_date;
    char *pilot;
    char *copilot;
    char *notes;
};

Flight creat_flight(){ 
    Flight new_flight = g_malloc(sizeof(struct flight));
    new_flight -> id   = NULL;

    return new_flights;
}

void set_flight_id(Flight flight ,char *id){
    int id_int = string_to_int(id);
    gpointer id_pointer = GINT_TO_POINTER(id_int);
    flight->id = id_pointer;
}

void set_flight_airline(Flight flight,char *airline){
    flight -> airline = g_strdup(airline); 
}

void set_flight_planel_model(Flight flight ,char *planel_model){
    flight -> plane_model = g_strdup(planel_model);
}

void set_flight_total_seats(Flight flight ,int total_seats){
    flight -> total_seats = total_seats;
}

void set_flight_origin(Flight flight ,char *origin){
    flight -> origin = g_strdup(origin);
}

void set_flight_schedule_departure_date(Flight flight, char *schedule_departure_date){
    flight -> schedule_departure_date = g_strdup(schedule_departure_date);
}

void set_flight_schedule_arrival_date(Flight flight, char *schedule_arrival_date){
    flight -> schedule_arrival_date = g_strdup(schedule_arrival_date);
}

void set_flight_real_departure_date(Flight flight, char *real_departure_date){
    flight -> real_departure_date = g_strdup(real_departure_date);
}

void set_flight_real_arrival_date(Flight flight, char *real_arrival_date){
    flight -> real_arrival_date = g_strdup(real_arrival_date);
}

void set_flight_pilot(Flight flight, char *pilot){
    flight -> pilot = g_strdup(pilot);
}

void set_flight_copilot(Flight flight, char *copilot){
    flight -> copilot = g_strdup(copilot);
}

void set_flight_note(Flight flight, char *notes){
    flight -> notes = g_strdup(notes);
}

void free_flight(Flight flight){
   g_free(flight -> name);
   g_free(flight -> arline);
   g_free(flight -> plane_model);
   g_free(flight -> origin);
   g_free(flight -> schedule_departure_date);
   g_free(flight -> schedule_arrival_date);
   g_free(flight -> real_departure_date);
   g_free(flight -> real_arrival_date);
   g_free(flight -> pilot);
   g_free(flight -> copilot);
   g_free(flight -> notes);
}
