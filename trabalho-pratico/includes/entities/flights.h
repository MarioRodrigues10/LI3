#ifndef FLIGHTS_H
#define FLIGHTS_H

#include "base/stats.h"
#include "catalogs/flights_catalog.h"

#define MAX_FIELD_SIZE 256
#define MAX_TOKENS_FLIGHT 13
typedef struct flight *FLIGHT;

/**
 * @brief Function that creates the flight
 *
 * @return The flight created
 */
FLIGHT create_flight();

/**
 * @brief Function that builds the flight
 *
 * @param flight_params - The flight parameters of type 'char*'
 * @param catalog - The catalog of type 'void*'
 * @param stats - The stats of type 'STATS'
 *
 */
void build_flight(char **flight_params, void *catalog, STATS stats);

/**
 * @brief Function that verifies if the paramenters are valid to create a new
 * flight (parameters : id, airline, plane_model, total_seats, origin,
 * schedule_departure_date, schedule_arrival_date, real_departure_date,
 * real_arrival_date, pilot, copilot, notes)
 *
 * @param parameters - The parameters of type 'char**'
 *
 * @return 1 if the parameters are valid, 0 otherwise
 */
int verify_flight_input(char **parameters);

/**
 * @brief Function that sets the flight id
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param id - The id string of type 'char*'
 */
void set_flight_id(FLIGHT flight, char *id);

/**
 * @brief Function that sets the flight airline
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param airline - The airline string of type 'char*'
 */
void set_flight_airline(FLIGHT flight, char *airline);

/**
 * @brief Function that sets the flight plane model
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param plane_model - The plane_model string of type 'char*'
 */
void set_flight_planel_model(FLIGHT flight, char *plane_model);

/**
 * @brief Function that sets the flight total seats
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param total_seats - The total_seats of type 'int'
 */
void set_flight_total_seats(FLIGHT flight, int total_seats);

/**
 * @brief Function that sets the flight origin
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param origin - The origin string of type 'char*'
 */
void set_flight_origin(FLIGHT flight, char *origin);

/**
 * @brief Function that sets the flight destination
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param destination - The destination string of type 'char*'
 */
void set_flight_destination(FLIGHT flight, char *destination);

/**
 * @brief Function that sets the flight schedule departure date
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param schedule_departure_date - The schedule departure date (aaaa/MM/dd
 * hh:mm:ss) string of type 'char*'
 */
void set_flight_schedule_departure_date(FLIGHT flight,
                                        char *schedule_departure_date);

/**
 * @brief Function that sets the flight schedule arrival date
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param schedule_arrival_date - The schedule arrival date (aaaa/MM/dd
 * hh:mm:ss) string of type 'char*'
 */
void set_flight_schedule_arrival_date(FLIGHT flight,
                                      char *schedule_arrival_date);

/**
 * @brief Function that sets the flight real departure date
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param real_departure_date - The real departure date (aaaa/MM/dd hh:mm:ss)
 * string of type 'char*'
 */
void set_flight_real_departure_date(FLIGHT flight, char *real_departure_date);

/**
 * @brief Function that sets the flight real arrival date
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param real_arrival_date - The real arrival date (aaaa/MM/dd hh:mm:ss) string
 * of type 'char*'
 */
void set_flight_real_arrival_date(FLIGHT flight, char *real_arrival_date);

/**
 * @brief Function that sets the flight pilot
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param pilot - The pilot string of type 'char*'
 */
void set_flight_pilot(FLIGHT flight, char *pilot);

/**
 * @brief Function that sets the flight copilot
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param copilot - The copilot string of type 'char*'
 */
void set_flight_copilot(FLIGHT flight, char *copilot);

/**
 * @brief Function that sets the flight notes
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param notes - The notes string of type 'char*'
 */
void set_flight_notes(FLIGHT flight, char *notes);

/**
 * @brief Function that frees the memory alocated to the flight
 *
 * @param flight - The flight of type 'FLIGHT'
 */
void free_flight(FLIGHT flight);

/**
 * @brief Function that gets the flight id
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return id - The flight id of type 'char'
 */
char *get_flight_id(FLIGHT flight);

/**
 * @brief Function that gets the flight airline
 *
 * @param flight - The flight of type 'FlIGHT'
 *
 * @return airline - The flight airline of type 'char*'
 */
char *get_flight_airline(FLIGHT flight);

/**
 * @brief Function that gets the flight plane model
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return plane_model - The flight plane model of type 'char*'
 */
char *get_flight_plane_model(FLIGHT flight);

/**
 * @brief Function that gets the flight total seats
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return total_seats - The flight total seats of type 'int'
 */
int get_flight_total_seats(FLIGHT flight);

/**
 * @brief Function that gets the flight origin
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return origin - The flight origin of type 'char*'
 */
char *get_flight_origin(FLIGHT flight);

/**
 * @brief Function that gets the flight destination
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return destination - The flight destination of type 'char*'
 *
 */
char *get_flight_destination(FLIGHT flight);

/**
 * @brief Function that gets the flight schedule departure date
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return schedule_departure_date - The flight schedule departure date of type
 * 'char*'
 */
char *get_flight_schedule_departure_date(FLIGHT flight);

/**
 * @brief Function that gets the flight schedule arrival date
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return schedule_arrival_date - The flight schedule arrival date of type
 * 'char*'
 */
char *get_flight_schedule_arrival_date(FLIGHT flight);

/**
 * @brief Function that gets the flight real departure date
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return real_departure_date - The flight real departure date of type 'char*'
 */
char *get_flight_real_departure_date(FLIGHT flight);

/**
 * @brief Function that gets the flight real arrival date
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return real_arrival_date - The flight real arrival date of type 'char*'
 */
char *get_flight_real_arrival_date(FLIGHT flight);

/**
 * @brief Function that gets the flight pilot
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return pilot - The flight pilot of type 'char*'
 */
char *get_flight_pilot(FLIGHT flight);

/**
 * @brief Function that gets the flight copilot
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return copilot - The flight copilot of type 'char*'
 */
char *get_flight_copilot(FLIGHT flight);

/**
 * @brief Function that gets the flight notes
 *
 * @param flight - The flight of type 'FlIGHT'
 *
 * @return notes - The flight notes of type 'char*'
 */
char *get_flight_notes(FLIGHT flight);

#endif
