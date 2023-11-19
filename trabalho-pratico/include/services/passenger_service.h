#ifndef PASSENGER_SERVICE_H
#define PASSENGER_SERVICE_H

#include <stdio.h>

#include "controllers/flight_controller.h"
#include "controllers/passenger_controller.h"
#include "controllers/user_controller.h"
#include "models/passenger.h"
#include "stats/flight_stats.h"
#include "stats/user_stats.h"
#include "utils/validation.h"

/**
 * @brief Verifies if the input is valid.
 *
 * @param parameters Parameters of type 'char**'.
 * @param users_data User data.
 * @param flights_data Flight data.
 *
 * @returns 1 if the input is valid, 0 otherwise.
 */
int verify_passenger_input(char **parameters, UsersData *users_data,
                           FlightsData *flights_data);

/**
 * @brief Constructs a passenger.
 *
 * @param parameters Parameters of type 'char**'.
 * @param users_data User data.
 * @param flights_data Flight data.
 * @param errors_file The file to put wrong lines.
 */
void construct_passenger(char **parameters, UsersData *users_data,
                         FlightsData *flights_data, FILE *errors_file);

#endif
