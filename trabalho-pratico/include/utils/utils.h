#ifndef UTILS_H
#define UTILS_H

#include <glib.h>
#include <stdbool.h>
#include <stdio.h>

#include "services/queries_service.h"
#include "stats/user_stats.h"

#define MASTER_DATE "2023/10/01"

/**
 * @brief Function that checks if the input file is valid.
 *
 * @param path The path of the input file of type 'const char*'
 *
 * @return True if the input file is valid or False if it isn't of type 'int'
 */
int check_input_file(const char* path);

/**
 * @brief Function that concatenates two strings.
 *
 * @param str1 The first string of type 'const char*'
 * @param str2 The second string of type 'const char*'
 *
 * @return The concatenated string of type 'char*'
 */
char* concatenate_strings(const char* str1, const char* str2);

/**
 * @brief Function that checks if the path of the dataset is valid.
 *
 * @param path The path of the dataset of type 'const char*'
 *
 * @return True if the path is valid or False if it isn't of type 'int'
 */
int check_dataset_path(const char* path);

/**
 * @brief Function that calculates the age of a passenger.
 *
 * @param birth_date The birth date of the passenger of type 'int'
 *
 * @return The age of the passenger of type 'int'
 *
 */
int calculate_age(int birth_date);

/**
 * @brief Function that calculates the total price of a reservation.
 *
 * @param num_nights The number of nights of type 'int'
 *
 * @param price_per_night The price per night of type 'int'
 *
 * @param city_tax The city tax of type 'char'
 *
 * @return The total price of the reservation of type 'double'
 *
 */
double calculate_total_price(int num_nights, int price_per_night,
                             char city_tax);

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
 * @brief Function that if end date is next to begin date.
 *
 * @param begin_date_str The begin date of type 'const char*'
 * @param end_date_str The end date of type 'const char*'
 *
 * @return if end date is next to begin date of type 'int'
 */
int is_day_next(const char* begin_date_str, const char* end_date_str);

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

/**
 * @brief Function that creates a prefix.
 *
 * @param parameters The parameters of the prefix of type 'char**'
 * @param N The number of parameters of type 'int'
 *
 * @return The prefix of type 'char*'
 */
char* create_prefix(char** parameters, int N);

/**
 * @brief Function that orders the user info by name and if they have the same
 * name, by id.
 *
 * @param a The first string of type 'const void*'
 * @param b The second string of type 'const void*'
 *
 * @return The result of the check of type 'int'
 */
int compare(const void* a, const void* b);

/**
 * @brief Function that create an valid data for query 5 parameters
 *
 * @param str1 The first parameter of the date of query 5 of type 'char*'
 * @param str2 The second parameter of the date of query 5 of type 'char*'
 *
 * @return The valid date of query 5 of type 'char*'
 *
 */
char* concatenate_and_modify_strings(char* str1, char* str2);

/**
 *  @brief Function that orders the responsed by name and if they have the same
 * name, by id, for obtaining the requested order
 *
 * @param a The first string of type 'const void*'
 * @param b The second string of type 'const void*'
 *
 * @return The result of the check of type 'int'
 */
int compare_respond(const void* a, const void* b);

/**
 * @brief Function to find prefix in user_name.
 *
 * @param a The first string of type 'const void*'
 * @param b The second string of type 'const void*'
 *
 * @return The result of the check of type 'int'
 */
int check_prefix(const void* a, const void* b);

/**
 * @brief Function that normalizes includes breakfast
 *
 * @param includes_breakfast The string of type 'char*'
 *
 * @return True if it includes breakfast or False if it doesn't of type
 * 'bool'.
 */
bool normalize_includes_breakfast(char* includes_breakfast);

/**
 * @brief Function that normalizes the hotel id
 *
 * @param hotel_id The hotel id of type 'char*'
 *
 * @return The normalized hotel id of type 'int'
 */
int normalize_hotel_id(char* hotel_id);

/**
 * @brief Function that normalizes the date
 *
 * @param date The date of type 'char*'
 *
 * @return The normalized date of type 'int'
 */
int normalize_date(char* date);

/**
 * @brief Function that normalizes the date with only the month
 *
 * @param date The date of type 'char*'
 *
 * @return The normalized date of type 'int'
 */
int normalize_date_month(char* date);

/**
 * @brief Function that normalizes the date with only the year
 *
 * @param date The date of type 'char*'
 *
 * @return The normalized date of type 'int'
 */
int normalize_date_year(char* date);

/**
 * @brief Function that normalizes the date
 *
 * @param date The date of type 'char*'
 *
 * @return The normalized date with day of type 'int'
 */
int normalize_date_with_day(char* date);

/**
 * @brief Function that normalizes the date
 *
 * @param date The date of type 'char*'
 *
 * @return The normalized date with month of type 'int'
 */
int normalize_date_with_month(char* date);

/**
 * @brief Function that normalizes the date
 *
 * @param date The date of type 'char*'
 *
 * @return The normalized date with year of type 'int'
 */
int normalize_date_with_year(char* date);

/**
 * @brief Function that converts a date in integer to a string
 *
 * @param date The date of type 'int'
 *
 * @return The date of type 'char*
 */
char* date_to_string(int date);

/**
 * @brief Function that calculate the median of delay in a airport
 *
 * @param key The key of the airport of type 'gpointer'
 * @param value The value of the airport of type 'gpointer'
 * @param user_data The user data of type 'gpointer'
 *
 */
void calculate_median_for_airport(gpointer key, gpointer value,
                                  gpointer user_data);

/**
 * @brief Auxiliar function that calculate the median of delay in a airport
 *
 * @param delays The delays of type 'GArray*'
 *
 * @return The median of delay of type 'double'
 */
double calculate_median(GArray* delays);

/**
 * @brief Function to sort the airports by median of delay,ascending order
 *
 * @param a The first airport of type 'gconstpointer'
 * @param b The second airport of type 'gconstpointer'
 *
 * @return The result of the check of type 'gint'
 */
gint ascending_order(gconstpointer a, gconstpointer b);

/**
 * @brief Function to sort the airports by median of delay,descending order
 *
 * @param a The first airport of type 'gconstpointer'
 * @param b The second airport of type 'gconstpointer'
 *
 * @return The result of the check of type 'gint'
 */
gint compare_median(gconstpointer a, gconstpointer b);

/*
 * @brief Function that sorts the reservations by date.
 *
 * @param result The result of the query of type 'void*'
 * @param N The number of reservations of type 'int'
 */
void sort_by_departure_date(void* result, int N);

/**
 * @brief Function that normalizes the string to upper
 *
 * @param string The string of type 'char*'
 */
void normalize_string_to_upper(char* string);

/**
 * @brief Function that normalizes the reservation id
 *
 * @param reservation_id The reservation id of type 'char*'
 *
 * @return The normalized reservation id of type 'int'
 */
int normalize_reservation_id(char* reservation_id);

/**
 * @brief Function that converts a reservation id in integer to a string
 *
 * @param reservation_id The reservation id of type 'int'
 *
 * @return The reservation id of type 'char*
 */
char* int_to_reservation_id(int reservation_id);

/**
 * @brief Function that counts the number of digits of a number
 *
 * @param n The number of type 'int'
 *
 * @return The number of digits of type 'int'
 */
int count_digits(int n);

/**
 * @brief Function that normalizes the flight id
 *
 * @param flight_id The flight id of type 'int'
 * @param N The number of digits of the flight id of type 'int'
 *
 * @return The normalized flight id of type 'int'
 */
char* int_to_flight_id(int flight_id, int N);

/**
 * @brief Function that calculates the number of unique passengers
 *
 * @param users_list The list of users of type 'GList*'
 * @param users_data The users data of type 'UsersData*'
 * @param flights_data The flights data of type 'FlightsData*'
 * @param date The date of type 'char*'
 * @param chars_to_compare The number of chars to compare of type 'int'
 *
 * @return The number of unique passengers of type 'int'
 */
int calculate_number_unique_passengers(GList* users_list, UsersData* users_data,
                                       FlightsData* flights_data, char* date,
                                       int chars_to_compare);

/**
 * @brief Function that calculates the number of unique passengers
 *
 * @param users_list The list of users of type 'GArray*'
 *
 * @return The number of unique passengers of type 'int'
 */
int remove_duplicates(GArray* data);

/**
 * @brief Compare two files
 *
 * @param fp1 File pointer to the first file
 * @param fp2 File pointer to the second file
 * @param error_line The line where the files are different
 * @param correct_line The line where the files are equal
 *
 *
 * @return 0 if the files are equal, 1 if they are different
 */
int compare_files(FILE* fp1, FILE* fp2, char* error_line, char* correct_line);

#endif
