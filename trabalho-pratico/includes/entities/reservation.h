#ifndef RESERVATION_H
#define RESERVATION_H

typedef struct reservation *Reservation;

/**
 * @brief Create a new reservations
 *
 * @return new_driver - The new driver of type `Resevations`
 */
Reservation createReservation();

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
int verifyReservationInput(char **parameters);

/**
 * @brief Set the reservation id
 *
 * @param reservation - The Resevation of type 'Reservation'
 * @param id - The id string of type 'char*'
 */
void setReservationId(Reservation reservation, char *id);

/**
 * @brief Set the reservation Resevation id
 *
 * @param reservation - The Resevation of type 'Reservation'
 * @param user_id - The Resevation id string of type 'char*'
 */
void setReservationUserId(Reservation reservation, char *id);

/**
 * @brief Set the hotel id
 *
 * @param reservation - The Resevation of type 'Reservation'
 * @param hotel_id - The hotel id string of type 'char*'
 */
void setReservationHotelId(Reservation reservation, char *id);

/**
 * @brief Set the hotel name
 *
 * @param reservation - The Resevation of type 'Reservation'
 * @param hotel_name - The hotel name string of type 'char*'
 */
void setReservationHotelName(Reservation reservation, char *hotel_name);

/**
 * @brief Set the reservation hotel starts
 *
 * @param reservation - The Resevation of type 'Reservation'
 * @param starts - The starts integer of type 'int'
 */
void setReservationHotelStarts(Reservation reservation, int starts);

/**
 * @brief Set the reservation city tax
 *
 * @param reservation - The Resevation of type 'Reservation'
 * @param city_tax - The tax integer of type 'int'
 */
void setReservationCityTax(Reservation reservation, int tax);

/**
 * @brief Set the reservation address
 *
 * @param reservation - The Resevation of type 'Reservation'
 * @param address - The address string of type 'char*'
 */
void setReservationAddress(Reservation reservation, char *address);

/**
 * @brief Set the reservation begin date
 *
 * @param reservation - The Resevation of type 'Reservation'
 * @param begin_date - The begin date string of type 'char*'
 */
void setReservationBeginDate(Reservation reservation, char *begin_date);

/**
 * @brief Set the reservation end date
 *
 * @param reservation - The Resevation of type 'Reservation'
 * @param end_date - The end date string of type 'char*'
 */
void setReservationEndDate(Reservation reservation, char *end_date);

/**
 * @brief Set the reservation price per night
 *
 * @param reservation - The Resevation of type 'Reservation'
 * @param price_per_night - The price_per_night integer of type 'int'
 */
void setReservationPricePerNight(Reservation reservation, int price_per_ninght);

/**
 * @brief Set the reservation include breakfast
 *
 * @param reservation - The Resevation of type 'Reservation'
 * @param include_breakfast - The include breakfast string of type 'char*'
 */
void setReservationIncludeBreakfast(Reservation reservation,
                                    char *include_breakfast);

/**
 * @brief Set the reservation room details
 *
 * @param reservation - The Resevation of type 'Reservation'
 * @param room_details - The room details string of type 'char*'
 */
void setReservationRoomDetail(Reservation reservation, char *room_detail);

/**
 * @brief Set the reservation rating
 *
 * @param reservation - The Resevation of type 'Reservation'
 * @param rating - The rating integer of type 'char*'
 */
void setReservationRating(Reservation reservation, int rating);

/**
 * @brief Set the reservation icomment
 *
 * @param reservation - The Resevation of type 'Reservation'
 * @param comment - The comment string of type 'char*'
 */
void setReservationComment(Reservation reservation, char *comment);

/**
 * @brief Frees the reservations allocated to store a reservation
 *
 * @param reservation - The Resevation of type 'Reservation'
 */
void freeReservation(Reservation reservation);

/**
 * @brief Get the Resevation id
 *
 * @param Resevation - The Resevation of type 'REservations'
 * @return id - The id integer of type 'int'
 */
int getReservationId(Reservation reservation);

/**
 * @brief Get the Resevation id
 *
 * @param Resevation - The Resevation of type 'Reservation'
 * @return id - The id integer of type 'int'
 */
int getUserId(Reservation reservation);

/**
 * @brief Get the hotel id
 *
 * @param Resevation - The Resevation of type 'Reservation'
 * @return id - The id integer of type 'int'
 */
int getHotelId(Reservation reservation);

/**
 * @brief Get the Resevation hotel name
 *
 * @param Resevation - The Resevation of type 'Reservation'
 * @return hotel_name - The hotel name string of type 'char*'
 */
char *getReservationHotelName(Reservation reservation);

/**
 * @brief Get the Resevation hotel starts
 *
 * @param Resevation - The Resevation of type 'Reservation'
 * @return starts - The starts integer of type 'int'
 */
int getReservationHotelStarts(Reservation reservation);

/**
 * @brief Get the Resevation city tax
 *
 * @param Resevation - The Resevation of type 'Reservation'
 * @return tax - The tax integer of type 'int'
 */
double getReservationCityTax(Reservation reservation);

/**
 * @brief Get the Resevation address
 *
 * @param Resevation - The Resevation of type 'Reservation'
 * @return address - The address string of type 'char*'
 */
char *getReservationAddress(Reservation reservation);

/**
 * @brief Get the Resevation begin date
 *
 * @param Resevation - The Resevation of type 'Reservation'
 * @return begin_date - The begin date string of type 'char*'
 */
char *getReservationBeginDate(Reservation reservation);

/**
 * @brief Get the Resevation end date
 *
 * @param Resevation - The Resevation of type 'Reservation'
 * @return end_date - The end date string of type 'char*'
 */
char *getReservationEndDate(Reservation reservation);

/**
 * @brief Get the Resevation price per night
 *
 * @param Resevation - The Resevation of type 'Reservation'
 * @return price_per_night - The price per night integer of type 'int'
 */
int getReservationPricePerNight(Reservation reservation);

/**
 * @brief Get the Resevation include breakfast
 *
 * @param Resevation - The Resevation of type 'Reservation'
 * @return include_breakfast - The include breakfast string of type 'char*'
 */
char *getReservationIncludeBreakfast(Reservation reservation);

/**
 * @brief Get the Resevation room details
 *
 * @param Resevation - The Resevation of type 'Reservation'
 * @return room_details - The room details string of type 'char*'
 */
char *getReservationRoomDetail(Reservation reservation);

/**
 * @brief Get the Resevation rating
 *
 * @param Resevation - The Resevation of type 'Reservation'
 * @return rating - The rating integer of type 'int'
 */
int getReservationRating(Reservation reservation);

/**
 * @brief Get the Resevation comment
 *
 * @param Resevation - The Resevation of type 'Reservation'
 * @return comment - The comment string of type 'char*'
 */
char *getReservationComment(Reservation reservation);

#endif