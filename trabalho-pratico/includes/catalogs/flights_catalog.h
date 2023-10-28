#ifndef FLIGHTS_CATOLOG_H
#define FLIGHTS_CATALOG_H

#include "entities/flights.h"

typedef struct flights_catalog *FlIGHTS_CATALOG;

/**
 * @brief Function that creates the flights catalog
 *
 * @return The flights catalog created
 */
FlIGHTS_CATALOG create_flights_catalog();

/**
 * @brief Function that frees the memory alocated to the flights catalog
 *
 * @param flights_catalog - The flights catalog to be freed of type
 * 'FlIGHTS_CATALOG'
 */
void free_flights_catalog(FlIGHTS_CATALOG flights_catalog);

#endif