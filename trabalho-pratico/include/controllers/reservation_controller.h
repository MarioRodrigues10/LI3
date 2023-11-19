#ifndef RESERVATION_CONTROLLER_H
#define RESERVATION_CONTROLLER_H

#include "models/reservation.h"
#include "stats/hotel_stats.h"

typedef struct reservations_data ReservationsData;

/**
 * @brief Allocates the memory necessary to create a new ReservationsData struct
 * and generates the hastable.
 *
 * @return ReservationsData pointer of type 'ReservationsData*' to the allocated
 * memory.
 */
ReservationsData *reservations_data_new();

/**
 * @brief Adds a reservation to the hastable.
 *
 * @param reservations_data Pointer to the ReservationsData struct.
 * @param reservation Pointer to the ReservationInfo struct.
 */
void add_reservation(ReservationsData *reservations_data,
                     ReservationInfo *reservation);

/**
 * @brief Frees the memory allocated to the ReservationsData struct.
 *
 * @param reservations_data Pointer to the ReservationsData struct.
 */
void reservations_data_free(ReservationsData *reservations_data);

/**
 * @brief Adds a hotel to the hotel stats.
 *
 * @param reservations_data Pointer to the ReservationsData struct.
 * @param hotel_stats Pointer to the hotelStats struct.
 */
void add_hotel_stats_controller(ReservationsData *reservations_data,
                                HotelStats *hotel_stats);

/**
 * @brief Updates the hotel stats.
 *
 * @param reservations_data Pointer to the ReservationsData struct.
 * @param hotel_id Pointer to the hotel id.
 * @param rating Rating of the hotel.
 * @param reservation_id Reservation id of the reservation.
 */
void update_hotel_stats_controller(ReservationsData *reservations_data,
                                   char *hotel_id, int rating,
                                   char *reservation_id);

/**
 * @brief Gets a reservation from the hastable by its reservation id.
 *
 * @param reservations_data Pointer to the ReservationsData struct.
 * @param reservation_id Pointer to the reservation id.
 * @return ReservationInfo pointer of type 'ReservationInfo*' to the
 * reservation.
 */
ReservationInfo *get_reservation_by_reservation_id(
    ReservationsData *reservations_data, char *reservation_id);

/**
 * @brief Gets a hotel stats from the hastable by its hotel id.
 *
 * @param reservations_data Pointer to the ReservationsData struct.
 * @param hotel_id Pointer to the hotel id.
 *
 * @return HotelStats pointer of type 'HotelStats*' to the
 */
HotelStats *get_hotel_stats_by_hotel_id(ReservationsData *reservations_data,
                                        char *hotel_id);

#endif
