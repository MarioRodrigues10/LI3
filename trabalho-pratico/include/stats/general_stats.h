#ifndef GENERAL_STATS_H
#define GENERAL_STATS_H

#include <glib.h>

typedef struct general_stats GeneralStats;

/**
 * @brief Set the key from general stats object
 *
 * @param general_stats GeneralStats object
 * @param key HashTable key of type 'int'
 */
void set_key_from_general_stats(GeneralStats *general_stats, int key);

/**
 * @brief Set the number of flights from general stats object
 *
 * @param general_stats GeneralStats object
 */
void set_number_of_flights_from_general_stats(GeneralStats *general_stats);

/**
 * @brief Set the number of passengers from general stats object
 *
 * @param general_stats GeneralStats object
 */
void set_number_of_passengers_from_general_stats(GeneralStats *general_stats);

/**
 * @brief Set the unique passengers from general stats object
 *
 * @param general_stats GeneralStats object
 */
void set_unique_passengers_from_general_stats(GeneralStats *general_stats);

/**
 * @brief Set the reservations from general stats object
 *
 * @param general_stats GeneralStats object
 */
void set_reservations_from_general_stats(GeneralStats *general_stats);

/**
 * @brief Set the users from general stats object
 *
 * @param general_stats GeneralStats object
 */
void set_users_from_general_stats(GeneralStats *general_stats);

/**
 * @brief Get the key from general stats object
 *
 * @param general_stats GeneralStats object
 * @return int HashTable key
 */
int get_key_from_general_stats(GeneralStats *general_stats);

/**
 * @brief Get the number of flights from general stats object
 *
 * @param general_stats GeneralStats object
 * @return int Number of flights
 */
int get_number_of_flights_from_general_stats(GeneralStats *general_stats);

/**
 * @brief Get the number of passengers from general stats object
 *
 * @param general_stats GeneralStats object
 * @return int Number of passengers
 */
int get_number_of_passengers_from_general_stats(GeneralStats *general_stats);

/**
 * @brief Get the unique passengers from general stats object
 *
 * @param general_stats GeneralStats object
 * @return int Number of unique passengers
 */
int get_unique_passengers_from_general_stats(GeneralStats *general_stats);

/**
 * @brief Get the reservations from general stats object
 *
 * @param general_stats GeneralStats object
 *
 * @return int Number of reservations
 */
int get_reservations_from_general_stats(GeneralStats *general_stats);

/**
 * @brief Set the users from general stats object
 *
 * @param general_stats GeneralStats object
 */
int get_users_from_general_stats(GeneralStats *general_stats);

/**
 * @brief Get the users array from general stats object
 *
 * @param general_stats GeneralStats object
 *
 * @return GArray* Users array
 */
GArray *get_users_array_from_general_stats(GeneralStats *general_stats);

/**
 * @brief Create a general stats object
 *
 * @param key HashTable key of type 'int'
 * @param number_of_users Number of users of type 'int'
 * @param number_of_flights Number of flights of type 'int'
 * @param number_of_passengers Number of passengers of type 'int'
 * @param reservations Number of reservations of type 'int'
 * @param user_id User id of type 'char*'
 *
 * @return GeneralStats* GeneralStats object
 */
GeneralStats *create_general_stats(int key, int number_of_users,
                                   int number_of_flights,
                                   int number_of_passengers, int reservations,
                                   char *user_id);

/**
 * @brief Update general stats object
 *
 * @param general_stats GeneralStats object
 * @param key HashTable key of type 'int'
 * @param number_of_users Number of users of type 'int'
 * @param number_of_flights Number of flights of type 'int'
 * @param number_of_passengers Number of passengers of type 'int'
 * @param reservations Number of reservations of type 'int'
 * @param user_id User id of type 'char*'
 *
 * @return GeneralStats* Updated general stats object
 */
GeneralStats *update_general_stats(GeneralStats *general_stats, int key,
                                   int number_of_users, int number_of_flights,
                                   int number_of_passengers, int reservations,
                                   char *user_id);

/**
 * @brief Destroy general stats object
 *
 * @param general_stats GeneralStats object
 */
void destroy_general_stats(GeneralStats *general_stats);

#endif