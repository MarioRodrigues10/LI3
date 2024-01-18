#ifndef QUERY5_H
#define QUERY5_H

#include <stdbool.h>
#include <stdio.h>

#include "controllers/flight_controller.h"
#include "models/flight.h"
#include "services/flight_service.h"
#include "utils/maping.h"
#include "utils/utils.h"

/**
 * @struct query5_result - Struct that represents the result of query 5 to be
 * used in other places of the program
 */
typedef struct query5_result *QUERY5_RESULT;

/**
 * @struct query5_result_helper - Struct that represents the result of query 5
 * to be used in other places of the program
 */
typedef struct query5_result_helper *QUERY5_RESULT_HELPER;

/**
 * @brief Queries the data structs.
 *
 * @param has_f If the query has the modifier 'F'.
 * @param line The line with the quey parameters.
 * @param flights_data The flights data struct.
 * @param Maping* The maping struct.
 * @param output_file The pointer to the output file.
 */
void query5(bool has_f, char **query_parameters, FlightsData *flights_data,
            Maping *map, FILE *output_file);

#endif
