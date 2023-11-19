#ifndef RESERVATION_H
#define RESERVATION_H

#define MAX_TOKENS_RESERVATION 14

typedef struct reservation ReservationInfo;

/**
 * @brief Allocates the memory necessary to create a new reservation.
 *
 * @return ReservationInfo pointer of type 'ReservationInfo*' to the allocated
 * memory.
 */
ReservationInfo *create_reservation();

/**
 * @brief Sets the reservation id of a reservation.
 *
 * @param reservation ReservationInfo pointer of type 'ReservationInfo*'.
 * @param reservation_id Reservation id of type 'char*'.
 */
void set_reservation_id(ReservationInfo *reservation, char *reservation_id);

/**
 * @brief Sets the user id of a reservation.
 *
 * @param reservation ReservationInfo pointer of type 'ReservationInfo*'.
 * @param user_id User id of type 'char*'.
 */
void set_user_id_reservation(ReservationInfo *reservation, char *user_id);

/**
 * @brief Sets the hotel id of a reservation.
 *
 * @param reservation ReservationInfo pointer of type 'ReservationInfo*'.
 * @param hotel_id Hotel id of type 'char*'.
 */
void set_hotel_id(ReservationInfo *reservation, char *hotel_id);

/**
 * @brief Sets the hotel name of a reservation.
 *
 * @param reservation ReservationInfo pointer of type 'ReservationInfo*'.
 * @param hotel_name Hotel name of type 'char*'.
 */
void set_hotel_name(ReservationInfo *reservation, char *hotel_name);

/**
 * @brief Sets the hotel stars of a reservation.
 *
 * @param reservation ReservationInfo pointer of type 'ReservationInfo*'.
 * @param hotel_stars Hotel stars of type 'int'.
 */
void set_hotel_stars(ReservationInfo *reservation, int hotel_stars);

/**
 * @brief Sets the city tax of a reservation.
 *
 * @param reservation ReservationInfo pointer of type 'ReservationInfo*'.
 * @param city_tax City tax of type 'int'.
 */
void set_city_tax(ReservationInfo *reservation, int city_tax);

/**
 * @brief Sets the begin date of a reservation.
 *
 * @param reservation ReservationInfo pointer of type 'ReservationInfo*'.
 * @param begin_date Begin date of type 'char*'.
 */
void set_begin_date(ReservationInfo *reservation, char *begin_date);

/**
 * @brief Sets the end date of a reservation.
 *
 * @param reservation ReservationInfo pointer of type 'ReservationInfo*'.
 * @param end_date End date of type 'char*'.
 */
void set_end_date(ReservationInfo *reservation, char *end_date);

/**
 * @brief Sets the price per night of a reservation.
 *
 * @param reservation ReservationInfo pointer of type 'ReservationInfo*'.
 * @param price_per_night Price per night of type 'int'.
 */
void set_price_per_night(ReservationInfo *reservation, int price_per_night);

/**
 * @brief Sets the includes breakfast of a reservation.
 *
 * @param reservation ReservationInfo pointer of type 'ReservationInfo*'.
 * @param includes_breakfast Includes breakfast of type 'char*'.
 */
void set_includes_breakfast(ReservationInfo *reservation,
                            char *includes_breakfast);

/**
 * @brief Sets the rating of a reservation.
 *
 * @param reservation ReservationInfo pointer of type 'ReservationInfo*'.
 * @param rating Rating of type 'int'.
 */
void set_rating(ReservationInfo *reservation, int rating);

/**
 * @brief Gets the reservation id of a reservation.
 *
 * @param reservation ReservationInfo pointer of type 'ReservationInfo*'.
 * @return char pointer of type 'char*'.
 */
char *get_reservation_id(ReservationInfo *reservation);

/**
 * @brief Gets the user id of a reservation.
 *
 * @param reservation ReservationInfo pointer of type 'ReservationInfo*'.
 * @return char pointer of type 'char*'.
 */
char *get_user_id_reservation(ReservationInfo *reservation);

/**
 * @brief Gets the hotel id of a reservation.
 *
 * @param reservation ReservationInfo pointer of type 'ReservationInfo*'.
 * @return char pointer of type 'char*'.
 */
char *get_hotel_id(ReservationInfo *reservation);

/**
 * @brief Gets the hotel name of a reservation.
 *
 * @param reservation ReservationInfo pointer of type 'ReservationInfo*'.
 * @return char pointer of type 'char*'.
 */
char *get_hotel_name(ReservationInfo *reservation);

/**
 * @brief Gets the hotel stars of a reservation.
 *
 * @param reservation ReservationInfo pointer of type 'ReservationInfo*'.
 * @return int of type 'int'.
 */
int get_hotel_stars(ReservationInfo *reservation);

/**
 * @brief Gets the city tax of a reservation.
 *
 * @param reservation ReservationInfo pointer of type 'ReservationInfo*'.
 * @return int of type 'int'.
 */
int get_city_tax(ReservationInfo *reservation);

/**
 * @brief Gets the begin date of a reservation.
 *
 * @param reservation ReservationInfo pointer of type 'ReservationInfo*'.
 * @return char pointer of type 'char*'.
 */
char *get_begin_date(ReservationInfo *reservation);

/**
 * @brief Gets the end date of a reservation.
 *
 * @param reservation ReservationInfo pointer of type 'ReservationInfo*'.
 * @return char pointer of type 'char*'.
 */
char *get_end_date(ReservationInfo *reservation);

/**
 * @brief Gets the price per night of a reservation.
 *
 * @param reservation ReservationInfo pointer of type 'ReservationInfo*'.
 * @return int of type 'int'.
 */
int get_price_per_night(ReservationInfo *reservation);

/**
 * @brief Gets the includes breakfast of a reservation.
 *
 * @param reservation ReservationInfo pointer of type 'ReservationInfo*'.
 * @return char pointer of type 'char*'.
 */
char *get_includes_breakfast(ReservationInfo *reservation);

/**
 * @brief Gets the rating of a reservation.
 *
 * @param reservation ReservationInfo pointer of type 'ReservationInfo*'.
 * @return int of type 'int'.
 */
int get_rating(ReservationInfo *reservation);

/**
 * @brief Frees the memory allocated to a reservation.
 *
 * @param reservation ReservationInfo pointer of type 'ReservationInfo*'.
 */
void destroy_reservation(ReservationInfo *reservation);

#endif