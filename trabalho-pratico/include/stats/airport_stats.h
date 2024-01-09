#ifndef AIRPORT_STATS_H
#define AIRPORT_STATS_H

#include <glib.h>

typedef struct airport_stats AirportStats;

typedef struct airport_info AirportInfo;

typedef struct airport_info_list AirportInfoList;

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
 * @brief Gets the delays from airport stats.
 *
 * @param airport_stats Airport stats of type 'AirportStats*'.
 *
 * @returns The delays of type 'GArray*'.
 *
 */
GArray *get_delays(AirportStats *airport_stats);

/**
 * @brief Creates a new airport stats.
 *
 * @param airport_name Airport name of type 'char*'.
 * @param flight_id Flight id of type 'char*'.
 *
 * @returns A new airport stats of type 'AirportStats*'.
 *
 */
AirportStats *create_airport_stats(char *airport_name, int flight_id,
                                   int delay);

/**
 * @brief Updates an airport stats.
 *
 * @param airport_stats Airport stats of type 'AirportStats*'.
 * @param airport_name Airport name of type 'char*'.
 * @param flight_id Flight id of type 'char*'.
 *
 * @returns An updated airport stats of type 'AirportStats*'.
 *
 */
AirportStats *update_airport_stats(AirportStats *airport_stats,
                                   char *airport_name, int flight_id,
                                   int delay);

/**
 * @brief Adds an airport info to airport stats.
 *
 * @param airport_stats Airport stats of type 'AirportStats*'.
 * @param airport_info Airport info of type 'AirportInfo*'.
 *
 */
void add_airport_info(AirportStats *airport_stats);

// /**
//  * @brief Destroys an airport info.
//  *
//  * @param airport_info Airport info of type 'AirportInfo*'.
//  *
//  */
// void destroy_airport_info(AirportInfo *airport_info);

/**
 * @brief Destroys an airport stats.
 *
 * @param airport_stats Airport stats of type 'AirportStats*'.
 *
 */
void destroy_airport_stats(AirportStats *airport_stats);

/**
 * @brief Creates a new airport info list.
 *
 * @param year Year of type 'int'.
 * @param origin Origin of type 'char*'.
 * @param destination Destination of type 'char*'.
 * @param number_of_passengers Number of passengers of type 'int'.
 *
 * @returns A new airport info list of type 'AirportInfoList*'.
 */
AirportInfo *create_airport_info(int year, char *origin, char *destination,
                                 int number_of_passengers);
/**
 * @brief Creates a new airport info list.
 *
 * @param origin Origin of type 'char*'.
 * @param destination Destination of type 'char*'.
 * @param number_of_passengers Number of passengers of type 'int'.
 *
 * @returns A new airport info list of type 'AirportInfoList*'.
 */
AirportInfo *update_airport_info(AirportInfo *airport_info, char *origin,
                                 char *destination, int number_of_passengers);
/**
 * @brief destroy a airport info list.
 *
 * @param airport_info_list Airport info list of type 'AirportInfoList*'.
 */
void destroy_airport_info_list(AirportInfoList *airport_info_list);

/**
 * @brief destroy a airport info .
 *
 * @param airport_info Airport info of type 'AirportInfo*'.
 */
void destroy_airport_info(AirportInfo *airport_info);

#endif
