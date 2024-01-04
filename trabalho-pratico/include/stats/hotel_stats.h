#ifndef HOTEL_STATS_H
#define HOTEL_STATS_H

#include <glib.h>

typedef struct hotel_stats HotelStats;

/**
 * @brief Sets the hotel id from hotel stats.
 *
 * @param hotel_stats hotel stats of type 'HotelStats*'.
 * @param hotel_id hotel id of type 'char*'.
 *
 */
void set_hotel_id_from_hotel_stats(HotelStats *hotel_stats, char *hotel_id);

/**
 * @brief Sets the total rating from hotel stats.
 *
 * @param hotel_stats hotel stats of type 'HotelStats*'.
 * @param total_rating Total rating of type 'int'.
 *
 */
void set_total_rating_from_hotel_stats(HotelStats *hotel_stats,
                                       int total_rating);

/**
 * @brief Sets the number of clients from hotel stats.
 *
 * @param hotel_stats hotel stats of type 'HotelStats*'.
 * @param number_of_clients Number of clients of type 'int'.
 *
 */
void set_number_of_clients_from_hotel_stats(HotelStats *hotel_stats,
                                            int number_of_clients);

/**
 * @brief Gets the hotel id from hotel stats.
 *
 * @param hotel_stats hotel stats of type 'HotelStats*'.
 *
 */
char *get_hotel_id_from_hotel_stats(HotelStats *hotel_stats);

/**
 * @brief Gets the total rating from hotel stats.
 *
 * @param hotel_stats hotel stats of type 'HotelStats*'.
 *
 */
int get_total_rating_from_hotel_stats(HotelStats *hotel_stats);

/**
 * @brief Gets the number of clients from hotel stats.
 *
 * @param hotel_stats hotel stats of type 'HotelStats*'.
 *
 */
int get_number_of_clients_from_hotel_stats(HotelStats *hotel_stats);

/**
 * @brief Gets the hotel reservations from hotel stats.
 *
 * @param hotel_stats hotel stats of type 'HotelStats*'.
 *
 * @returns A GArray of type 'GArray*' with the hotel reservations
 */
GArray *get_hotel_reservations(HotelStats *hotel_stats);

/**
 * @brief Creates a new hotel stats.
 *
 * @param hotel_id hotel id of type 'char*'.
 * @param total_rating Total rating of type 'int'.
 * @param number_of_clients Number of clients of type 'int'.
 * @param reservation_id Reservation id of type 'int'.
 *
 * @returns A new hotel stats of type 'HotelStats*'.
 *
 */
HotelStats *create_hotel_stats(char *hotel_id, int total_rating,
                               int number_of_clients, int reservation_id);

/**
 * @brief Updates a hotel stats.
 *
 * @param hotel_stats hotel stats of type 'HotelStats*'.
 * @param id Id of type 'char*'.
 * @param rating Rating of type 'int'.
 * @param reservation_id Reservation id of type 'int'.
 *
 * @returns An updated hotel stats of type 'HotelStats*'.
 *
 */
HotelStats *update_hotel_stats(HotelStats *hotel_stats, char *id, int rating,
                               int reservation_id);

/**
 * @brief Destroys a hotel stats.
 *
 * @param hotel_stats hotel stats of type 'HotelStats*'.
 *
 */
void destroy_hotel_stats(HotelStats *hotel_stats);

#endif
