#include "entities/passengers.h"

#include <glib.h>
#include <stdlib.h>
#include <string.h>


struct passengers{
    gpointer flight_id;
    gpointer user_id;
};

PASSENGERS creat_passengers(){
    PASSENGERS new_passengers = g_malloc(sizeof(struct passengers));
    new_passengers -> flight_id = NULL;
    new_passengers -> user_id = NULL;

    return new_passengers;
}

void set_passengers_flight_id(PASSENGERS passengers,char *id){
    int id_int = string_to_int(id);
    gpointer id_pointer = GINT_TO_POINTER(id_int);
    passengers -> flight_id = id_pointer;
}

void set_passengers_user_id(PASSENGERS passengers, char *id){
    int id_int = string_to_init(id);
    gpointer id_pointer = GINT_TO_POINTER(id_int);
    passengers -> user_id = id_pointer;

}