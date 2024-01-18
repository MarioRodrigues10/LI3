#ifndef QUERY8_H
#define QUERY8_H

#include <stdbool.h>
#include <stdio.h>

#include "controllers/reservation_controller.h"
#include "models/reservation.h"
#include "services/reservation_service.h"

/**
 * @brief Writes the query8 output to the output file.
 *
 * @param has_f Whether the output should be formatted or not.
 * @param output_file The output file.
 * @param revenue The revenue.
 */
void write_query8(bool has_f, FILE *output_file, double revenue);

/**
 * @brief Queries the data structs.
 *
 * @param has_f If the query has the modifier 'F'.
 * @param line The line with the quey parameters.
 * @param reservations_data The reservations data struct.
 * @param output_file The pointer to the output file.
 */
void query8(bool has_f, char **query_parameters,
            ReservationsData *reservations_data, FILE *output_file);

#endif
