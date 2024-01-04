#include "controllers/user_controller.h"

#include <glib.h>

struct users_data {
  GHashTable *users;

  GHashTable *user_stats;
};

// SET UP

UsersData *users_data_new() {
  UsersData *users_data = malloc(sizeof(UsersData));
  users_data->users = g_hash_table_new_full(g_str_hash, g_str_equal, g_free,
                                            (GDestroyNotify)destroy_user);
  users_data->user_stats = g_hash_table_new_full(
      g_str_hash, g_str_equal, g_free, (GDestroyNotify)destroy_user_stats);
  return users_data;
}

// USER

void add_user(UsersData *users_data, UserInfo *user) {
  char *user_id = get_user_id(user);
  g_hash_table_insert(users_data->users, user_id, user);
}

void users_data_free(UsersData *users_data) {
  g_hash_table_destroy(users_data->users);
  g_hash_table_destroy(users_data->user_stats);
  free(users_data);
}

// USER STATS

void add_user_stats_controller(UsersData *users_data, UserStats *user_stats) {
  char *user_id = get_user_id_from_user_stats(user_stats);
  g_hash_table_insert(users_data->user_stats, user_id, user_stats);
}

void update_user_stats_controller(UsersData *users_data, char *user_id,
                                  int number_of_flights,
                                  int number_of_reservations,
                                  double total_spent) {
  UserStats *user_stats = g_hash_table_lookup(users_data->user_stats, user_id);
  if (user_stats == NULL) {
    UserStats *user_stats =
        create_user_stats(user_id, number_of_flights, number_of_reservations,
                          total_spent, NULL, 0);
    add_user_stats_controller(users_data, user_stats);
    return;
  }
  user_stats = update_user_stats(user_stats, user_id, number_of_flights,
                                 number_of_reservations, total_spent);
}

// ACCESS

// USER

UserInfo *get_user_by_username(UsersData *users_data, char *username) {
  return g_hash_table_lookup(users_data->users, username);
}

// USER STATS

UserStats *get_user_stats_by_user_id(UsersData *users_data, char *user_id) {
  return g_hash_table_lookup(users_data->user_stats, user_id);
}
