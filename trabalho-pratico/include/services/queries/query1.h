#ifndef QUERY1_H
#define QUERY1_H

#include <stdbool.h>
#include <stdio.h>

#include "controllers/flight_controller.h"
#include "controllers/reservation_controller.h"
#include "controllers/user_controller.h"
#include "models/flight.h"
#include "models/reservation.h"
#include "models/user.h"
#include "stats/user_stats.h"
#include "utils/maping.h"
#include "utils/utils.h"

/**
 * @brief Writes the query1 output to the output file.
 *
 * @param has_f Whether the output should be formatted or not.
 * @param output_file The output file.
 * @param hotel_id The hotel id.
 * @param hotel_name The hotel name.
 * @param hotel_stars The hotel stars.
 * @param begin_date The begin date.
 * @param end_date The end date.
 * @param includes_breakfast The includes breakfast.
 * @param number_of_nights The number of nights.
 * @param total_price The total price.
 */
void write_query1_for_reservation(bool has_f, FILE *output_file, char *hotel_id,
                                  char *hotel_name, char hotel_stars,
                                  char *begin_date, char *end_date,
                                  char *includes_breakfast,
                                  int number_of_nights, double total_price);

/**
 * @brief Writes the query1 output to the output file.
 *
 * @param has_f Whether the output should be formatted or not.
 * @param output_file The output file.
 * @param airline_company The airline company.
 * @param plane_model The plane model.
 * @param origin The origin.
 * @param destination The destination.
 * @param schedule_departure_date The schedule departure date.
 * @param schedule_arrival_date The schedule arrival date.
 * @param passengers The number of passengers.
 * @param delay The delay.
 */
void write_query1_for_flight(bool has_f, FILE *output_file,
                             char *airline_company, char *plane_model,
                             char *origin, char *destination,
                             char *schedule_departure_date,
                             char *schedule_arrival_date, int passengers,
                             int delay);

/**
 * @brief Writes the query1 output to the output file.
 *
 * @param has_f Whether the output should be formatted or not.
 * @param output_file The output file.
 * @param name The name.
 * @param sex The sex.
 * @param age The age.
 * @param country_code The country code.
 * @param passport The passport.
 * @param number_of_flights The number of flights.
 * @param number_of_reservations The number of reservations.
 * @param total_spent The total spent.
 */
void write_query1_for_user(bool has_f, FILE *output_file, char *name, char *sex,
                           int age, char *country_code, char *passport,
                           int number_of_flights, int number_of_reservations,
                           double total_spent);

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

#endif
