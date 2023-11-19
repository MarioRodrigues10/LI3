#ifndef OUTPUT_HANDLER_CONTROLLER_H
#define OUTPUT_HANDLER_CONTROLLER_H

#include <stdbool.h>
#include <stdio.h>

typedef struct query4_result *QUERY4_RESULT;

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
                                  char *hotel_name, int hotel_stars,
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
                           char *age, char *country_code, char *passport,
                           int number_of_flights, int number_of_reservations,
                           double total_spent);

/**
 * @brief Writes the query2 output to file
 *
 * @param has_f Wheter the output should be formatted or not
 * @param output_file The output file
 * @param ids The ids
 * @param dates The dates
 * @param types The types
 * @param N The length of the array
 */
void write_query2(bool has_f, FILE *output_file, char **ids, char **dates,
                  char **types, int N);
/**
 * @brief Writes the query3 output to the output file.
 *
 * @param has_f Whether the output should be formatted or not.
 * @param output_file The output file.
 * @param media_of_ratings The media of ratings.
 */
void write_query3(bool has_f, FILE *output_file, double media_of_ratings);

/**
 * @brief Writes the query4 output to the output file.
 *
 * @param has_f Whether the output should be formatted or not.
 * @param output_file The output file.
 * @param query_result The query result.
 */
void write_query4(bool has_f, FILE *output_file, QUERY4_RESULT query_result);

/**
 * @brief Writes the query8 output to the output file.
 *
 * @param has_f Whether the output should be formatted or not.
 * @param output_file The output file.
 * @param revenue The revenue.
 */
void write_query8(bool has_f, FILE *output_file, double revenue);

/**
 * @brief Writes the query9 output to the output file.
 *
 * @param has_f Whether the output should be formatted or not.
 * @param output_file The output file.
 * @param user_ids The user ids.
 * @param user_names The user names.
 * @param N The length of the array.
 */
void write_query9(bool has_f, FILE *output_file, char **user_ids,
                  char **user_names, int N);
#endif
