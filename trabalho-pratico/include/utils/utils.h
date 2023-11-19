#ifndef UTILS_H
#define UTILS_H

#include <glib.h>

#include "stats/user_stats.h"

#define MASTER_DATE "2023/10/01"

/**
 * @struct query4_result - Struct that represents the result of query 4 to be
 * used in other places of the program
 */
typedef struct query4_result* QUERY4_RESULT;

/**
 * @brief Function that calculates the age of a passenger.
 *
 * @param birth_date_str The birth date of the passenger of type 'char*'
 *
 * @return The age of the passenger of type 'int'
 *
 */
char* calculate_age(char* birth_date_str);

/**
 * @brief Function that calculates the total price of a reservation.
 *
 * @param num_nights The number of nights of type 'int'
 *
 * @param price_per_night The price per night of type 'int'
 *
 * @param city_tax The city tax of type 'int'
 *
 * @return The total price of the reservation of type 'double'
 *
 */
double calculate_total_price(int num_nights, int price_per_night, int city_tax);

/**
 * @brief Function that calculates the number of nights between two dates.
 *
 * @param begin_date_str The begin date of type 'const char*'
 *
 * @param end_date_str The end date of type 'const char*'
 *
 * @return The number of nights of type 'int'
 *
 */
int calculate_number_of_nights(const char* begin_date_str,
                               const char* end_date_str);

/**
 * @brief Function that calculates the delay of a flight.
 *
 * @param scheduled_date The scheduled date of type 'char*'
 *
 * @param actual_date The actual date of type 'char*'
 *
 * @return The delay of the flight of type 'char*' in seconds
 */
int calculate_delay(char* scheduled_date, char* actual_date);

/**
 * @brief Function that compares two dates.
 *
 * @param query4_content The content of the query4 of type 'void*'
 * @param N The number of reservations of type 'int'
 */
void sort_by_date_and_value(void* query4_content, int N);

/**
 * @brief Function that sorts the flights by date.
 *
 * @param flight_ids The flight ids of type 'char**'
 * @param flight_dates The flight dates of type 'char**'
 * @param flight_types The flight types of type 'char**'
 * @param N The number of flights of type 'int'
 */
void sort_by_date(char** flight_ids, char** flight_dates, char** flight_types,
                  int N);

/**
 * @brief Function that sorts the reservations by date.
 *
 * @param year The year of type 'int'
 * @param month The month of type 'int'
 * @param day The day of type 'int'
 */
char* format_date(int year, int month, int day);

/**
 * @brief Function that removes quotation marks from a string.
 *
 * @param str The string to be modified of type 'const char*'
 *
 * @return The modified string of type 'char*'
 */
char* remove_quotation_marks(char* str);

/*
 * @brief Function that concatenates two strings with a space between them.
 *
 * @param str1 The first string of type 'const char*'
 * @param str2 The second string of type 'const char*'
 *
 * @return The concatenated string of type 'char*'
 */
char* strcat_with_space(const char* str1, const char* str2);

/**
 * @brief Function that creates a prefix.
 *
 * @param parameters The parameters of the prefix of type 'char**'
 *
 * @return The prefix of type 'char*'
 */
char* create_prefix(char** parameters);

/**
 * @brief Function that sorts the users by name and id.
 *
 * @param user_ids The user ids of type 'char**'
 * @param user_names The user names of type 'char**'
 * @param N The number of users of type 'int'
 */
void sort_by_name_and_id(char** user_ids, char** user_names, int N);

#endif
