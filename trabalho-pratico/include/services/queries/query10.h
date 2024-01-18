#ifndef QUERY10_H
#define QUERY10_H

#include <stdbool.h>
#include <stdio.h>

#include "controllers/general_controller.h"
#include "utils/utils.h"

/**
 * @brief Writes the query10 output to the output file.
 *
 * @param has_f Whether the output should be formatted or not.
 * @param output_file The output file.
 * @param date The date.
 * @param number_users The number of users.
 * @param number_flights The number of flights.
 * @param number_passengers The number of passengers.
 * @param number_unique_passengers The number of unique passengers.
 * @param number_reservations The number of reservations.
 * @param flag The flag.
 * @param N The length of the array.
 */
void write_query10(bool has_f, FILE *output_file, int *date, int *number_users,
                   int *number_flights, int *number_passengers,
                   int *number_unique_passengers, int *number_reservations,
                   char *flag, int N);

/**
 * @brief Queries the data structs.
 *
 * @param has_f If the query has the modifier 'F'.
 * @param line The line with the quey parameters.
 * @param num_parameters The number of parameters.
 * @param general_data The general data struct.
 * @param output_file The pointer to the output file.
 */
void query10(bool has_f, char **query_parameters, int num_parameters,
             GeneralData *general_data, FILE *output_file);

#endif
