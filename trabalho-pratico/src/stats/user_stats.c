#include "stats/user_stats.h"

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>

struct user_stats {
  char *user_id;
  int number_of_flights;
  int number_of_reservations;
  double total_spent;

  GArray *user_flights;
  GArray *user_reservations;
};

struct user_info {
  char *user_id;
  char *user_name;
};

struct stats_user_information {
  GArray *info;
};

// SETTERS

void set_user_id_from_user_stats(UserStats *user_stats, char *user_id) {
  user_stats->user_id = g_strdup(user_id);
}

void set_number_of_flights_from_user_stats(UserStats *user_stats,
                                           int number_of_flights) {
  user_stats->number_of_flights = number_of_flights;
}

void set_number_of_reservations_from_user_stats(UserStats *user_stats,
                                                int number_of_reservations) {
  user_stats->number_of_reservations = number_of_reservations;
}

void set_total_spent_from_user_stats(UserStats *user_stats,
                                     double total_spent) {
  user_stats->total_spent = total_spent;
}

// GETTERS

char *get_user_id_from_user_stats(UserStats *user_stats) {
  char *user_id = g_strdup(user_stats->user_id);
  return user_id;
}

int get_number_of_flights_from_user_stats(UserStats *user_stats) {
  int number_of_flights = user_stats->number_of_flights;
  return number_of_flights;
}

int get_number_of_reservations_from_user_stats(UserStats *user_stats) {
  int number_of_reservations = user_stats->number_of_reservations;
  return number_of_reservations;
}

double get_total_spent_from_user_stats(UserStats *user_stats) {
  double total_spent = user_stats->total_spent;
  return total_spent;
}

GArray *get_user_flights_from_user_stats(UserStats *user_stats) {
  if (user_stats == NULL) return NULL;
  GArray *user_flights = g_array_copy(user_stats->user_flights);
  return user_flights;
}

GArray *get_user_reservations_from_user_stats(UserStats *user_stats) {
  if (user_stats == NULL) return NULL;
  GArray *user_reservations = g_array_copy(user_stats->user_reservations);
  return user_reservations;
}

// SET UP

UserStats *create_user_stats(char *user_id, int number_of_flights,
                             int number_of_reservations, double total_spent,
                             int flight_id, int reservation_id) {
  UserStats *new_user_stats = malloc(sizeof(UserStats));
  new_user_stats->user_id = user_id;
  new_user_stats->number_of_flights = number_of_flights;
  new_user_stats->number_of_reservations = number_of_reservations;
  new_user_stats->total_spent = total_spent;
  new_user_stats->user_flights = g_array_new(FALSE, FALSE, sizeof(int));
  new_user_stats->user_reservations = g_array_new(FALSE, FALSE, sizeof(int));
  if (flight_id != 0)
    g_array_append_val(new_user_stats->user_flights, flight_id);
  if (reservation_id != 0)
    g_array_append_val(new_user_stats->user_reservations, reservation_id);

  return new_user_stats;
}

StatsUserInfo *create_stats_user_information() {
  StatsUserInfo *new_user = malloc(sizeof(StatsUserInfo *));

  new_user->info = g_array_new(FALSE, FALSE, sizeof(UserInfoStats *));
  return new_user;
}

UserStats *update_user_stats(UserStats *user_stats, char *id, int flight,
                             int reservation, double total_spent) {
  if (user_stats != NULL) {
    user_stats->number_of_flights += flight;
    user_stats->number_of_reservations += reservation;
    user_stats->total_spent += total_spent;
    return user_stats;
  } else {
    UserStats *new_user_stats =
        create_user_stats(id, flight, reservation, total_spent, 0, 0);
    return new_user_stats;
  }
}

UserStats *update_user_flights(UserStats *users_stats, char *user_id,
                               int flight_id) {
  if (users_stats != NULL) {
    g_array_append_val(users_stats->user_flights, flight_id);
    return users_stats;
  } else {
    UserStats *new_user_stats =
        create_user_stats(user_id, 0, 0, 0.0, flight_id, 0);
    return new_user_stats;
  }
}

UserStats *update_user_reservations(UserStats *users_stats, char *user_id,
                                    int reservation_id) {
  if (users_stats != NULL) {
    g_array_append_val(users_stats->user_reservations, reservation_id);
    return users_stats;
  } else {
    UserStats *new_user_stats =
        create_user_stats(user_id, 0, 0, 0.0, 0, reservation_id);
    return new_user_stats;
  }
}

void update_user_stats_info(StatsUserInfo *stats, char *user_id,
                            char *user_name) {
  if (stats == NULL || user_id == NULL || user_name == NULL) return;
  UserInfoStats *new_user_info = malloc(sizeof(UserInfoStats));
  set_user_id_from_user_info(new_user_info, user_id);
  set_user_name_from_user_info(new_user_info, user_name);
  g_array_append_val(stats->info, new_user_info);
}

GArray *get_stats_user_info(StatsUserInfo *users_stats) {
  GArray *user_info = g_array_copy(users_stats->info);
  return user_info;
}

void set_user_name_from_user_info(UserInfoStats *user_info, char *user_name) {
  user_info->user_name = g_strdup(user_name);
}

char *get_user_name_from_user_info(UserInfoStats *user_info) {
  char *user_name = user_info->user_name;
  return user_name;
}

void set_user_id_from_user_info(UserInfoStats *user_info, char *user_id) {
  user_info->user_id = g_strdup(user_id);
}

char *get_user_id_from_user_info(UserInfoStats *user_info) {
  char *user_id = user_info->user_id;
  return user_id;
}

// DESTROYER

void destroy_user_stats(UserStats *user_stats) {
  g_array_free(user_stats->user_flights, TRUE);
  g_array_free(user_stats->user_reservations, TRUE);
  free(user_stats);
}

void free_stats_user_information(StatsUserInfo *stats) {
  for (guint i = 0; i < stats->info->len; i++) {
    UserInfoStats *user_info = g_array_index(stats->info, UserInfoStats *, i);
    g_free(user_info->user_id);
    g_free(user_info->user_name);
    free(user_info);
  }
  g_array_free(stats->info, TRUE);
  free(stats);
}