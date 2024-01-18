#ifndef QUERY2_H
#define QUERY2_H

#include <stdbool.h>
#include <stdio.h>

#include "controllers/flight_controller.h"
#include "controllers/reservation_controller.h"
#include "controllers/user_controller.h"
#include "models/flight.h"
#include "models/reservation.h"
#include "models/user.h"
#include "services/flight_service.h"
#include "services/reservation_service.h"
#include "services/user_service.h"
#include "stats/user_stats.h"

/**
 * @struct query2_result - Struct that represents the result of query 2 to be
 * used in other places of the program
 */
typedef struct query2_result *QUERY2_RESULT;

/**
 * @brief Function that compares two results.
 *
 * @param a The first string of type 'const void*'
 * @param b The second string of type 'const void*'
 *
 * @return The result of the check of type 'int'
 */
int compare_query2_result(const void *a, const void *b);

/**
 * @brief Function that sorts the flights by date.
 *
 * @param result The result of the query of type 'void*'
 * @param N The number of flights of type 'int'
 */
void sort_by_date(void *result, int N);

/**
 * @struct query2_result_helper - Struct that represents the result of query 2
 * to be used in other places of the program
 */
typedef struct query2_result_helper *QUERY2_RESULT_HELPER;

/**
 * @brief Writes the query2 output to file
 *
 * @param has_f Wheter the output should be formatted or not
 * @param output_file The output file
 * @param query_result_array The query result array
 */
void write_query2(bool has_f, FILE *output_file, GArray *query_result_array);

/**
 * @brief Queries the data structs.
 *
 * @param has_f If the query has the modifier 'F'.
 * @param line The line with the quey parameters.
 * @param flights_data The flights data struct.
 * @param reservations_data The reservations data struct.
 * @param users_data The users data struct.
 * @param output_file The pointer to the output file.
 * @param N The number of parameters.
 */
void query2(bool has_f, char **query_parameters, FlightsData *flights_data,
            ReservationsData *reservations_data, UsersData *users_data,
            FILE *output_file, int N);

/**
 * @brief Query2 helper function for reservations.
 *
 * @param reservations_data The reservations data struct.
 * @param type The type of the reservation.
 * @param array The array to fetch the data.
 * @param output_array The array to output the data.
 * @param len The length of the array.
 */
void query2_seed_flights(FlightsData *flights_data, char *type, GArray *array,
                         GArray *output_array, int len);

/**
 * @brief Query2 helper function for flights.
 *
 * @param flights_data The flights data struct.
 * @param type The type of the reservation.
 * @param array The array to fetch the data.
 * @param output_array The array to output the data.
 * @param len The length of the array.
 */
void query2_seed_reservations(ReservationsData *reservations_data, char *type,
                              GArray *array, GArray *output_array, int len);
/**
 * @brief Query2 helper function to free the memory.
 *
 * @param result The result of the query.
 * @param len The length of the array.
 */
void free_query2(void *result, int len);

/**
 * @brief Query flights helper function.
 *
 * @param has_f If the query has the modifier 'F'.
 * @param user_stats The user stats struct.
 * @param flights_data The flights data struct.
 * @param output_file The pointer to the output file.
 */
void query2_flights(bool has_f, UserStats *user_stats,
                    FlightsData *flights_data, FILE *output_file);

/**
 * @brief Query reservations helper function.
 *
 * @param has_f If the query has the modifier 'F'.
 * @param user_stats The user stats struct.
 * @param reservations_data The reservations data struct.
 * @param output_file The pointer to the output file.
 */
void query2_reservations(bool has_f, UserStats *user_stats,
                         ReservationsData *reservations_data,
                         FILE *output_file);

/**
 * @brief Query both helper function.
 *
 * @param has_f If the query has the modifier 'F'.
 * @param user_stats The user stats struct.
 * @param flights_data The flights data struct.
 * @param reservations_data The reservations data struct.
 * @param output_file The pointer to the output file.
 */
void query2_both(bool has_f, UserStats *user_stats, FlightsData *flights_data,
                 ReservationsData *reservations_data, FILE *output_file);

#endif
