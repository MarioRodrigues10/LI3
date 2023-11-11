#ifndef PASSENGERS_H
#define PASSENGERS_H

#define MAX_FIELD_SIZE 256
#define MAX_TOKENS_PASSENGER 2

#include "catalogs/passengers_catalog.h"

typedef struct passenger *PASSENGER;

/**
 * @brief Function that creates the passenger
 *
 * @return new_passenger - The new user of type 'PASSENGER'
 */
PASSENGER create_passenger();

/**
 * @brief Function that builds the passenger
 *
 * @param passenger_params - The passenger parameters of type 'char*'
 * @param catalog - The catalog of type 'void*'
 *
 */
void build_passenger(char **passenger_params, void *catalog);

/**
 * @brief Function that verifies if the parameters are valid to create a new
 * passenger (paramenters : flight_id, user_id)
 *
 * @param parameters - The parameters of type 'char**'
 *
 * @return 0 if the parameters are valid, 1 otherwise
 */
int verify_passenger_input(char **parameters);

/**
 * @brief Function that sets the passenger flight id
 *
 * @param passengers - The passenger type 'PASSENGER'
 *
 *@param id - The flight id string of type 'char*'
 */
void set_passenger_flight_id(PASSENGER passenger, char *id);

/**
 * @brief Function that sets the passenger user id
 *
 * @param passengers - The passenger type 'PASSENGER'
 *
 *@param id - The user id string of type 'char*'
 */
void set_passenger_user_id(PASSENGER passenger, char *id);

/**
 * @brief Function that frees the memory allocated to store a passenger
 *
 * @param passenger - The passenger of type 'PASSENGER'
 */
void free_passenger(PASSENGER passenger);

/**
 * @brief Function that gets the paflight id
 *
 * @param passenger - The passenger of type 'PASSENGER'
 *
 * @return id - The flight id of type 'int'
 */
char *get_passenger_flight_id(PASSENGER passenger);

/**
 * @brief Function that gets the passenger user id
 *
 * @param passenger - The passenger of type 'PASSENGER'
 *
 * @return id - The user id of type 'int'
 */
char *get_passenger_user_id(PASSENGER passenger);

#endif