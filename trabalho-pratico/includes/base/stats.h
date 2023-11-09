#ifndef STATS_H
#define STATS_H

#include <glib.h>

typedef struct stats *STATS;
typedef struct hotel_stats *HOTEL_STATS;

/**
 * @brief Function that creates the stats
 *
 * @return The stats created
 */
STATS creat_stats();

/**
 * @brief Function that creates the hotel stats
 *
 * @param id The id of the hotel
 * @param total_rating The total rating of the hotel
 * @param total_clients The total clients of the hotel
 *
 * @return The hotel stats created
 */
HOTEL_STATS create_hotel_stats(gpointer id, double total_rating,
                               int total_clients);

/**
 * @brief Function that gets the total rating of the hotel
 *
 * @param stats The stats
 * @param id The id of the hotel
 * @param total_rating The total rating of the hotel
 *
 */
void update_hotel_stats(STATS stats, gpointer id, double total_rating);

/**
 * @brief Function that gets the sum rating of the hotel
 *
 * @param stats The stats
 * @param id The id of the hotel
 *
 * @return The sum rating of the hotel
 */
int get_total_rating(STATS stats, gpointer id);

/**
 * @brief Function that gets the total
 *
 * @param stats The stats
 * @param id The id of the hotel
 *
 * @return The total clients of the hotel
 */
int get_total_clients(STATS stats, gpointer id);

/**
 * @brief Function that gets the media of the ratings
 *
 * @param stats The stats
 * @param id The id of the hotel
 *
 * @return The media of the ratings
 */
double media_of_ratings(STATS stats, gpointer id);

/**
 * @brief Function that gets the total of the ratings
 *
 * @param stats The stats
 * @param id The id of the hotel
 *
 * @return The total of the ratings
 */
void free_stats(STATS stats);

#endif