#ifndef RESERVATIONS_H
#define RESERVATIONS_H

#define MAX_FIELD_SIZE 256
#define MAX_TOKENS_RESERVATION 14

typedef struct reservation *RESERVATION;

/**
 * @brief Create a new reservations
 *
 * @return new_driver - The new driver of type `Resevations`
 */
RESERVATION create_reservation();

/**
 * @brief Verify if the paramenters is valid to create a new reservation
 * (parameters : id, user_id, hotel_id, hotel_name, hotel_starts, city_tax,
 * address, begin_date, end_date, price_per_night, include_breakfast,
 * room_detail, rating, comment)
 *
 * @param parameters - The parameters of type 'char**'
 *
 *
 * @return 1 - If the input is valid
 * @return 0 - If the input is invalid
 */
int verify_reservation_input(char **parameters);

/**
 * @brief Set the reservation id
 *
 * @param reservation - The Resevation of type 'RESERVATION'
 * @param id - The id string of type 'char*'
 */
void set_reservation_id(RESERVATION reservation, char *id);

/**
 * @brief Set the reservation Resevation id
 *
 * @param reservation - The Resevation of type 'RESERVATION'
 * @param user_id - The Resevation id string of type 'char*'
 */
void set_reservation_user_id(RESERVATION reservation, char *id);

/**
 * @brief Set the hotel id
 *
 * @param reservation - The Resevation of type 'RESERVATION'
 * @param hotel_id - The hotel id string of type 'char*'
 */
void set_reservation_hotel_id(RESERVATION reservation, char *id);

/**
 * @brief Set the hotel name
 *
 * @param reservation - The Resevation of type 'RESERVATION'
 * @param hotel_name - The hotel name string of type 'char*'
 */
void set_reservation_hotel_name(RESERVATION reservation, char *hotel_name);

/**
 * @brief Set the reservation hotel starts
 *
 * @param reservation - The Resevation of type 'RESERVATION'
 * @param starts - The starts integer of type 'int'
 */
void set_reservation_hotel_starts(RESERVATION reservation, int starts);

/**
 * @brief Set the reservation city tax
 *
 * @param reservation - The Resevation of type 'RESERVATION'
 * @param city_tax - The tax integer of type 'int'
 */
void set_reservation_city_tax(RESERVATION reservation, int tax);

/**
 * @brief Set the reservation address
 *
 * @param reservation - The Resevation of type 'RESERVATION'
 * @param address - The address string of type 'char*'
 */
void set_reservation_address(RESERVATION reservation, char *address);

/**
 * @brief Set the reservation begin date
 *
 * @param reservation - The Resevation of type 'RESERVATION'
 * @param begin_date - The begin date string of type 'char*'
 */
void set_reservation_begin_date(RESERVATION reservation, char *begin_date);

/**
 * @brief Set the reservation end date
 *
 * @param reservation - The Resevation of type 'RESERVATION'
 * @param end_date - The end date string of type 'char*'
 */
void set_reservation_end_date(RESERVATION reservation, char *end_date);

/**
 * @brief Set the reservation price per night
 *
 * @param reservation - The Resevation of type 'RESERVATION'
 * @param price_per_night - The price_per_night integer of type 'int'
 */
void set_reservation_price_per_night(RESERVATION reservation,
                                     int price_per_ninght);

/**
 * @brief Set the reservation include breakfast
 *
 * @param reservation - The Resevation of type 'RESERVATION'
 * @param include_breakfast - The include breakfast string of type 'char*'
 */
void set_reservation_include_breakfast(RESERVATION reservation,
                                       char *include_breakfast);

/**
 * @brief Set the reservation room details
 *
 * @param reservation - The Resevation of type 'RESERVATION'
 * @param room_details - The room details string of type 'char*'
 */
void set_reservation_room_detail(RESERVATION reservation, char *room_detail);

/**
 * @brief Set the reservation rating
 *
 * @param reservation - The Resevation of type 'RESERVATION'
 * @param rating - The rating integer of type 'char*'
 */
void set_reservation_rating(RESERVATION reservation, int rating);

/**
 * @brief Set the reservation icomment
 *
 * @param reservation - The Resevation of type 'RESERVATION'
 * @param comment - The comment string of type 'char*'
 */
void set_reservation_comment(RESERVATION reservation, char *comment);

/**
 * @brief Frees the reservations allocated to store a reservation
 *
 * @param reservation - The Resevation of type 'RESERVATION'
 */
void free_reservation(RESERVATION reservation);

/**
 * @brief Get the Resevation id
 *
 * @param Resevation - The Resevation of type 'REservations'
 * @return id - The id integer of type 'int'
 */
int get_reservation_id(RESERVATION reservation);

/**
 * @brief Get the Resevation id
 *
 * @param Resevation - The Resevation of type 'RESERVATION'
 * @return id - The id integer of type 'int'
 */
int get_user_id(RESERVATION reservation);

/**
 * @brief Get the hotel id
 *
 * @param Resevation - The Resevation of type 'RESERVATION'
 * @return id - The id integer of type 'int'
 */
int get_hotel_id(RESERVATION reservation);

/**
 * @brief Get the Resevation hotel name
 *
 * @param Resevation - The Resevation of type 'RESERVATION'
 * @return hotel_name - The hotel name string of type 'char*'
 */
char *get_reservation_hotel_name(RESERVATION reservation);

/**
 * @brief Get the Resevation hotel starts
 *
 * @param Resevation - The Resevation of type 'RESERVATION'
 * @return starts - The starts integer of type 'int'
 */
int get_reservation_hotel_starts(RESERVATION reservation);

/**
 * @brief Get the Resevation city tax
 *
 * @param Resevation - The Resevation of type 'RESERVATION'
 * @return tax - The tax integer of type 'int'
 */
double get_reservation_city_tax(RESERVATION reservation);

/**
 * @brief Get the Resevation address
 *
 * @param Resevation - The Resevation of type 'RESERVATION'
 * @return address - The address string of type 'char*'
 */
char *get_reservation_address(RESERVATION reservation);

/**
 * @brief Get the Resevation begin date
 *
 * @param Resevation - The Resevation of type 'RESERVATION'
 * @return begin_date - The begin date string of type 'char*'
 */
char *get_reservation_begin_date(RESERVATION reservation);

/**
 * @brief Get the Resevation end date
 *
 * @param Resevation - The Resevation of type 'RESERVATION'
 * @return end_date - The end date string of type 'char*'
 */
char *get_reservation_end_date(RESERVATION reservation);

/**
 * @brief Get the Resevation price per night
 *
 * @param Resevation - The Resevation of type 'RESERVATION'
 * @return price_per_night - The price per night integer of type 'int'
 */
int get_reservation_price_per_night(RESERVATION reservation);

/**
 * @brief Get the Resevation include breakfast
 *
 * @param Resevation - The Resevation of type 'RESERVATION'
 * @return include_breakfast - The include breakfast string of type 'char*'
 */
char *get_reservation_include_breakfast(RESERVATION reservation);

/**
 * @brief Get the Resevation room details
 *
 * @param Resevation - The Resevation of type 'RESERVATION'
 * @return room_details - The room details string of type 'char*'
 */
char *get_reservation_room_detail(RESERVATION reservation);

/**
 * @brief Get the Resevation rating
 *
 * @param Resevation - The Resevation of type 'RESERVATION'
 * @return rating - The rating integer of type 'int'
 */
int get_reservation_rating(RESERVATION reservation);

/**
 * @brief Get the Resevation comment
 *
 * @param Resevation - The Resevation of type 'RESERVATION'
 * @return comment - The comment string of type 'char*'
 */
char *get_reservation_comment(RESERVATION reservation);

#endif