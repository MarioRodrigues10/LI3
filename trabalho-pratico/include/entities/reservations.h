#ifndef RESERVATIONS_H
#define RESERVATIONS_H

#define MAX_FIELD_SIZE 256
#define MAX_TOKENS_RESERVATION 14

#include "base/stats.h"
#include "catalogs/reservations_catalog.h"
#include "catalogs/users_catalog.h"

typedef struct reservation *RESERVATION;

/**
 * @brief Function that creates a new reservation
 *
 * @return new_driver - The new driver of type `Reservation`
 */
RESERVATION create_reservation();

/**
 * @brief Function that builds the reservation
 *
 * @param reservation_params - The reservation parameters of type 'char*'
 * @param catalog - The catalog of type 'void*'
 *
 */
void build_reservation(char **reservation_params, void *catalog,
                       void *catalog_users, STATS stats);

/**
 * @brief Function that verifies if the parameters is valid to create a new
 * reservation (parameters : id, user_id, hotel_id, hotel_name, hotel_starts,
 * city_tax, address, begin_date, end_date, price_per_night, include_breakfast,
 * room_detail, rating, comment)
 *
 * @param parameters - The parameters of type 'char**'
 *
 * @return 0 if the input is invalid and 1 if the input is valid
 */
int verify_reservation_input(char **parameters, void *catalog_users);

/**
 * @brief Function that sets the reservation id
 *
 * @param reservation - The Reservation of type 'RESERVATION'
 * @param id - The id string of type 'char*'
 */
void set_reservation_id(RESERVATION reservation, char *id);

/**
 * @brief Function that sets the user id
 *
 * @param reservation - The Reservation of type 'RESERVATION'
 * @param user_id - The Reservation id string of type 'char*'
 */
void set_reservation_user_id(RESERVATION reservation, char *id);

/**
 * @brief Function that sets the hotel id
 *
 * @param reservation - The Reservation of type 'RESERVATION'
 * @param hotel_id - The hotel id string of type 'char*'
 */
void set_reservation_hotel_id(RESERVATION reservation, char *id);

/**
 * @brief Function that sets the hotel name
 *
 * @param reservation - The Reservation of type 'RESERVATION'
 * @param hotel_name - The hotel name string of type 'char*'
 */
void set_reservation_hotel_name(RESERVATION reservation, char *hotel_name);

/**
 * @brief Function that sets the reservation hotel stars
 *
 * @param reservation - The Reservation of type 'RESERVATION'
 * @param stars - The stars integer of type 'int'
 */
void set_reservation_hotel_stars(RESERVATION reservation, int stars);

/**
 * @brief Function that sets the reservation city tax
 *
 * @param reservation - The Reservation of type 'RESERVATION'
 * @param city_tax - The tax integer of type 'int'
 */
void set_reservation_city_tax(RESERVATION reservation, int tax);

/**
 * @brief Function that sets the reservation address
 *
 * @param reservation - The Reservation of type 'RESERVATION'
 * @param address - The address string of type 'char*'
 */
void set_reservation_address(RESERVATION reservation, char *address);

/**
 * @brief Function that sets the reservation begin date
 *
 * @param reservation - The Reservation of type 'RESERVATION'
 * @param begin_date - The begin date string of type 'char*'
 */
void set_reservation_begin_date(RESERVATION reservation, char *begin_date);

/**
 * @brief Function that sets the reservation end date
 *
 * @param reservation - The Reservation of type 'RESERVATION'
 * @param end_date - The end date string of type 'char*'
 */
void set_reservation_end_date(RESERVATION reservation, char *end_date);

/**
 * @brief Function that sets the reservation price per night
 *
 * @param reservation - The Reservation of type 'RESERVATION'
 * @param price_per_night - The price_per_night integer of type 'int'
 */
void set_reservation_price_per_night(RESERVATION reservation,
                                     int price_per_ninght);

/**
 * @brief Function that sets the reservation include breakfast
 *
 * @param reservation - The Reservation of type 'RESERVATION'
 * @param include_breakfast - The includes breakfast string of type 'char*'
 */
void set_reservation_includes_breakfast(RESERVATION reservation,
                                        char *includes_breakfast);

/**
 * @brief Function that sets the reservation room details
 *
 * @param reservation - The Reservation of type 'RESERVATION'
 * @param room_details - The room details string of type 'char*'
 */
void set_reservation_room_details(RESERVATION reservation, char *room_detail);

/**
 * @brief Function that sets the reservation rating
 *
 * @param reservation - The Reservation of type 'RESERVATION'
 * @param rating - The rating integer of type 'int'
 */
void set_reservation_rating(RESERVATION reservation, int rating);

/**
 * @brief Function that sets the reservation comment
 *
 * @param reservation - The Reservation of type 'RESERVATION'
 * @param comment - The comment string of type 'char*'
 */
void set_reservation_comment(RESERVATION reservation, char *comment);

/**
 * @brief Function that frees the space allocated to store a reservation
 *
 * @param reservation - The Reservation of type 'RESERVATION'
 */
void free_reservation(RESERVATION reservation);

/**
 * @brief Function that gets the reservation id
 *
 * @param Reservation - The Reservation of type 'RESERVATION'
 *
 * @return id - The id integer of type 'int'
 */
int get_reservation_id(RESERVATION reservation);

/**
 * @brief Function that gets the reservation user id
 *
 * @param Reservation - The Reservation of type 'RESERVATION'
 *
 * @return id - The id string of type 'char*'
 */
char *get_user_id_from_reservation(RESERVATION reservation);

/**
 * @brief Function that gets the reservation hotel id
 *
 * @param Reservation - The Reservation of type 'RESERVATION'
 *
 * @return id - The id of type 'char*'
 */
char *get_reservation_hotel_id(RESERVATION reservation);

/**
 * @brief Function that gets the reservation hotel name
 *
 * @param Reservation - The Reservation of type 'RESERVATION'
 *
 * @return hotel_name - The hotel name string of type 'char*'
 */
char *get_reservation_hotel_name(RESERVATION reservation);

/**
 * @brief Function that gets the reservation hotel stars
 *
 * @param Reservation - The Reservation of type 'RESERVATION'
 *
 * @return stars - The starts integer of type 'int'
 */
int get_reservation_hotel_stars(RESERVATION reservation);

/**
 * @brief Function that gets the reservation city tax
 *
 * @param Reservation - The Reservation of type 'RESERVATION'
 *
 * @return tax - The tax integer of type 'int'
 */
int get_reservation_city_tax(RESERVATION reservation);

/**
 * @brief Function that gets the reservation address
 *
 * @param Reservation - The Reservation of type 'RESERVATION'
 *
 * @return address - The address string of type 'char*'
 */
char *get_reservation_address(RESERVATION reservation);

/**
 * @brief Function that gets the reservation begin date
 *
 * @param Reservation - The Reservation of type 'RESERVATION'
 *
 * @return begin_date - The begin date string of type 'char*'
 */
char *get_reservation_begin_date(RESERVATION reservation);

/**
 * @brief Function that gets the reservation end date
 *
 * @param Reservation - The Reservation of type 'RESERVATION'
 *
 * @return end_date - The end date string of type 'char*'
 */
char *get_reservation_end_date(RESERVATION reservation);

/**
 * @brief Function that gets the reservation price per night
 *
 * @param Reservation - The Reservation of type 'RESERVATION'
 *
 * @return price_per_night - The price per night integer of type 'int'
 */
int get_reservation_price_per_night(RESERVATION reservation);

/**
 * @brief Function that gets the reservation include breakfast
 *
 * @param Reservation - The Reservation of type 'RESERVATION'
 *
 * @return include_breakfast - The includes breakfast string of type 'char*'
 */
char *get_reservation_includes_breakfast(RESERVATION reservation);

/**
 * @brief Function that gets the reservation room details
 *
 * @param Reservation - The Reservation of type 'RESERVATION'
 *
 * @return room_details - The room details string of type 'char*'
 */
char *get_reservation_room_detail(RESERVATION reservation);

/**
 * @brief Function that gets reservation rating
 *
 * @param Reservation - The Reservation of type 'RESERVATION'
 *
 * @return rating - The rating integer of type 'int'
 */
int get_reservation_rating(RESERVATION reservation);

/**
 * @brief Function that gets the reservation comment
 *
 * @param Reservation - The Reservation of type 'RESERVATION'
 *
 * @return comment - The comment string of type 'char*'
 */
char *get_reservation_comment(RESERVATION reservation);

#endif