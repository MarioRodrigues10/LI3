#ifndef PASSENGER_CONTROLLER_H
#define PASSENGER_CONTROLLER_H

#include "models/passenger.h"

typedef struct passengers_data PassengersData;

/**
 * @brief Allocates the memory necessary to create a new PassengersData struct
 * and generates the hastable.
 *
 * @return PassengersData pointer of type 'PassengersData*' to the allocated
 * memory.
 */
PassengersData *passengers_data_new();

/**
 * @brief Adds a passenger to the hastable.
 *
 * @param passengers_data Pointer to the PassengersData struct.
 * @param passenger Pointer to the PassengerInfo struct.
 */
void add_passenger(PassengersData *passengers_data, PassengerInfo *passenger);

/**
 * @brief Frees the memory allocated to the PassengersData struct.
 *
 * @param passengers_data Pointer to the PassengersData struct.
 */
void passengers_data_free(PassengersData *passengers_data);

/**
 * @brief Gets a passenger from the hastable by its passenger id.
 *
 * @param passengers_data Pointer to the PassengersData struct.
 * @param passenger_id Pointer to the passenger id.
 * @return PassengerInfo pointer of type 'PassengerInfo*' to the passenger.
 */
PassengerInfo *get_passenger_by_passenger_id(PassengersData *passengers_data,
                                             char *passenger_id);

#endif
