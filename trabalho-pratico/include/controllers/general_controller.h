#ifndef GENERAL_CONTROLLER_H
#define GENERAL_CONTROLLER_H

#include "stats/general_stats.h"

typedef struct general_data GeneralData;

/**
 * @brief Creates a new GeneralData object
 *
 * @return GeneralData
 */
GeneralData *general_data_new();

/**
 * @brief Frees a GeneralData object
 *
 * @param general_data GeneralData object
 */
void general_data_free(GeneralData *general_data);

/**
 * @brief Get the general stats by key object
 *
 * @param general_data GeneralData object
 * @param key unique key
 * @return GeneralStats GeneralStats object
 */
GeneralStats *get_general_stats_by_key(GeneralData *general_data, int key);

/**
 * @brief Add a GeneralStats object to the GeneralData object
 *
 * @param general_data GeneralData object
 * @param general_stats GeneralStats object
 */
void add_general_stats_controller(GeneralData *general_data,
                                  GeneralStats *general_stats);

/**
 * @brief Update GeneralStats object
 *
 * @param general_data GeneralData object
 * @param key unique key
 * @param number_of_flights number of flights
 * @param number_of_passengers number of passengers
 * @param reservations number of reservations
 * @param user_id user id
 */
void update_general_stats_controller(GeneralData *general_data, int key,
                                     int number_of_users, int number_of_flights,
                                     int number_of_passengers, int reservations,
                                     char *user_id);

#endif