#ifndef QUERY6_H
#define QUERY6_H

#include <stdbool.h>
#include <stdio.h>

#include "controllers/flight_controller.h"
#include "models/flight.h"
#include "services/flight_service.h"
#include "stats/airport_stats.h"

/**
 * @struct query6_result - Struct that represents the result of query 6 to be
 * used in other places of the program
 */
typedef struct query6_result *QUERY6_RESULT;

/**
 * @brief Writes the query6 output to the output file.
 *
 * @param has_f Whether the output should be formatted or not.
 * @param output_file The output file.
 * @param airport_info The airport info.
 * @param number_of_passengers The number of passengers.
 * @param N The length of the array.
 */
void write_query6(bool has_f, FILE *output_file, char **airport_info,
                  int *number_of_passengers, int N);

/**
 * @brief Queries the data structs.
 *
 * @param has_f If the query has the modifier 'F'.
 * @param line The line with the quey parameters.
 * @param flights_data The flights data struct.
 * @param output_file The pointer to the output file.
 */
void query6(bool has_f, char **query_parameters, FlightsData *flights_data,
            FILE *output_file);

#endif
