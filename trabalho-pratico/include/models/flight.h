#ifndef FLIGHT_H
#define FLIGHT_H

#define MAX_TOKENS_FLIGHT 13

#include <glib.h>

typedef struct flight FlightInfo;

/**
 * @brief Allocates the memory necessary to create a new flight.
 *
 * @return FlightInfo pointer of type 'FlightInfo*' to the allocated memory.
 */
FlightInfo *create_flight();

/**
 * @brief Sets the flight id of a flight.
 *
 * @param flight FlightInfo pointer of type 'FlightInfo*'.
 * @param flight_id Flight id of type 'char*'.
 */
void set_flight_id(FlightInfo *flight, int flight_id);

/**
 * @brief Sets the airline of a flight.
 *
 * @param flight FlightInfo pointer of type 'FlightInfo*'.
 * @param airline Airline of type 'char'.
 */
void set_airline(FlightInfo *flight, char airline);

/**
 * @brief Sets the plane model of a flight.
 *
 * @param flight FlightInfo pointer of type 'FlightInfo*'.
 * @param plane_model Plane model of type 'char'.
 */
void set_plane_model(FlightInfo *flight, char plane_model);

/**
 * @brief Sets the total seats of a flight.
 *
 * @param flight FlightInfo pointer of type 'FlightInfo*'.
 * @param total_seats Total seats of type 'short int'.
 */
void set_total_seats(FlightInfo *flight, short int total_seats);

/**
 * @brief Sets the origin of a flight.
 *
 * @param flight FlightInfo pointer of type 'FlightInfo*'.
 * @param origin Origin of type 'char*'.
 */
void set_origin(FlightInfo *flight, char *origin);

/**
 * @brief Sets the destination of a flight.
 *
 * @param flight FlightInfo pointer of type 'FlightInfo*'.
 * @param destination Destination of type 'char*'.
 */
void set_destination(FlightInfo *flight, char *destination);

/**
 * @brief Sets the schedule departure date of a flight.
 *
 * @param flight FlightInfo pointer of type 'FlightInfo*'.
 * @param schedule_departure_date Schedule departure date of type 'guint32'.
 */
void set_schedule_departure_date(FlightInfo *flight,
                                 guint32 schedule_departure_date);

/**
 * @brief Sets the schedule arrival date of a flight.
 *
 * @param flight FlightInfo pointer of type 'FlightInfo*'.
 * @param schedule_arrival_date Schedule arrival date of type 'guint32'.
 */
void set_schedule_arrival_date(FlightInfo *flight,
                               guint32 schedule_arrival_date);

/**
 * @brief Sets the real departure date of a flight.
 *
 * @param flight FlightInfo pointer of type 'FlightInfo*'.
 * @param real_departure_date Real departure date of type 'guint32'.
 */
void set_real_departure_date(FlightInfo *flight, guint32 real_departure_date);

/**
 * @brief Gets the flight id of a flight.
 *
 * @param flight FlightInfo pointer of type 'FlightInfo*'.
 * @return char* Flight id of type 'char*'.
 */
int get_flight_id(FlightInfo *flight);

/**
 * @brief Gets the airline of a flight.
 *
 * @param flight FlightInfo pointer of type 'FlightInfo*'.
 * @return char Airline of type 'char'.
 */
char get_airline(FlightInfo *flight);

/**
 * @brief Gets the plane model of a flight.
 *
 * @param flight FlightInfo pointer of type 'FlightInfo*'.
 * @return char Plane model of type 'char'.
 */
char get_plane_model(FlightInfo *flight);

/**
 * @brief Gets the total seats of a flight.
 *
 * @param flight FlightInfo pointer of type 'FlightInfo*'.
 * @return int Total seats of type 'short int'.
 */
short int get_total_seats(FlightInfo *flight);

/**
 * @brief Gets the origin of a flight.
 *
 * @param flight FlightInfo pointer of type 'FlightInfo*'.
 * @return char* Origin of type 'char*'.
 */
char *get_origin(FlightInfo *flight);

/**
 * @brief Gets the destination of a flight.
 *
 * @param flight FlightInfo pointer of type 'FlightInfo*'.
 * @return char* Destination of type 'char*'.
 */
char *get_destination(FlightInfo *flight);

/**
 * @brief Gets the schedule departure date of a flight.
 *
 * @param flight FlightInfo pointer of type 'FlightInfo*'.
 * @return guint32 Schedule departure date of type 'guint32'.
 */
guint32 get_schedule_departure_date(FlightInfo *flight);

/**
 * @brief Gets the schedule arrival date of a flight.
 *
 * @param flight FlightInfo pointer of type 'FlightInfo*'.
 * @return guint32 Schedule arrival date of type 'guint32'.
 */
guint32 get_schedule_arrival_date(FlightInfo *flight);

/**
 * @brief Gets the real departure date of a flight.
 *
 * @param flight FlightInfo pointer of type 'FlightInfo*'.
 * @return guint32 Real departure date of type 'guint32'.
 */
guint32 get_real_departure_date(FlightInfo *flight);

/**
 * @brief Frees the memory allocated to a flight.
 *
 * @param flight FlightInfo pointer of type 'FlightInfo*'.
 */
void destroy_flight(FlightInfo *flight);

#endif
