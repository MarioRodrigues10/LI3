#ifndef PASSENGERS_CATALOG_H
#define PASSENGERS_CATALOG_H

#include "entities/passengers.h"

typedef struct passengers_catalog *PASSENGERS_CATALOG;
typedef struct passenger *PASSENGER;

/**
 * @brief Create the passenger catalog
 */
PASSENGERS_CATALOG create_passengers_catalog();

/**
 * @brief Free the memory alocated to the passengers catalog
 *
 * @param passengers_catalog  - The passengers catalog to be free
 */
void free_passengers_catalog(PASSENGERS_CATALOG passengers_catalog);

#endif