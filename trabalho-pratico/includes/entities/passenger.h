#ifndef PASSENGER_H
#define PASSENGER_H

typedef struct passenger *Passenger;

/**
 * @brief Create a new Passenger
 *
 * @return new_passenger - The new user of type 'Passenger'
 */
Passenger create_passenger();

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

  /**
   * @brief Frees the memory allocated to store a passenger
   *
   * @param passenger - The passenger of type 'Passenger'
   */
  void free_passenger(Passenger passenger);

  /**
   * @brief Get the flight id
   *
   * @param passenger - The passenger of type 'Passenger'
   *
   * @return id - The flight id of type 'int'
   */
  int get_passenger_flight_id(Passenger passenger);

  /**
   * @brief Get the user id
   *
   * @param passenger - The passenger of type 'Passenger'
   *
   * @return id - The user id of type 'int'
   */
  int get_passenger_user_id(Passenger passenger);

#endif