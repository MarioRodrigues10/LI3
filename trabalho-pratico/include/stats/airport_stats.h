#ifndef AIRPORT_STATS_H
#define AIRPORT_STATS_H

#include <glib.h>

typedef struct airport_stats AirportStats;

typedef struct airport_info AirportInfo;

/**
 * @brief Sets the flight id of airport info.
 *
 * @param airport_info Airport info of type 'AirportInfo*'.
 * @param flight_id Flight id of type 'char*'.
 *
 */
void set_flight_id_of_airport_info(AirportInfo *airport_info, char *flight_id);

/**
 * @brief Sets the departure date of airport info.
 *
 * @param airport_info Airport info of type 'AirportInfo*'.
 * @param departure_date Departure date of type 'char*'.
 *
 */
void set_departure_date_of_airport_info(AirportInfo *airport_info,
                                        char *departure_date);

/**
 * @brief Sets the destination of airport info.
 *
 * @param airport_info Airport info of type 'AirportInfo*'.
 * @param destination Destination of type 'char*'.
 *
 */
void set_destination_of_airport_info(AirportInfo *airport_info,
                                     char *destination);

/**
 * @brief Sets the airline of airport info.
 *
 * @param airport_info Airport info of type 'AirportInfo*'.
 * @param airline Airline of type 'char*'.
 *
 */
void set_airline_of_airport_info(AirportInfo *airport_info, char *airline);

/**
 * @brief Sets the plane model of airport info.
 *
 * @param airport_info Airport info of type 'AirportInfo*'.
 * @param plane_model Plane model of type 'char*'.
 *
 */
void set_plane_model_of_airport_info(AirportInfo *airport_info,
                                     char *plane_model);

/**
 * @brief Sets the airport name of airport stats.
 *
 * @param airport_stats Airport stats of type 'AirportStats*'.
 * @param airport_name Airport name of type 'char*'.
 *
 */
void set_airport_name_of_airport_stats(AirportStats *airport_stats,
                                       char *airport_name);

/**
 * @brief Gets the flight id from airport info.
 *
 * @param airport_info Airport info of type 'AirportInfo*'.
 *
 */
char *get_flight_id_from_airport_info(AirportInfo *airport_info);

/**
 * @brief Gets the departure date from airport info.
 *
 * @param airport_info Airport info of type 'AirportInfo*'.
 *
 */
char *get_departure_date_from_airport_info(AirportInfo *airport_info);

/**
 * @brief Gets the destination from airport info.
 *
 * @param airport_info Airport info of type 'AirportInfo*'.
 *
 */
char *get_destination_from_airport_info(AirportInfo *airport_info);

/**
 * @brief Gets the airline from airport info.
 *
 * @param airport_info Airport info of type 'AirportInfo*'.
 *
 */
char *get_airline_from_airport_info(AirportInfo *airport_info);

/**
 * @brief Gets the plane model from airport info.
 *
 * @param airport_info Airport info of type 'AirportInfo*'.
 *
 */
char *get_plane_model_from_airport_info(AirportInfo *airport_info);

/**
 * @brief Gets the airport name from airport stats.
 *
 * @param airport_stats Airport stats of type 'AirportStats*'.
 *
 */
char *get_airport_name_from_airport_stats(AirportStats *airport_stats);

/**
 * @brief Gets the airport flights from airport stats.
 *
 * @param airport_stats Airport stats of type 'AirportStats*'.
 *
 */
GArray *get_airport_flights_from_airport_stats(AirportStats *airport_stats);

/**
 * @brief Creates a new airport info.
 *
 * @param flight_id Flight id of type 'char*'.
 * @param departure_date Departure date of type 'char*'.
 * @param destination Destination of type 'char*'.
 * @param airline Airline of type 'char*'.
 * @param plane_model Plane model of type 'char*'.
 *
 * @returns A new airport info of type 'AirportInfo*'.
 *
 */

AirportInfo *create_airport_info(char *flight_id, char *departure_date,
                                 char *destination, char *airline,
                                 char *plane_model);

/**
 * @brief Creates a new airport stats.
 *
 * @param airport_name Airport name of type 'char*'.
 * @param airport_info Airport info of type 'AirportInfo*'.
 *
 * @returns A new airport stats of type 'AirportStats*'.
 *
 */
AirportStats *create_airport_stats(char *airport_name,
                                   AirportInfo *airport_info);

/**
 * @brief Updates an airport stats.
 *
 * @param airport_stats Airport stats of type 'AirportStats*'.
 * @param airport_name Airport name of type 'char*'.
 * @param airport_info Airport info of type 'AirportInfo*'.
 *
 * @returns An updated airport stats of type 'AirportStats*'.
 *
 */
AirportStats *update_airport_stats(AirportStats *airport_stats,
                                   char *airport_name,
                                   AirportInfo *airport_info);

/**
 * @brief Adds an airport info to airport stats.
 *
 * @param airport_stats Airport stats of type 'AirportStats*'.
 * @param airport_info Airport info of type 'AirportInfo*'.
 *
 */
void add_airport_info(AirportStats *airport_stats, AirportInfo *airport_info);

/**
 * @brief Destroys an airport info.
 *
 * @param airport_info Airport info of type 'AirportInfo*'.
 *
 */
void destroy_airport_info(AirportInfo *airport_info);

/**
 * @brief Destroys an airport stats.
 *
 * @param airport_stats Airport stats of type 'AirportStats*'.
 *
 */
void destroy_airport_stats(AirportStats *airport_stats);

/**
 * @brief Gets the airport info by index.
 *
 * @param airport_stats Airport stats of type 'AirportStats*'.
 * @param index Index of type 'int'.
 *
 */
AirportInfo *get_airport_info_by_index(AirportStats *airport_stats, int index);

/**
 * @brief Sorts airport infos by departure date.
 *
 * @param airport_stats Airport stats of type 'AirportStats*'.
 *
 */
void sort_airport_info_by_departure_date(AirportStats *airport_stats);

/**
 * @brief Compares two airport infos by departure date.
 *
 * @param airport_info_1 Airport info of type 'gconstpointer'.
 * @param airport_info_2 Airport info of type 'gconstpointer'.
 *
 * @returns An integer representing the comparation.
 */
int compare_airport_info_by_departure_date(gconstpointer airport_info_1,
                                           gconstpointer airport_info_2);

#endif
