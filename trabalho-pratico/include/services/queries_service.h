#ifndef QUERIES_SERVICE_H
#define QUERIES_SERVICE_H

#include <stdbool.h>
#include <stdio.h>

#include "controllers/flight_controller.h"
#include "controllers/general_controller.h"
#include "controllers/passenger_controller.h"
#include "controllers/reservation_controller.h"
#include "controllers/user_controller.h"
#include "models/flight.h"
#include "models/passenger.h"
#include "models/reservation.h"
#include "models/user.h"
#include "services/flight_service.h"
#include "services/passenger_service.h"
#include "services/reservation_service.h"
#include "services/user_service.h"
#include "stats/user_stats.h"
#include "utils/maping.h"
#include "utils/output-handler.h"
#include "utils/utils.h"

/**
 * @struct query2_result - Struct that represents the result of query 2 to be
 * used in other places of the program
 */
typedef struct query2_result *QUERY2_RESULT;

/**
 * @struct query2_result_helper - Struct that represents the result of query 2
 * to be used in other places of the program
 */
typedef struct query2_result_helper *QUERY2_RESULT_HELPER;

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
 * @struct query7_result - Struct that represents the result of query 7 to be
 * used in other places of the program
 */
typedef struct query7_result *QUERY7_RESULT;

/**
 * @brief Queries the data structs.
 *
 * @param has_f If the query has the modifier 'F'.
 * @param line The line with the quey parameters.
 * @param flights_data The flights data struct.
 * @param reservations_data The reservations data struct.
 * @param users_data The users data struct.
 * @param map The maping struct.
 * @param output_file The pointer to the output file.
 */
void query1(bool has_f, char **query_parameters, FlightsData *flights_data,
            ReservationsData *reservations_data, UsersData *users_data,
            Maping *map, FILE *output_file);

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

/**
 * @brief Queries the data structs.
 *
 * @param has_f If the query has the modifier 'F'.
 * @param line The line with the quey parameters.
 * @param reservations_data The reservations data struct.
 * @param output_file The pointer to the output file.
 * @param mode The mode of the program.
 */
void query3(bool has_f, char **query_parameters,
            ReservationsData *reservations_data, FILE *output_file);

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
 * @param mode The mode of the program.
 */
void query4(bool has_f, char **query_parameters,
            ReservationsData *reservations_data, FILE *output_file);

/**
 * @brief Queries the data structs.
 *
 * @param has_f If the query has the modifier 'F'.
 * @param line The line with the quey parameters.
 * @param flights_data The flights data struct.
 * @param Maping* The maping struct.
 * @param output_file The pointer to the output file.
 * @param mode The mode of the program.
 */
void query5(bool has_f, char **query_parameters, FlightsData *flights_data,
            Maping *map, FILE *output_file);

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

/**
 * @brief Queries the data structs.
 *
 * @param has_f If the query has the modifier 'F'.
 * @param line The line with the quey parameters.
 * @param reservations_data The reservations data struct.
 * @param output_file The pointer to the output file.
 * @param mode The mode of the program.
 */
void query8(bool has_f, char **query_parameters,
            ReservationsData *reservations_data, FILE *output_file);

/**
 * @brief Queries the data structs.
 *
 * @param has_f If the query has the modifier 'F'.
 * @param line The line with the quey parameters.
 * @param users_data The users data struct.
 * @param output_file The pointer to the output file.
 * @param num_parameters The number of parameters.
 */
void query9(bool has_f, char **query_parameters, UsersData *users_data,
            StatsUserInfo *users_stats, FILE *output_file, int num_parameters);

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
