#ifndef PASSENGERS_CATALOG_H
#define PASSENGERS_CATALOG_H

#include "entities/passenger.h"

typedef struct passenger_catalog *PASSENGERS_CATALOG;
typedef struct passenger *PASSENGER;

/**
 * @brief Create the passenger catalog
 */
PASSENGERS_CATALOG create_passengers_catalog();

/**
 * @brief Free the memory alocated to the passenger catalog
 *
 * @param passenger_catalog  - The passenger catalog to be free
 */
void free_passengesrs_catalog(PASSENGERS_CATALOG passenger_catalog);

#endif