#ifndef FLIGHT_STATS_H
#define FLIGHT_STATS_H

typedef struct flight_stats FlightStats;

/**
 * @brief Sets the flight id from flight stats.
 *
 * @param flight_stats Flight stats of type 'FlightStats*'.
 * @param flight_id Flight id of type 'char*'.
 *
 */
void set_flight_id_from_flight_stats(FlightStats *flight_stats,
                                     char *flight_id);

/**
 * @brief Sets the number of passengers from flight stats.
 *
 * @param flight_stats Flight stats of type 'FlightStats*'.
 * @param number_of_passengers Number of passengers of type 'int'.
 *
 */
void set_number_of_passengers_from_flight_stats(FlightStats *flight_stats,
                                                int number_of_passengers);

/**
 * @brief Gets the flight id from flight stats.
 *
 * @param flight_stats Flight stats of type 'FlightStats*'.
 *
 */
char *get_flight_id_from_flight_stats(FlightStats *flight_stats);

/**
 * @brief Gets the number of passengers from flight stats.
 *
 * @param flight_stats Flight stats of type 'FlightStats*'.
 *
 */
int get_number_of_passengers_from_flight_stats(FlightStats *flight_stats);

/**
 * @brief Creates a new flight stats.
 *
 * @param flight_id Flight id of type 'char*'.
 * @param number_of_passengers Number of passengers of type 'int'.
 *
 * @returns A new flight stats of type 'FlightStats*'.
 *
 */
FlightStats *create_flight_stats(char *flight_id, int number_of_passengers);

/**
 * @brief Updates a flight stats.
 *
 * @param flight_stats Flight stats of type 'FlightStats*'.
 * @param id Id of type 'char*'.
 * @param passengers Passengers of type 'int'.
 *
 * @returns An updated flight stats of type 'FlightStats*'.
 *
 */
FlightStats *update_flight_stats(FlightStats *flight_stats, char *id,
                                 int passengers);

/**
 * @brief Destroys a flight stats.
 *
 * @param flight_stats Flight stats of type 'FlightStats*'.
 *
 */
void destroy_flight_stats(FlightStats *flight_stats);

#endif
