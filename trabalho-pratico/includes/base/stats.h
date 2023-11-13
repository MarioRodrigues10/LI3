#ifndef STATS_H
#define STATS_H

#include <glib.h>

typedef struct stats *STATS;
typedef struct hotel_stats *HOTEL_STATS;
typedef struct flight_stats *FLIGHT_STATS;
typedef struct user_stats *USER_STATS;

/**
 * @brief Function that creates the stats
 *
 * @return The stats created
 */
STATS create_stats();

/**
 * @brief Function that gets the total of the ratings
 *
 * @param stats The stats
 * @param id The id of the hotel
 *
 * @return The total of the ratings
 */
void free_stats(STATS stats);

/**
 * @brief Function that creates the hotel stats
 *
 * @param id The id of the hotel
 * @param total_rating The total rating of the hotel
 * @param total_clients The total clients of the hotel
 *
 * @return The hotel stats created
 */
HOTEL_STATS create_hotel_stats(char *hotel_id, int total_rating,
                               int total_clients);

/**
 * @brief Function that gets the total rating of the hotel
 *
 * @param stats The stats
 * @param id The id of the hotel
 * @param total_rating The total rating of the hotel
 *
 */
void update_hotel_stats(STATS stats, char *hotel_id, int total_rating);

/**
 * @brief Function that gets the hotel stats by the hotel id
 *
 * @param stats The stats
 * @param id The id of the hotel
 *
 * @return The hotel stats
 *
 */
HOTEL_STATS get_hotel_stats_by_hotel_id(STATS stats, char *hotel_id);

/**
 * @brief Function that gets the sum rating of the hotel
 *
 * @param stats The stats
 * @param id The id of the hotel
 *
 * @return The sum rating of the hotel
 */
int get_total_rating(STATS stats, char *hotel_id);

/**
 * @brief Function that gets the total
 *
 * @param stats The stats
 * @param id The id of the hotel
 *
 * @return The total clients of the hotel
 */
int get_total_clients(STATS stats, char *hotel_id);

/**
 * @brief Function that gets the media of the ratings
 *
 * @param stats The stats
 * @param id The id of the hotel
 *
 * @return The media of the ratings
 */
double media_of_ratings(STATS stats, char *hotel_id);

/**
 * @brief Function that frees the memory alocated to the hotel stats
 *
 * @param hotel_stats The hotel stats to be freed of type 'HOTEL_STATS'
 */
void free_hotel_stats(HOTEL_STATS hotel_stats);

/**
 * @brief Function that creates the flight stats
 *
 * @param flight_id The id of the flight
 * @param total_passengers The total passengers of the flight
 *
 * @return The flight stats created
 */
FLIGHT_STATS create_flight_stats(char *flight_id, int total_passengers);

/**
 * @brief Function that updates the stats of the flight
 *
 * @param stats The stats of type 'STATS'
 *
 * @param flight_id The id of the flight
 *
 */
void update_flight_stats(STATS stats, char *flight_id);

/**
 * @brief Function that gets the flight stats by the flight id
 *
 * @param stats The stats
 * @param id The id of the flight
 *
 * @return The flight stats
 */
FLIGHT_STATS get_flight_stats_by_flight_id(STATS stats, char *flight_id);

/**
 * @brief Function that gets the total passengers of the flight
 *
 * @param stats The stats of type 'STATS'
 * @param flight_id The id of the flight
 *
 * @return The total passengers of the flight
 */
int get_total_passengers(STATS stats, char *flight_id);

/**
 * @brief Function that frees the memory alocated to the flight stats
 *
 * @param flight_stats The flight stats to be freed of type 'FLIGHT_STATS'
 */
void free_flight_stats(FLIGHT_STATS flight_stats);

/**
 * @brief Function that creates the user stats
 *
 * @param user_id The id of the user
 * @param number_of_flights The number of flights of the user
 * @param number_of_reservations The number of reservations of the user
 * @param total_spent The total spent of the user
 *
 * @return The user stats created
 */
USER_STATS create_user_stats(char *user_id, int number_of_flights,
                             int number_of_reservations, double total_spent);

/**
 * @brief Function that updates the number of fligths of the user
 *
 * @param stats The stats of type 'STATS'
 * @param user_id The id of the user
 */
void update_user_stats_number_of_flights(STATS stats, char *user_id);

/**
 * @brief Function that updates the number of reservations of the user
 *
 * @param stats The stats of type 'STATS'
 * @param user_id The id of the user
 */
void update_user_stats_number_of_reservations(STATS stats, char *user_id);

/**
 * @brief Function that updates the total spent of the user
 *
 * @param stats The stats of type 'STATS'
 * @param user_id The id of the user
 * @param total_spent The total spent of the user
 */
void update_user_stats_total_spent(STATS stats, char *user_id,
                                   double total_spent);

/**
 * @brief Function that gets the user stats by the user id
 *
 * @param stats The stats
 * @param id The id of the user
 *
 * @return The user stats
 */
USER_STATS get_user_stats_by_user_id(STATS stats, char *user_id);

/**
 * @brief Function that gets the number of flights of the user
 *
 * @param stats The stats of type 'STATS'
 * @param user_id The id of the user
 *
 * @return The number of flights of the user
 */
int get_number_of_flights(STATS stats, char *user_id);

/**
 * @brief Function that gets the number of reservations of the user
 *
 * @param stats The stats of type 'STATS'
 * @param user_id The id of the user
 *
 * @return The number of reservations of the user
 */
int get_number_of_reservations(STATS stats, char *user_id);

/**
 * @brief Function that gets the total spent of the user
 *
 * @param stats The stats of type 'STATS'
 * @param user_id The id of the user
 *
 * @return The total spent of the user
 */
double get_total_spent(STATS stats, char *user_id);

/**
 * @brief Function that frees the memory alocated to the user stats
 *
 * @param user_stats The user stats to be freed of type 'USER_STATS'
 */
void free_user_stats(USER_STATS user_stats);

#endif