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


Reservation creat_reservation(){
    Reservation new_reservation = g_malloc(sizeof(struct reservation));
    new_reservation -> id = NULL;

    return new_reservation;
}

void set_reservation_id(Reservation reservation, char *id){
    gpointer id_pointer = id; 
    reservation -> id = id_pointer;
}

void set_reservation_user_id(Reservation reservation, char *id){
    int id_int = string_to_int(id);
    gpointer id_pointer = GINT_TO_POINTER(id_int);
    reservation-> user_id = id_pointer;   
}

void set_reservation_hotel_id(Reservation reservation,char *id){l
    int id_int = string_to_int(id);
    gpointer id_pointer = GINT_TO_POINTER(id_int);
    reservation -> hotel_id = id_pointer;
}

void set_reservation_hotel_name(Reservation reservation ,char *hotel_name){
    reservation -> hotel_name = g_strdup(hotel_name);
}

void set_reservation_hotel_starts(Reservation reservation ,int starts){
    reservation -> hotel_start = starts;
}

void set_reservation_city_tax(Reservation reservation, int tax){
    reservation -> city_tax = tax;
}

void set_reservation_address(Reservation reservation, char *address){
    reservation -> address = g_strdup(address);
}

void set_reservation_begin_date(Reservation reservation, char *begin_date){
    reservation ->begin_date = g_strdup(begin_date);
}

void set_reservation_end_date(Reservation reservation, char *end_date){
    reservation ->end_date = g_strdup(end_date);
}

void set_reservation_price_per_night(Reservation reservation, int price_per_ninght){
    reservation -> price_per_ninght = price_per_ninght;
}

void set_reservation_include_breakfast(Reservation reservation, char *include_breakfast){
    reservation -> include_breakfast = g_strdup(include_breakfast);
}

void set_reservation_room_detail(Reservation reservation,char *room_detail){
    reservation -> room_detail = g_strdup(room_detail);
}

void set_reservation_rating(Reservation reservation,int rating){
    reservation -> rating = rating;
}

void set_reservation_comment(Reservation reservation, char *comment){
    reservation -> comment = g_strdup(comment);
}

void free_reservation(Reservation reservation){
    g_free(reservation -> hotel_name);
    g_free(reservation -> address);
    g_free(reservation -> begin_date);
    g_free(reservation -> end_date);
    g_free(reservation -> include_breakfast);
    g_free(reservation -> room_detail);
    g_free(reservation -> comment);
}