#ifndef RESERVATIONS_CATALOG_H
#define RESERVATIONS_CATALOG_H


typedef struct reservations_catalog *Reservation_Catalog;

typedef struct reservations *Reservation;

// Create the catalog for the reservations.
Reservation_Catalog creat_reservations_catalog();

#endif