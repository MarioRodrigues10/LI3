#ifndef FLIGHT_CATOLOG_H
#define FLIGHT_CATALOG_H


typedef struct flight_catalog *Flight_Catalog;

typedef struct flight *Flight;

/**
 * @brief Create the flight catalog  
 */
Flight_Catalog create_flight_catalog(void);

/**
 * @brief Free the memory alocated to the flight catalog
 * 
 * @param flight_catalog  - The flight catalog to be freed
 */
void free_flight_catalog(Flight_Catalog flight_catalog);

#endif