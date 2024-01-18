#ifndef QUERIES_SERVICE_H
#define QUERIES_SERVICE_H

#include <stdbool.h>
#include <stdio.h>

#include "controllers/flight_controller.h"
#include "controllers/general_controller.h"
#include "controllers/passenger_controller.h"
#include "controllers/reservation_controller.h"
#include "controllers/user_controller.h"
#include "stats/user_stats.h"
#include "utils/maping.h"
#include "utils/utils.h"

/**
 * @brief Manages the queries.
 *
 * @param line The line with the quey parameters.
 * @param flights_data The flights data struct.
 * @param reservations_data The reservations data struct.
 * @param general_data The general data struct.
 * @param users_data The users data struct.
 * @param users_stats The users stats struct.
 * @param map The maping struct.
 * @param output_file The pointer to the output file.
 */
void query_manager(char *line, FlightsData *flights_data,
                   ReservationsData *reservations_data,
                   GeneralData *general_data, UsersData *users_data,
                   StatsUserInfo *users_stats, Maping *map, FILE *output_file);

/**
 * @brief Manages the queries test.
 *
 * @param line The line with the quey parameters.
 * @param flights_data The flights data struct.
 * @param reservations_data The reservations data struct.
 * @param general_data The general data struct.
 * @param users_data The users data struct.
 * @param users_stats The users stats struct.
 * @param map The maping struct.
 * @param output_file The pointer to the output file.
 * @param output_file_expected The pointer to the output file expected.
 */
void query_manager_test(char *line, FlightsData *flights_data,
                        ReservationsData *reservations_data,
                        GeneralData *general_data, UsersData *users_data,
                        StatsUserInfo *users_stats, Maping *map,
                        FILE *output_file, FILE *output_file_expected);

#endif
