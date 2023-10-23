#ifndef FLIGHT_H
#define FLIGHT_H

typedef struct Flight *Flight;

/**
 * @brief Create a new flight
 *
 * @return new_flight - The new flight of type 'Flight'
 */
Flight createFlight();

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
int verifyFlightInput(char **parameters);

/**
 * @brief Set the flight id
 *
 * @param flight - The flight of type 'Flight'
 * @param id - The id string of type 'char*'
 */
void setFlightId(Flight flight, char *id);
/**
 * @brief Set the flight ariline
 *
 * @param flight - The flight of type 'Flight'
 * @param airline - The airline string of type 'char*'
 */
void setFlightAirline(Flight flight, char *airline);

/**
 * @brief Set the flight plane model
 *
 * @param flight - The flight of type 'Flight'
 * @param plane_modal - The plane_modal string of type 'char*'
 */
void setFlightPlanelModel(Flight flight, char *plane_modal);

/**
 * @brief Set the flight total seats
 *
 * @param flight - The flight of type 'flight'
 * @param total_seats - The total_setas  integer of type 'int'
 */
void setFlightTotalSeats(Flight flight, int total_seats);

/**
 * @brief Set the flight origin
 *
 * @param flight - The flight of type 'flight'
 * @param origin - The origin string of type 'char*'
 */
void setFlightOrigin(Flight flight, char *origin);

/**
 * @brief Set the flight schedule departure date
 *
 * @param flight - The flight of type 'flight'
 * @param schedule_departure_date - The schedule departure date (aaaa/MM/dd
 * hh:mm:ss) string of type 'char*'
 */
void setFlightScheduleDepartureDate(Flight flight,
                                    char *schedule_departure_date);

/**
 * @brief Set the flight schedule arrival date
 *
 * @param flight - The flight of type 'flight'
 * @param schedule_arrival_date - The schedule arrival date (aaaa/MM/dd
 * hh:mm:ss) string of type 'char*'
 */
void setFlightScheduleArrivalDate(Flight flight, char *schedule_arrival_date);

/**
 * @brief Set the flight real departure date
 *
 * @param flight - The flight of type 'flight'
 * @param real_departure_date - The real departure date (aaaa/MM/dd hh:mm:ss)
 * string of type 'char*'
 */
void setFlightRealDepartureDate(Flight flight, char *real_departure_date);

/**
 * @brief Set the flight real arrival date
 *
 * @param flight - The flight of type 'flight'
 * @param real_arrival_date - The real arrival date (aaaa/MM/dd hh:mm:ss) string
 * of type 'char*'
 */
void setFlightRealArrivalDate(Flight flight, char *real_arrival_date);

/**
 * @brief Set the flight pilot
 *
 * @param flight - The flight of type 'User'
 * @param pilot - The pilot string of type 'char*'
 */
void setFlightPilot(Flight flight, char *pilot);

/**
 * @brief Set the flight copilot
 *
 * @param flight - The flight of type 'User'
 * @param copilot - The copilot string of type 'char*'
 */
void setFlightCopilot(Flight flight, char *copilot);

/**
 * @brief Set the flight notes
 *
 * @param flight - The flight of type 'User'
 * @param notes - The notes string of type 'char*'
 */
void setFlightNote(Flight flight, char *notes);

/**
 * @brief Frees the memory allocated to store a flight
 *
 * @param flight - The flight of type 'flight'
 */
void freeFlight(Flight flight);

/**
 * @brief Get the flight id
 *
 * @param flight - The flight of type 'flight'
 *
 * @return id - The flight id of type 'int'
 */
int getFlightId(Flight flight);

/**
 * @brief Get the flight airline
 *
 * @param flight - The flight of type 'flight'
 *
 * @return airline - The flight airline of type 'char*'
 */
char *getFlightAirline(Flight flight);

/**
 * @brief Get the flight plane model
 *
 * @param flight - The flight of type 'flight'
 *
 * @return plane_model - The flight plane model of type 'char*'
 */
char *getFlightPlaneModel(Flight flight);

/**
 * @brief Get the flight total seats
 *
 * @param flight - The flight of type 'flight'
 *
 * @return total_seats - The flight total seats of type 'int'
 */
int getFlightTotalSeats(Flight flight);

/**
 * @brief Get the flight origin
 *
 * @param flight - The flight of type 'flight'
 *
 * @return origin - The flight origin of type 'char*'
 */
char *getFlightOrigin(Flight flight);

/**
 * @brief Get the flight schedule departure date
 *
 * @param flight - The flight of type 'flight'
 *
 * @return schedule_departure_date - The flight schedule departure date of type
 * 'char*'
 */
char *getFlightScheduleDepartureDate(Flight flight);

/**
 * @brief Get the flight schedule arrival date
 *
 * @param flight - The flight of type 'flight'
 *
 * @return schedule_arrival_date - The flight schedule arrival date of type
 * 'char*'
 */
char *getFlightScheduleArrivalDate(Flight flight);

/**
 * @brief Get the flight real departure date
 *
 * @param flight - The flight of type 'flight'
 *
 * @return real_departure_date - The flight real departure date of type 'char*'
 */
char *getFlightRealDepartureDate(Flight flight);

/**
 * @brief Get the flight real arrival date
 *
 * @param flight - The flight of type 'flight'
 *
 * @return real_arrival_date - The flight real arrival date of type 'char*'
 */
char *getFlightRealArrivalDate(Flight flight);

/**
 * @brief Get the flight pilot
 *
 * @param flight - The flight of type 'flight'
 *
 * @return pilot - The flight pilot of type 'char*'
 */
char *getFlightPilot(Flight flight);

/**
 * @brief Get the flight copilot
 *
 * @param flight - The flight of type 'flight'
 *
 * @return copilot - The flight copilot of type 'char*'
 */
char *getFlightCopilot(Flight flight);

/**
 * @brief Get the flight notes
 *
 * @param flight - The flight of type 'flight'
 *
 * @return notes - The flight notes of type 'char*'
 */
char *getFlightNotes(Flight flight);

#endif
