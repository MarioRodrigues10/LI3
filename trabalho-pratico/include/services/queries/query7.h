#ifndef QUERY7_H
#define QUERY7_H

#include <stdbool.h>
#include <stdio.h>

#include "controllers/flight_controller.h"
#include "models/flight.h"
#include "services/flight_service.h"

/**
 * @struct query7_result - Struct that represents the result of query 7 to be
 * used in other places of the program
 */
typedef struct query7_result *QUERY7_RESULT;

/**
 * @brief Writes the query7 output to the output file.
 *
 * @param has_f Whether the output should be formatted or not.
 * @param output_file The output file.
 * @param aiport The aiport.
 * @param delays The delays.
 * @param N The length of the array.
 */
void write_query7(bool has_f, FILE *output_file, char **aiport, int *delays,
                  int N);

/**
 * @brief Queries the data structs.
 *
 * @param has_f If the query has the modifier 'F'.
 * @param line The line with the quey parameters.
 * @param flights_data The flights data struct.
 * @param output_file The pointer to the output file.
 */
void query7(bool has_f, char **query_parameters, FlightsData *flights_data,
            FILE *output_file);

#endif
