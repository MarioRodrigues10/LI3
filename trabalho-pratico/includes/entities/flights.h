#ifndef FLIGHTS_H
#define FLIGHTS_H

typedef struct Flight *FLIGHT;

/**
 * @brief Create a new flight
 *
 * @return new_flight - The new flight of type 'FLIGHT'
 */
FLIGHT create_flight();

/**
 * @brief Verify if the paramenters is valid to create a new flight (parameters
 * : id, airline, plane_model, total_seats, origin, schedule_departure_date,
 * schedule_arrival_date, real_departure_date, real_arrival_date, pilot,
 * copilot, notes)
 *
 * @param parameters - The parameters of type 'char**'
 *
 *
 * @return 1 - If the input is valid
 * @return 0 - If the input is invalid
 */
int verify_flight_input(char **parameters);

/**
 * @brief Set the flight id
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param id - The id string of type 'char*'
 */
void set_flight_id(FLIGHT flight, char *id);
/**
 * @brief Set the flight ariline
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param airline - The airline string of type 'char*'
 */
void set_flight_airline(FLIGHT flight, char *airline);

/**
 * @brief Set the flight plane model
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param plane_modal - The plane_modal string of type 'char*'
 */
void set_flight_planel_model(FLIGHT flight, char *plane_modal);

/**
 * @brief Set the flight total seats
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param total_seats - The total_setas  integer of type 'int'
 */
void set_flight_total_seats(FLIGHT flight, int total_seats);

/**
 * @brief Set the flight origin
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param origin - The origin string of type 'char*'
 */
void set_flight_origin(FLIGHT flight, char *origin);

/**
 * @brief Set the flight schedule departure date
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param schedule_departure_date - The schedule departure date (aaaa/MM/dd
 * hh:mm:ss) string of type 'char*'
 */
void set_flight_schedule_departure_date(FLIGHT flight,
                                        char *schedule_departure_date);

/**
 * @brief Set the flight schedule arrival date
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param schedule_arrival_date - The schedule arrival date (aaaa/MM/dd
 * hh:mm:ss) string of type 'char*'
 */
void set_flight_schedule_arrival_date(FLIGHT flight,
                                      char *schedule_arrival_date);

/**
 * @brief Set the flight real departure date
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param real_departure_date - The real departure date (aaaa/MM/dd hh:mm:ss)
 * string of type 'char*'
 */
void set_flight_real_departure_date(FLIGHT flight, char *real_departure_date);

/**
 * @brief Set the flight real arrival date
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param real_arrival_date - The real arrival date (aaaa/MM/dd hh:mm:ss) string
 * of type 'char*'
 */
void set_flight_real_arrival_date(FLIGHT flight, char *real_arrival_date);

/**
 * @brief Set the flight pilot
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param pilot - The pilot string of type 'char*'
 */
void set_flight_pilot(FLIGHT flight, char *pilot);

/**
 * @brief Set the flight copilot
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param copilot - The copilot string of type 'char*'
 */
void set_flight_copilot(FLIGHT flight, char *copilot);

/**
 * @brief Set the flight notes
 *
 * @param flight - The flight of type 'FLIGHT'
 * @param notes - The notes string of type 'char*'
 */
void set_flight_note(FLIGHT flight, char *notes);

/**
 * @brief Frees the memory allocated to store a flight
 *
 * @param flight - The flight of type 'FLIGHT'
 */
void free_flight(FLIGHT flight);

/**
 * @brief Get the flight id
 *
 * @param flight - The flight of type 'FLIGHT'
 *
 * @return id - The flight id of type 'int'
 */
int get_flight_id(FLIGHT flight);

/**
 * @brief Get the flight airline
 *
 * @param flight - The flight of type 'FlIGHT'
 *
 * @return airline - The flight airline of type 'char*'
 */
char *get_flight_airline(FLIGHT flight);

/**
 * @brief Get the flight plane model
 *
 * @param flight - The flight of type 'FlIGHT'
 *
 * @return plane_model - The flight plane model of type 'char*'
 */
char *get_flight_plane_model(FLIGHT flight);

/**
 * @brief Get the flight total seats
 *
 * @param flight - The flight of type 'FlIGHT'
 *
 * @return total_seats - The flight total seats of type 'int'
 */
int get_flight_total_seats(FLIGHT flight);

/**
 * @brief Get the flight origin
 *
 * @param flight - The flight of type 'FlIGHT'
 *
 * @return origin - The flight origin of type 'char*'
 */
char *get_flight_origin(FLIGHT flight);

/**
 * @brief Get the flight schedule departure date
 *
 * @param flight - The flight of type 'FlIGHT'
 *
 * @return schedule_departure_date - The flight schedule departure date of type
 * 'char*'
 */
char *get_flight_schedule_departure_date(FLIGHT flight);

/**
 * @brief Get the flight schedule arrival date
 *
 * @param flight - The flight of type 'FlIGHT'
 *
 * @return schedule_arrival_date - The flight schedule arrival date of type
 * 'char*'
 */
char *get_flight_schedule_arrival_date(FLIGHT flight);

/**
 * @brief Get the flight real departure date
 *
 * @param flight - The flight of type 'FlIGHT'
 *
 * @return real_departure_date - The flight real departure date of type 'char*'
 */
char *get_flight_real_departure_date(FLIGHT flight);

/**
 * @brief Get the flight real arrival date
 *
 * @param flight - The flight of type 'FlIGHT'
 *
 * @return real_arrival_date - The flight real arrival date of type 'char*'
 */
char *get_flight_real_arrival_date(FLIGHT flight);

/**
 * @brief Get the flight pilot
 *
 * @param flight - The flight of type 'FlIGHT'
 *
 * @return pilot - The flight pilot of type 'char*'
 */
char *get_flight_pilot(FLIGHT flight);

/**
 * @brief Get the flight copilot
 *
 * @param flight - The flight of type 'FlIGHT'
 *
 * @return copilot - The flight copilot of type 'char*'
 */
char *get_flight_copilot(FLIGHT flight);

/**
 * @brief Get the flight notes
 *
 * @param flight - The flight of type 'FlIGHT'
 *
 * @return notes - The flight notes of type 'char*'
 */
char *get_flight_notes(FLIGHT flight);

#endif
