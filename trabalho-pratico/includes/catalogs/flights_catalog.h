#ifndef FLIGHTS_CATALOG_H
#define FLIGHTS_CATALOG_H

#include "entities/flights.h"

typedef struct flights_catalog *FLIGHTS_CATALOG;
typedef struct flight *FLIGHT;

/**
 * @brief Function that creates the flights catalog
 *
 * @return The flights catalog created
 */
FLIGHTS_CATALOG create_flights_catalog();

/**
 * @brief Function that adds a flight to the flights catalog
 *
 * @param flights_catalog - The flights catalog to add the flight to
 * @param flight - The flight to be added to the flights catalog
 * @param key - The key of the flight to be added to the flights catalog
 */
void add_flight_to_catalog(FLIGHTS_CATALOG flights_catalog, FLIGHT flight,
                           void *key);
/**
 * @brief Function that frees the memory alocated to the flights catalog
 *
 * @param flights_catalog - The flights catalog to be freed of type
 * 'FLIGHTS_CATALOG'
 */
void free_flights_catalog(FLIGHTS_CATALOG flights_catalog);

#endif