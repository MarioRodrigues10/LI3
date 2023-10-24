#ifndef FLIGHTS_CATOLOG_H
#define FLIGHTS_CATALOG_H

#include "entities/flight.h"

typedef struct flights_catalog *FlIGHTS_CATALOG;

typedef struct flight *FLIGHT;

/**
 * @brief Create the flight catalog
 */
 FlIGHTS_CATALOG create_flights_catalog();

/**
 * @brief Free the memory alocated to the flight catalog
 *
 * @param flight_catalog  - The flight catalog to be freed
 */
void free_flight_catalog(FlIGHTS_CATALOG flights_catalog);

#endif