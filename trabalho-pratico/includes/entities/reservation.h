#ifndef RESERVATION_H
#define RESERVATION_H

typedef struct reservation *Reservation;

/**
 * @brief Creates a new reservations
 *
 * @return new_driver - The new driver of type `Resevations`
 */
Reservation creat_reservation();

/**
 * @brief Set the reservation id
 * 
 * @param reservation - The user of type 'Reservation'
 * @param id - The id string of type 'char*'
 */
void set_reservation_id(Reservation reservation, char *id);

/**
 * @brief Set the reservation user id
 * 
 * @param reservation - The user of type 'Reservation'
 * @param user_id - The user id string of type 'char*'
 */
void set_reservation_user_id(Reservation reservation, char *id);

/**
 * @brief Set the hotel id
 * 
 * @param reservation - The user of type 'Reservation'
 * @param hotel_id - The hotel id string of type 'char*'
 */
void set_reservation_hotel_id(Reservation reservation,char *id);

/**
 * @brief Set the hotel name
 * 
 * @param reservation - The user of type 'Reservation'
 * @param hotel_name - The hotel name string of type 'char*'
 */
void set_reservation_hotel_name(Reservation reservation ,char *hotel_name);

/**
 * @brief Set the reservation hotel starts
 * 
 * @param reservation - The user of type 'Reservation'
 * @param starts - The starts integer of type 'int'
 */
void set_reservation_hotel_starts(Reservation reservation ,int starts);

/**
 * @brief Set the reservation city tax
 * 
 * @param reservation - The user of type 'Reservation'
 * @param city_tax - The tax integer of type 'int'
 */
void set_reservation_city_tax(Reservation reservation, int tax);

/**
 * @brief Set the reservation address
 * 
 * @param reservation - The user of type 'Reservation'
 * @param address - The address string of type 'char*'
 */
void set_reservation_address(Reservation reservation, char *address);

/**
 * @brief Set the reservation begin date 
 * 
 * @param reservation - The user of type 'Reservation'
 * @param begin_date - The begin date string of type 'char*'
 */
void set_reservation_begin_date(Reservation reservation, char *begin_date);

/**
 * @brief Set the reservation end date
 * 
 * @param reservation - The user of type 'Reservation'
 * @param end_date - The end date string of type 'char*'
 */
void set_reservation_end_date(Reservation reservation, char *end_date);

/**
 * @brief Set the reservation price per night
 * 
 * @param reservation - The user of type 'Reservation'
 * @param price_per_night - The price_per_night integer of type 'int'
 */
void set_reservation_price_per_night(Reservation reservation, int price_per_ninght);

/**
 * @brief Set the reservation include breakfast
 * 
 * @param reservation - The user of type 'Reservation'
 * @param include_breakfast - The include breakfast string of type 'char*'
 */
void set_reservation_include_breakfast(Reservation reservation, char *include_breakfast);

/**
 * @brief Set the reservation room details
 * 
 * @param reservation - The user of type 'Reservation'
 * @param room_details - The room details string of type 'char*'
 */
void set_reservation_room_detail(Reservation reservation,char *room_detail);

/**
 * @brief Set the reservation rating
 * 
 * @param reservation - The user of type 'Reservation'
 * @param rating - The rating integer of type 'char*'
 */
void set_reservation_rating(Reservation reservation,int rating);

/**
 * @brief Set the reservation icomment
 * 
 * @param reservation - The user of type 'Reservation'
 * @param comment - The comment string of type 'char*'
 */
void set_reservation_comment(Reservation reservation, char *comment);

/**
 * @brief Frees the reservations allocated to store a reservation
 * 
 * @param reservation - The user of type 'Reservation'
 */
void free_reservation(Reservation reservation);


#endif