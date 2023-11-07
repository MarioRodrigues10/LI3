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
 * @brief Function that adds a flight to the flights catalog
 *
 * @param flights_catalog - The flights catalog to add the flight to
 * @param flight - The flight to be added to the flights catalog
 * @param key - The key of the flight to be added to the flights catalog
 */
void add_flight_to_catalog(FlIGHTS_CATALOG flights_catalog, FLIGHT flight,
                           gpointer key);
/**
 * @brief Function that frees the memory alocated to the flights catalog
 *
 * @param flights_catalog - The flights catalog to be freed of type
 * 'FlIGHTS_CATALOG'
 */
void free_flights_catalog(FlIGHTS_CATALOG flights_catalog);

#endif