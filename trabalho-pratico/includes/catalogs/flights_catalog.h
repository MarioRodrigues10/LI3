#ifndef FLIGHTS_CATOLOG_H
#define FLIGHTS_CATALOG_H

#include "entities/flights.h"

typedef struct flights_catalog *FlIGHTS_CATALOG;

typedef struct flight *FLIGHT;

/**
 * @brief Create the flights catalog
 */
FlIGHTS_CATALOG create_flights_catalog();

/**
 * @brief Free the memory alocated to the flights catalog
 *
 * @param flights_catalog  - The flights catalog to be freed
 */
void free_flights_catalog(FlIGHTS_CATALOG flights_catalog);

#endif