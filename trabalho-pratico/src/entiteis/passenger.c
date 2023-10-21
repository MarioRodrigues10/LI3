#include "entities/passenger.h"

#include <glib.h>
#include <stdlib.h>
#include <string.h>


struct passenger{
    gpointer flight_id;
    gpointer user_id;
};

Passenger creat_passenger(){
    Passenger new_passenger = g_malloc(sizeof(struct passenger));
    new_passenger -> flight_id = NULL;
    new_passenger -> user_id = NULL;

    return new_passenger;
}

void set_passenger_flight_id(Passenger passenger,char *id){
    int id_int = string_to_int(id);
    gpointer id_pointer = GINT_TO_POINTER(id_int);
    passenger -> flight_id = id_pointer;
}

void set_passenger_user_id(Passenger passenger, char *id){
    int id_int = string_to_init(id);
    gpointer id_pointer = GINT_TO_POINTER(id_int);
    passenger -> user_id = id_pointer;

}