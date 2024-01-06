#ifndef USER_CONTROLLER_H
#define USER_CONTROLLER_H

#include "models/user.h"
#include "stats/user_stats.h"

typedef struct users_data UsersData;

/**
 * @brief Allocates the memory necessary to create a new UsersData struct and
 * generates the hastable.
 *
 * @return UsersData pointer of type 'UsersData*' to the allocated memory.
 */
UsersData *users_data_new();

/**
 * @brief Adds a user to the hastable.
 *
 * @param users_data Pointer to the UsersData struct.
 * @param user Pointer to the UserInfo struct.
 */
void add_user(UsersData *users_data, UserInfo *user);

/**
 * @brief Updates a user stats in the hastable.
 *
 * @param users_data Pointer to the UsersData struct.
 * @param user_stats Pointer to the UserStats struct.
 */
UserStats *update_user_stats_controller(UsersData *users_data, char *user_id,
                                        int number_of_flights,
                                        int number_of_reservations,
                                        double total_spent);

/**
 * @brief Frees the memory allocated to the UsersData struct.
 *
 * @param users_data Pointer to the UsersData struct.
 */
void users_data_free(UsersData *users_data);

/**
 * @brief Adds a user stats to the hastable.
 *
 * @param users_data Pointer to the UsersData struct.
 * @param user_stats Pointer to the UserStats struct.
 */
void add_user_stats_controller(UsersData *users_data, UserStats *user_stats);

/**
 * @brief Frees the memory allocated to the UsersData struct.
 *
 * @param users_data Pointer to the UsersData struct.
 */
void users_stats_data_free_controller(UsersData *users_data);

/**
 * @brief Gets a user from the hastable by its username.
 *
 * @param users_data Pointer to the UsersData struct.
 * @param username Pointer to the username.
 *
 * @return UserInfo pointer of type 'UserInfo*' to the user.
 */
UserInfo *get_user_by_username(UsersData *users_data, char *username);

/**
 * @brief Gets a user stats from the hastable by its user id.
 *
 * @param users_data Pointer to the UsersData struct.
 * @param user_id Pointer to the user id.
 *
 * @return UserStats pointer of type 'UserStats*' to the user stats.
 */
UserStats *get_user_stats_by_user_id(UsersData *users_data, char *user_id);

/**
 * @brief Gets a user stats from the hastable by its user id.
 *
 * @param users_data Pointer to the UsersData struct.
 *
 * @return GHashTable pointer of type 'GHashTable*' to the user stats.
 */
GHashTable *get_user_stats(UsersData *users_data);

#endif
