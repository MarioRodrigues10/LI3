#ifndef INPUT_HANDLER_CONTROLLER_H
#define INPUT_HANDLER_CONTROLLER_H

#include <stdio.h>

#include "controllers/flight_controller.h"
#include "controllers/passenger_controller.h"
#include "controllers/reservation_controller.h"
#include "controllers/user_controller.h"
#include "services/feeder_service.h"
#include "services/queries_service.h"

/**
 * @brief Creates a directory.
 *
 * @param folder The name of the directory to be created.
 *
 * @return 0 if the directory was created successfully, 1 otherwise.
 */
int create_directory(const char* folder);

/**
 * @brief Creates an output file.
 *
 * @param queries_counter The number of the query being executed.
 *
 * @return The output file.
 */
FILE* create_output_file(int queries_counter);

/**
 * @brief Handles the input from the user.
 *
 * @param argv The arguments passed to the program.
 *
 * @return 0 if the program should continue running, 1 if it should stop.
 */
int input_handler(char** argv);

#endif
