#ifndef USER_STATS_H
#define USER_STATS_H

#include <glib.h>

typedef struct user_stats UserStats;
typedef struct user_info UserInfoStats;
typedef struct stats_user_information StatsUserInfo;

StatsUserInfo *create_stats_user_information();
GArray *get_stats_user_info(StatsUserInfo *stats);

/**
 * @brief Sets the user id from user stats.
 *
 * @param user_stats User stats of type 'UserStats*'.
 * @param user_id User id of type 'char*'.
 *
 */
void set_user_id_from_user_stats(UserStats *user_stats, char *user_id);

/**
 * @brief Sets the number of flights from user stats.
 *
 * @param user_stats User stats of type 'UserStats*'.
 * @param number_of_flights Number of flights of type 'int'.
 *
 */
void set_number_of_flights_from_user_stats(UserStats *user_stats,
                                           int number_of_flights);

/**
 * @brief Sets the number of reservations from user stats.
 *
 * @param user_stats User stats of type 'UserStats*'.
 * @param number_of_reservations Number of reservations of type 'int'.
 *
 */
void set_number_of_reservations_from_user_stats(UserStats *user_stats,
                                                int number_of_reservations);

/**
 * @brief Sets the total spent from user stats.
 *
 * @param user_stats User stats of type 'UserStats*'.
 * @param total_spent Total spent of type 'double'.
 *
 */
void set_total_spent_from_user_stats(UserStats *user_stats, double total_spent);

/**
 * @brief Gets the user id from user stats.
 *
 * @param user_stats User stats of type 'UserStats*'.
 *
 * @returns The user id of type 'char*'.
 *
 */
char *get_user_id_from_user_stats(UserStats *user_stats);

/**
 * @brief Gets the number of flights from user stats.
 *
 * @param user_stats User stats of type 'UserStats*'.
 *
 * @returns The number of flights of type 'int'.
 *
 */
int get_number_of_flights_from_user_stats(UserStats *user_stats);

/**
 * @brief Gets the number of reservations from user stats.
 *
 * @param user_stats User stats of type 'UserStats*'.
 *
 * @returns The number of reservations of type 'int'.
 *
 */
int get_number_of_reservations_from_user_stats(UserStats *user_stats);

/**
 * @brief Gets the total spent from user stats.
 *
 * @param user_stats User stats of type 'UserStats*'.
 *
 * @returns The total spent of type 'double'.
 *
 */
double get_total_spent_from_user_stats(UserStats *user_stats);

/**
 * @brief Gets the user flights from user stats.
 *
 * @param user_stats User stats of type 'UserStats*'.
 *
 * @returns The user flights of type 'GArray*'.
 *
 */
GArray *get_user_flights_from_user_stats(UserStats *user_stats);

/**
 * @brief Gets the user reservations from user stats.
 *
 * @param user_stats User stats of type 'UserStats*'.
 *
 * @returns The user reservations of type 'GArray*'.
 *
 */
GArray *get_user_reservations_from_user_stats(UserStats *user_stats);

/**
 * @brief Creates a user stats.
 *
 * @param user_id User id of type 'char*'.
 * @param number_of_flights Number of flights of type 'int'.
 * @param number_of_reservations Number of reservations of type 'int'.
 * @param total_spent Total spent of type 'double'.
 * @param flight_id Flight id of type 'char*'.
 * @param reservation_id Reservation id of type 'char*'.
 *
 * @returns The user stats of type 'UserStats*'.
 *
 */
UserStats *create_user_stats(char *user_id, int number_of_flights,
                             int number_of_reservations, double total_spent,
                             int flight_id, int reservation_id);

/**
 * @brief Updates the user stats.
 *
 * @param user_stats User stats of type 'UserStats*'.
 * @param id Id of type 'char*'.
 * @param flight Flight of type 'int'.
 * @param reservation Reservation of type 'int'.
 * @param total_spent Total spent of type 'double'.
 *
 * @returns The user stats of type 'UserStats*'.
 */
UserStats *update_user_stats(UserStats *user_stats, char *id, int flight,
                             int reservation, double total_spent);

/**
 * @brief Updates the user flights.
 *
 * @param users_stats User stats of type 'UserStats*'.
 * @param user_id User id of type 'char*'.
 * @param flight_id Flight id of type 'char*'.
 */
UserStats *update_user_flights(UserStats *users_stats, char *user_id,
                               int flight_id);

/**
 * @brief Updates the user reservations.
 *
 * @param users_stats User stats of type 'UserStats*'.
 * @param user_id User id of type 'char*'.
 * @param reservation_id Reservation id of type 'int'.
 */
UserStats *update_user_reservations(UserStats *users_stats, char *user_id,
                                    int reservation_id);

/**
 * @brief Function that updates the user stats
 *
 * @param stats The stats of type 'STATS'
 * @param user_id The id of the user
 * @param user_name The name of the user
 *
 */
void update_user_stats_info(StatsUserInfo *stats, char *user_id,
                            char *user_name);

/**
 * @brief Function that sets the user name from user info
 *
 * @param user_info The user info of type 'UserInfoStats*'
 * @param user_name The user name of type 'char*'
 *
 */
void set_user_name_from_user_info(UserInfoStats *user_info, char *user_name);

/**
 * @brief Function that gets the user name from user info
 *
 * @param user_info The user info of type 'UserInfoStats*'
 *
 * @returns The user name of type 'char*'
 */
char *get_user_name_from_user_info(UserInfoStats *user_info);

/**
 * @brief Function that sets the user id from user info
 *
 * @param user_info The user info of type 'UserInfoStats*'
 * @param user_id The user id of type 'char*'
 *
 */
void set_user_id_from_user_info(UserInfoStats *user_info, char *user_id);

/**
 * @brief Function that gets the user id from user info
 *
 * @param user_info The user info of type 'UserInfoStats*'
 *
 * @returns The user id of type 'char*'
 */
char *get_user_id_from_user_info(UserInfoStats *user_info);

/**
 * @brief Destroys the user stats.
 *
 * @param user_stats User stats of type 'UserStats*'.
 */
void destroy_user_stats(UserStats *user_stats);

/**
 * @brief Destroys the stats user information.
 *
 * @param stats The stats of type 'StatsUserInfo*'
 */
void free_stats_user_information(StatsUserInfo *stats);
#endif
