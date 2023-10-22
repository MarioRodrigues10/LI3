#ifndef PASSENGER_CATALOG_H
#define PASSENGER_CATALOG_H


typedef struct passenger_catalog *Passenger_Catalog;
typedef struct passenger *Passenger;

/**
 * @brief Create the passenger catalog
*/
Passenger_Catalog create_passenger_catalog();

/**
 * @brief Free the memory alocated to the passenger catalog
 * 
 * @param passenger_catalog  - The passenger catalog to be free
 */
void free_passenger_catalog(Passenger_Catalog passenger_catalog);

#endif