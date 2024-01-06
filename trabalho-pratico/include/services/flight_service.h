#ifndef FLIGHT_SERVICE_H
#define FLIGHT_SERVICE_H

#include <stdio.h>

#include "controllers/flight_controller.h"
#include "controllers/general_controller.h"
#include "models/flight.h"
#include "utils/validation.h"

/**
 * @brief Verifies if the input is valid.
 *
 * @param parameters Parameters of type 'char**'.
 *
 * @returns 1 if the input is valid, 0 otherwise.
 *
 */
int verify_flight_input(char **parameters);

/**
 * @brief Constructs a flight.
 *
 * @param parameters Parameters of type 'char**'.
 * @param flights_data Struct data of type 'void*'.
 * @param errors_file The file to put the wrong lines.
 */
void construct_flight(char **parameters, void *struct_data, void *general_data,
                      FILE *errors_file);

#endif
