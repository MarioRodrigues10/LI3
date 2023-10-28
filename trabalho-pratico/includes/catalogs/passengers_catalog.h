#ifndef PASSENGERS_CATALOG_H
#define PASSENGERS_CATALOG_H

#include "entities/passengers.h"

typedef struct passengers_catalog *PASSENGERS_CATALOG;
typedef struct passenger *PASSENGER;

/**
 * @brief Function that creates the passengers catalog
 *
 * @return The passengers catalog created
 */
PASSENGERS_CATALOG create_passengers_catalog();

/**
 * @brief Function that frees the memory alocated to the passengers catalog
 *
 * @param passengers_catalog  - The passengers catalog to be freed of type
 * 'PASSENGERS_CATALOG'
 */
void free_passengers_catalog(PASSENGERS_CATALOG passengers_catalog);

#endif