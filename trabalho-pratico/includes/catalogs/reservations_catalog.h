#ifndef RESERVATIONS_CATALOG_H
#define RESERVATIONS_CATALOG_H

#include "entities/reservations.h"

typedef struct reservations_catalog *RESERVATIONS_CATALOG;

/**
 * @brief Create the reservations catalog
 */
RESERVATIONS_CATALOG create_reservations_catalog();

/**
 * @brief Free the memory alocated to the reservations catalog
 *
 * @param reservation_catalog  - The reservations catalog to be free
 */
void free_reservations_catalog(RESERVATIONS_CATALOG reservations_catalog);
#endif