#ifndef FLIGHT_CONTROLLER_H
#define FLIGHT_CONTROLLER_H

#include "models/flight.h"
#include "stats/airport_stats.h"
#include "stats/flight_stats.h"

typedef struct flights_data FlightsData;

/**
 * @brief Gets the flight stats hashtable.
 *
 * @param flights_data Pointer to the FlightsData struct.
 *
 * @return GHashTable pointer of type 'GHashTable*' to the flight stats
 */
GHashTable *get_airport_stats(FlightsData *flights_data);

/**
 * @brief Allocates the memory necessary to create a new FlightsData struct and
 * generates the hastable.
 *
 * @return FlightsData pointer of type 'FlightsData*' to the allocated memory.
 */
FlightsData *flights_data_new();

/**
 * @brief Adds a flight to the hastable.
 *
 * @param flights_data Pointer to the FlightsData struct.
 * @param flight Pointer to the FlightInfo struct.
 */
void add_flight(FlightsData *flights_data, FlightInfo *flight);

/**
 * @brief Frees the memory allocated to the FlightsData struct.
 *
 * @param flights_data Pointer to the FlightsData struct.
 */
void flights_data_free(FlightsData *flights_data);

/**
 * @brief Adds a flight stats to the hastable.
 *
 * @param flights_data Pointer to the FlightsData struct.
 * @param flight_stats Pointer to the FlightStats struct.
 */
void add_flight_stats_controller(FlightsData *flights_data,
                                 FlightStats *flight_stats);

/**
 * @brief Updates the flight stats.
 *
 * @param flights_data Pointer to the FlightsData struct.
 * @param flight_id Pointer to the flight id.
 * @param number_of_passengers Number of passengers of type 'int'.
 */
void update_flight_stats_controller(FlightsData *flights_data, int flight_id,
                                    int number_of_passengers);

/**
 * @brief Gets a flight from the hastable by its flight id.
 *
 * @param flights_data Pointer to the FlightsData struct.
 * @param flight_id Pointer to the flight id.
 * @return FlightInfo pointer of type 'FlightInfo*' to the flight.
 */
FlightInfo *get_flight_by_flight_id(FlightsData *flights_data, int flight_id);

/**
 * @brief Gets a flight stats from the hastable by its flight id.
 *
 * @param flights_data Pointer to the FlightsData struct.
 * @param flight_id Pointer to the flight id.
 * @return FlightStats pointer of type 'FlightStats*' to the flight stats.
 */
FlightStats *get_flight_stats_by_flight_id(FlightsData *flights_data,
                                           int flight_id);

/**
 * @brief Adds an airport stats to the hastable.
 *
 * @param flights_data Pointer to the FlightsData struct.
 * @param airport_stats Pointer to the AirportStats struct.
 */
void add_airport_stats_controller(FlightsData *flights_data,
                                  AirportStats *airport_stats);

/**
 * @brief Updates the airport stats.
 *
 * @param flights_data Pointer to the FlightsData struct.
 * @param airport_name Pointer to the airport name.
 * @param airport_info Pointer to the AirportInfo struct.
 */
void update_airport_stats_controller(FlightsData *flights_data,
                                     char *airport_name, int flight_id,
                                     int delay);

/**
 * @brief Gets an airport stats from the hastable by its airport name.
 *
 * @param flights_data Pointer to the FlightsData struct.
 * @param airport_name Pointer to the airport name.
 * @return AirportStats pointer of type 'AirportStats*' to the airport stats.
 */
AirportStats *get_airport_stats_by_airport_name(FlightsData *flights_data,
                                                char *airport_name);

#endif
