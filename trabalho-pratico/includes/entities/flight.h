#ifndef FLIGHT_H
#define FLIGHT_H


typedef struct Flight *Flight;

/**
 * @brief Create a new flight
 * 
 * @return new_flight - The new flight of type 'Flight' 
 */
Flight create_flight();

/**
 * @brief Set the flight id
 * 
 * @param flight - The flight of type 'Flight'
 * @param id - The id string of type 'char*'
 */
void set_flight_id(Flight flight ,char *id);

/**
 * @brief Set the flight ariline
 * 
 * @param flight - The flight of type 'Flight'
 * @param airline - The airline string of type 'char*'
 */
void set_flight_airline(Flight flight, char *airline);

/**
 * @brief Set the flight plane model
 * 
 * @param flight - The flight of type 'Flight'
 * @param plane_modal - The plane_modal string of type 'char*'
 */

void set_flight_planel_model(Flight flight ,char *planel_model);

/**
 * @brief Set the flight total seats
 * 
 * @param flight - The flight of type 'flight'
 * @param total_seats - The total_setas  integer of type 'int'
 */
void set_flight_total_seats(Flight flight ,int total_seats);

/**
 * @brief Set the flight origin
 * 
 * @param flight - The flight of type 'flight'
 * @param origin - The origin string of type 'char*'
 */
void set_flight_origin(Flight flight ,char *origin);

/**
 * @brief Set the flight schedule departure date
 * 
 * @param flight - The flight of type 'flight'
 * @param schedule_departure_date - The schedule departure date (aaaa/MM/dd hh:mm:ss) string of type 'char*'
 */
void set_flight_schedule_departure_date(Flight flight, char *schedule_departure_date);

/**
 * @brief Set the flight schedule arrival date
 * 
 * @param flight - The flight of type 'flight'
 * @param schedule_arrival_date - The schedule arrival date (aaaa/MM/dd hh:mm:ss) string of type 'char*'
 */
void set_flight_schedule_arrival_date(Flight flight, char *schedule_arrival_date);

/**
 * @brief Set the flight real departure date
 * 
 * @param flight - The flight of type 'flight'
 * @param real_departure_date - The real departure date (aaaa/MM/dd hh:mm:ss) string of type 'char*'
 */
void set_flight_real_departure_date(Flight flight, char *real_departure_date);

/**
 * @brief Set the flight real arrival date
 * 
 * @param flight - The flight of type 'flight'
 * @param real_arrival_date - The real arrival date (aaaa/MM/dd hh:mm:ss) string of type 'char*'
 */
void set_flight_real_arrival_date(Flight flight, char *real_arrival_date);

/**
 * @brief Set the flight pilot
 * 
 * @param flight - The flight of type 'User'
 * @param pilot - The pilot string of type 'char*'
 */
void set_flight_pilot(Flight flight, char *pilot);

/**
 * @brief Set the flight copilot
 * 
 * @param flight - The flight of type 'User'
 * @param copilot - The copilot string of type 'char*'
 */
void set_flight_copilot(Flight flight, char *copilot);

/**
 * @brief Set the flight notes
 * 
 * @param flight - The flight of type 'User'
 * @param notes - The notes string of type 'char*'
 */
void set_flight_note(Flight flight, char *notes);

/**
 * @brief Frees the memory allocated to store a flight
 * 
 * @param flight - The flight of type 'flight'
 */
void free_flight(Flight flight);


#endif
