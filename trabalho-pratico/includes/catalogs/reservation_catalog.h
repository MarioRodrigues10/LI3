#ifndef RESERVATIONS_CATALOG_H
#define RESERVATIONS_CATALOG_H

typedef struct reservations_catalog *Reservation_Catalog;

typedef struct reservations *Reservation;

/**
 * @brief Create the reservations catalog
 */
Reservation_Catalog create_reservations_catalog();

/**
 * @brief Free the memory alocated to the reservations catalog
 *
 * @param reservation_catalog  - The reservations catalog to be free
 */
void free_reservations_catalog(Reservation_Catalog catalog);
#endif