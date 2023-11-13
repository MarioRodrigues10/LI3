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
 * @param id - The key of the flight to be added to the flights catalog
 */
void add_flight_to_catalog(FLIGHTS_CATALOG flights_catalog, FLIGHT flight,
                           char *id);

/**
 * @brief Function that gets a flight by id from the flights catalog
 *
 * @param catalog - The flights catalog to get the flight from
 *
 * @param id - The id of the flight to be retrieved
 *
 * @return The flight retrieved
 *
 */
FLIGHT get_flight_by_id(FLIGHTS_CATALOG catalog, char *id);

/**
 * @brief Function that frees the memory alocated to the flights catalog
 *
 * @param flights_catalog - The flights catalog to be freed of type
 * 'FLIGHTS_CATALOG'
 */
void free_flights_catalog(FLIGHTS_CATALOG flights_catalog);

#endif