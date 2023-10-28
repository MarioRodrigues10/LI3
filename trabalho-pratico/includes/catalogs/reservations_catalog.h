#ifndef RESERVATIONS_CATALOG_H
#define RESERVATIONS_CATALOG_H

#include "entities/reservations.h"

typedef struct reservations_catalog *RESERVATIONS_CATALOG;

/**
 * @brief Function that creates the reservations catalog
 *
 * @return The reservations catalog created
 */
RESERVATIONS_CATALOG create_reservations_catalog();

/**
 * @brief Function that frees the memory alocated to the reservations catalog
 *
 * @param reservation_catalog  - The reservations catalog to be freed of type
 * 'RESERVATIONS_CATALOG'
 */
void free_reservations_catalog(RESERVATIONS_CATALOG reservations_catalog);

#endif