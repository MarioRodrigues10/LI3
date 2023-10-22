#ifndef PASSENGER_H
#define PASSENGER_H


typedef struct passenger *Passenger;

/**
 * @brief Create a new Passenger
 * 
 * @return new_passenger - The new user of type 'Passenger' 
 */
Passenger createPassenger();

/**
 * @brief Verify if the parameters are valid to create a new passenger (paramenters : flight_id, user_id)
 * 
 * @param parameters - The parameters of type 'char**'
 * 
 * @return 1 - If the input is valid
 * @return 0 - If the input is invalid
 */
int verifyPassengerInput(char **parameters){

/**
 * @brief Set a flight id
 * 
 * @param passengers - The passenger type 'Passenger'
 * 
 *@param id - The flight id string of type 'char*'
 */
void setPassengerFlightId(Passenger passenger, char *id);

/**
 * @brief Set a user id
 * 
 * @param passengers - The passenger type 'Passenger'
 * 
 *@param id - The user id string of type 'char*'
 */
void setPassengerUserId(Passenger passenger, char *id);

/**
 * @brief Frees the memory allocated to store a passenger
 * 
 * @param passenger - The passenger of type 'Passenger'
 */
void freePassenger(Passenger passenger);

/**
 * @brief Get the flight id
 * 
 * @param passenger - The passenger of type 'Passenger'
 * 
 * @return id - The flight id of type 'int'
 */
int getPassengerFlightId(Passenger passenger);

/**
 * @brief Get the user id
 * 
 * @param passenger - The passenger of type 'Passenger'
 * 
 * @return id - The user id of type 'int'
 */
int getPassengerUserId(Passenger passenger);

#endif