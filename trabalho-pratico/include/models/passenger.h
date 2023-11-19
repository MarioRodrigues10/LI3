#ifndef PASSENGER_H
#define PASSENGER_H

#define MAX_TOKENS_PASSENGER 2

typedef struct passenger PassengerInfo;

/**
 * @brief Allocates the memory necessary to create a new passenger.
 *
 * @return PassengerInfo pointer of type 'PassengerInfo*' to the allocated
 * memory.
 */
PassengerInfo *create_passenger();

/**
 * @brief Sets the flight id of a passenger.
 *
 * @param passenger PassengerInfo pointer of type 'PassengerInfo*'.
 * @param flight_id Flight id of type 'char*'.
 */
void set_flight_id_passenger(PassengerInfo *passenger, char *flight_id);

/**
 * @brief Sets the user id of a passenger.
 *
 * @param passenger PassengerInfo pointer of type 'PassengerInfo*'.
 * @param user_id User id of type 'char*'.
 */
void set_user_id_passenger(PassengerInfo *passenger, char *user_id);

/**
 * @brief Gets the flight id of a passenger.
 *
 * @param passenger PassengerInfo pointer of type 'PassengerInfo*'.
 * @return char pointer of type 'char*'.
 */
char *get_flight_id_passenger(PassengerInfo *passenger);

/**
 * @brief Gets the user id of a passenger.
 *
 * @param passenger PassengerInfo pointer of type 'PassengerInfo*'.
 * @return char pointer of type 'char*'.
 */
char *get_user_id_passenger(PassengerInfo *passenger);

/**
 * @brief Frees the memory allocated to a passenger.
 *
 * @param passenger PassengerInfo pointer of type 'PassengerInfo*'.
 */
void destroy_passenger(PassengerInfo *passenger);

#endif
