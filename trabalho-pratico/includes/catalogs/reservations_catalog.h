#ifndef RESERVATIONS_CATALOG_H
#define RESERVATIONS_CATALOG_H

#include <glib.h>

#include "entities/reservations.h"

typedef struct reservations_catalog *RESERVATIONS_CATALOG;

/**
 * @brief Function that creates the reservations catalog
 *
 * @return The reservations catalog created
 */
RESERVATIONS_CATALOG create_reservations_catalog();

/**
 * @brief Function that adds a reservation to the reservations catalog
 *
 * @param reservations_catalog - The reservations catalog to add the reservation
 * to
 * @param reservation - The reservation to be added to the reservations catalog
 * @param key - The key of the reservation to be added to the reservations
 * catalog
 */
void add_reservation_to_catalog(RESERVATIONS_CATALOG reservations_catalog,
                                RESERVATION reservation, gpointer key);

/**
 * @brief Function that frees the memory alocated to the reservations catalog
 *
 * @param reservation_catalog  - The reservations catalog to be freed of type
 * 'RESERVATIONS_CATALOG'
 */
void free_reservations_catalog(RESERVATIONS_CATALOG reservations_catalog);

#endif