#ifndef QUERY4_H
#define QUERY4_H

#include <stdbool.h>
#include <stdio.h>

#include "controllers/reservation_controller.h"
#include "models/reservation.h"
#include "services/reservation_service.h"

/**
 * @struct query4_result - Struct that represents the result of query 4 to be
 * used in other places of the program
 */
typedef struct query4_result *QUERY4_RESULT;

/**
 * @struct query4_result_helper - Struct that represents the result of query 4
 * to be used in other places of the program
 */
typedef struct query4_result_helper *QUERY4_RESULT_HELPER;

/**
 * @brief Writes the query4 output to the output file.
 *
 * @param has_f Whether the output should be formatted or not.
 * @param output_file The output file.
 * @param query_result The query result.
 */
void write_query4(bool has_f, FILE *output_file, GArray *query_result);

/**
 * @brief Function that compares two dates.
 *
 * @param query4_content The content of the query4 of type 'void*'
 * @param N The number of reservations of type 'int'
 */
void sort_by_date_and_value(void *query4_content, int N);

/**
 * @brief Queries the data structs.
 *
 * @param has_f If the query has the modifier 'F'.
 * @param line The line with the quey parameters.
 * @param flights_data The flights data struct.
 * @param passengers_data The passengers data struct.
 * @param reservations_data The reservations data struct.
 * @param users_data The users data struct.
 * @param output_file The pointer to the output file.
 */
void query4(bool has_f, char **query_parameters,
            ReservationsData *reservations_data, FILE *output_file);

#endif
