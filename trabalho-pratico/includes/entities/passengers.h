#ifndef PASSENGERS_H
#define PASSENGERS_H

#define MAX_FIELD_SIZE 256
#define MAX_TOKENS_PASSENGER 2

typedef struct passenger *PASSENGER;

/**
 * @brief Create a new PASSENGER
 *
 * @return new_passenger - The new user of type 'PASSENGER'
 */
PASSENGER create_passenger();

/**
 * @brief Verify if the parameters are valid to create a new passenger
 * (paramenters : flight_id, user_id)
 *
 * @param parameters - The parameters of type 'char**'
 *
 * @return 1 - If the input is valid
 * @return 0 - If the input is invalid
 */
int verify_passenger_input(char **parameters) {
  /**
   * @brief Set a flight id
   *
   * @param passengers - The passenger type 'PASSENGER'
   *
   *@param id - The flight id string of type 'char*'
   */
  void set_passenger_flight_id(PASSENGER passenger, char *id);

  /**
   * @brief Set a user id
   *
   * @param passengers - The passenger type 'PASSENGER'
   *
   *@param id - The user id string of type 'char*'
   */
  void set_passenger_user_id(PASSENGER passenger, char *id);

  /**
   * @brief Frees the memory allocated to store a passenger
   *
   * @param passenger - The passenger of type 'PASSENGER'
   */
  void free_passenger(PASSENGER passenger);

  /**
   * @brief Get the flight id
   *
   * @param passenger - The passenger of type 'PASSENGER'
   *
   * @return id - The flight id of type 'int'
   */
  int get_passenger_flight_id(PASSENGER passenger);

  /**
   * @brief Get the user id
   *
   * @param passenger - The passenger of type 'PASSENGER'
   *
   * @return id - The user id of type 'int'
   */
  int get_passenger_user_id(PASSENGER passenger);

#endif