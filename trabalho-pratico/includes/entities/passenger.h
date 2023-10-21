#ifndef PASSENGER_H
#define PASSENGER_H


typedef struct passenger *Passenger;

/**
 * @brief Creat a new Passenger
 * 
 * @return new_passenger - The new user of type 'Passenger' 
 */
creat_passenger creat_passenger();

/**
 * @brief Set a flight id
 * 
 * @param passengers - The passenger type 'Passenger'
 * 
 *@param id - The flight id string of type 'char*'
 */
void set_passenger_flight_id(Passenger passenger, char *id);

/**
 * @brief Set a user id
 * 
 * @param passengers - The passenger type 'Passenger'
 * 
 *@param id - The user id string of type 'char*'
 */
void set_passenger_user_id(Passenger passenger, char *id);


#endif