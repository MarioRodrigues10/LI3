#ifndef UTILS_H
#define UTILS_H

#include <glib.h>
#include <stdbool.h>
#include <stdio.h>

#include "entities/flights.h"
#include "entities/passengers.h"
#include "entities/reservations.h"
#include "entities/users.h"
#include "io/parser.h"

/**
 * @brief Converts a string to an integer.
 *
 * @param c The string to be converted.
 *
 * @return The integer value of the string.
 *
 */
int string_to_int(char* c);

/**
 * @brief Extracts a number from a string.
 *
 * @param input The string to be extracted.
 *
 * @return The number extracted from the string.
 *
 */
int extract_number(char* input);

typedef enum errors {
  ERR_OPENING_FLIGHTS_FILE = 1,
  ERR_OPENING_PASSENGERS_FILE = 2,
  ERR_OPENING_RESERVATIONS_FILE = 3,
  ERR_OPENING_USERS_FILE = 4,
  ERR_OPENING_QUERIES_FILE = 5,
  ERR_CREATING_DIRECTORY = 6,
  ERR_OPENING_OUTPUT_FILE = 7,
  ERROR_WRITING_TO_ERRORS_FILE = 8,
} ERRORS;

/**
 * @brief Appends an array of strings to a file, separated by semicolons and
 * followed by a newline character.
 *
 * This function takes an array of strings, combines them, and appends the
 * resulting string to a specified file. The strings in the array are separated
 * by semicolons, and a newline character is added at the end of the line.
 *
 * @param line An array of strings to be combined and written to the file.
 * @param size_of_line The number of elements in the 'line' array.
 * @param file_name The name of the file to which the combined string will be
 * appended.
 * @param num_lines A reference to an integer that tracks the number of lines
 * already written to the file.
 *
 * @return If successful, the function returns the updated number of lines
 * written to the file. If an error occurs, it returns a specific error code.
 */
int print_errors_to_file(char* line[], int size_of_line, const char* file_name,
                         int num_lines);

/**
 * @brief Converts an ERROR enumeration to its corresponding error message.
 *
 * This function takes an ERROR enumeration as input and returns a string
 * describing the associated error message.
 *
 * @param error An ERROR enumeration value.
 * @return A string representing the error message.
 */
char* get_error_as_string(ERRORS error);

/**
 * @brief Creates a filename by concatenating a folder and a string.
 *
 * This function creates a filename by concatenating a folder path and a string.
 *
 * @param folder A string representing the folder path.
 * @param string A string to be concatenated to the folder.
 * @return A dynamically allocated string representing the filename.
 * @note The caller is responsible for freeing the memory allocated for the
 * filename.
 */
char* create_filename(char* folder, const char* string);

/**
 * @brief Creates a directory.
 *
 * This function attempts to create a directory with the specified folder path.
 *
 * @param folder A string representing the folder path to be created.
 * @return 0 if the directory was created successfully, or an error code if
 * creation failed.
 */
int create_directory(char* folder);

/**
 * @brief Creates an output file for storing query results.
 *
 * This function generates an output file with a specific filename based on the
 * query counter.
 *
 * @param queries_counter An integer representing the query counter.
 * @return A file pointer to the created output file, or NULL if an error
 * occurs.
 * @note The caller is responsible for closing the file when done using it.
 */
FILE* create_output_file(int queries_counter);

/**
 * @brief Standardizes an account status string to 'a' (active) or 'i'
 * (inactive).
 *
 * This function takes an account_status string and standardizes it to either
 * 'a' for "active" or 'i' for "inactive". It converts the input string to
 * lowercase and checks for valid status values.
 *
 * @param account_status A string representing the account status to be
 * standardized.
 * @return 'a' for "active," 'i' for "inactive," or 'x' for an invalid status.
 */
char standardize_account_status(char* account_status);

/**
 * @brief Standardizes an "includes_breakfast" string to 't' or 'f'.
 *
 * This function takes an "includes_breakfast" string and standardizes it to 't'
 * for true or 'f' for false. It checks for various valid representations,
 * including different combinations of upper and lower case characters.
 *
 * @param includes_breakfast A string representing the "includes_breakfast"
 * value to be standardized.
 * @return 't' for true, 'f' for false, or an unspecified value for an invalid
 * representation.
 */
char standardize_includes_breakfast(char* includes_breakfast);

/**
 * @brief Standardize an airport name by converting it to lowercase.
 *
 * This function takes an airport name as input and converts it to lowercase,
 * ensuring consistent formatting for airport names. The function operates
 * in-place and modifies the provided `airport_name` string directly.
 *
 * @param airport_name The airport name to be standardized.
 *
 * @return A pointer to the input `airport_name` string with all characters
 * converted to lowercase.
 */
char* standardize_airport_name(char* airport_name);

/**
 * @brief Validates a date in the format "yyyy/mm/dd".
 *
 * This function checks if the input date is in the valid format "yyyy/mm/dd"
 * and if the month and day are within their respective valid ranges.
 *
 * @param date A string representing the date.
 * @return true if the date is valid, false otherwise.
 */
bool validate_date_format_without_time(char* date);

/**
 * @brief Validates a date with time in the format "yyyy/mm/dd hh:mm:ss".
 *
 * This function checks if the input date with time is in the valid format
 * "yyyy/mm/dd hh:mm:ss" and if the month, day, hour, minutes, and seconds are
 * within their respective valid ranges.
 *
 * @param date A string representing the date with time.
 * @return true if the date with time is valid, false otherwise.
 */
bool validate_date_format_with_time(char* date);

/**
 * @brief Validates an email address.
 *
 * This function checks if the input string is in a valid email format,
 * including a non-empty username, domain, and top-level domain (TLD).
 *
 * @param email A string representing an email address.
 * @return true if the email is valid, false otherwise.
 */
bool validate_email(char* email);

/**
 * @brief Validates a country code composed of two letters.
 *
 * This function checks if the input string is a valid country code, consisting
 * of two alphabetic letters.
 *
 * @param country_code A string representing the country code.
 * @return true if the country code is valid, false otherwise.
 */
bool validate_country_code(char* country_code);

/**
 * @brief Validates the account status (active or inactive).
 *
 * This function checks if the input string represents a valid account status,
 * regardless of case. Valid values are "active" or "inactive".
 *
 * @param account_status A string representing the account status.
 * @return true if the account status is valid, false otherwise.
 */
bool validate_account_status(char* account_status);

/**
 * @brief Validates the number of seats in a flight.
 *
 * This function checks if the total number of seats in a flight is not less
 * than the number of passengers.
 *
 * @param total_seats The total number of seats in the flight.
 * @param number_of_passengers The number of passengers.
 * @return true if the number of seats is valid, false otherwise.
 */
bool validate_total_seats(int total_seats, int number_of_passengers);

/**
 * @brief Validates whether two airports are equal (case-insensitive).
 *
 * This function checks if two airport codes are equal, ignoring case.
 *
 * @param airport1 The code of the first airport.
 * @param airport2 The code of the second airport.
 * @return true if the airports are equal, false otherwise.
 */
bool validate_airports(char* airport1, char* airport2);

/**
 * @brief Validates the number of stars of a hotel.
 *
 * This function checks if the input integer is within the valid range of 1 to 5
 * (inclusive).
 *
 * @param hotel_stars The number of stars of the hotel.
 * @return true if the number of stars is valid, false otherwise.
 */
bool validate_number_of_stars(int hotel_stars);

/**
 * @brief Validates the city tax percentage in a reservation.
 *
 * This function checks if the input integer is greater than or equal to 0.
 *
 * @param city_tax The city tax percentage.
 * @return true if the city tax percentage is valid, false otherwise.
 */
bool validate_city_tax(int city_tax);

/**
 * @brief Validates the price per night in a reservation.
 *
 * This function checks if the input integer is greater than 0.
 *
 * @param price_per_night The price per night.
 * @return true if the price per night is valid, false otherwise.
 */
bool validate_price_per_night(int price_per_night);

/**
 * @brief Validates the "includes_breafast" field in a reservation.
 *
 * This function checks if the input string represents a valid value for the
 * "includes_breafast" field, including different combinations of upper and
 * lower case characters. Valid values for "false" include "f", "false", "0",
 * and an empty string. Valid values for "true" include "t", "true", and "1".
 *
 * @param includes_breakfast A string representing the "includes_breafast"
 * field.
 * @return true if the value is valid, false otherwise.
 */
bool validate_includes_breakfast(char* includes_breakfast);

/**
 * @brief Validates a rating value within the range of 1 to 5 (inclusive).
 *
 * This function checks if the input rating value falls within the valid range
 * of 1 to 5.
 *
 * @param rating An integer representing the rating value to be validated.
 * @return true if the rating is valid, false otherwise.
 */
bool validate_rating(int rating);

/**
 * @brief Validates whether a string parameter is not empty and not NULL.
 *
 * This function checks if the input string parameter is not NULL and has a
 * length greater than zero.
 *
 * @param parameter A string parameter to be validated.
 * @return true if the parameter is not empty and not NULL, false otherwise.
 */
bool validate_parameter_not_empty(char* parameter);

#endif
