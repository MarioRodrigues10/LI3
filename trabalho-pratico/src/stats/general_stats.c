#include "stats/general_stats.h"

#include <glib.h>

struct general_stats {
  int key;  // YYYYMMDD
  int number_of_users;
  int number_of_flights;
  int number_of_passengers;
  int unique_passengers;
  int reservations;
};

// SETTERS

void set_key_from_general_stats(GeneralStats *general_stats, int key) {
  general_stats->key = key;
}

void set_number_of_flights_from_general_stats(GeneralStats *general_stats) {
  general_stats->number_of_flights += 1;
}

void set_number_of_passengers_from_general_stats(GeneralStats *general_stats) {
  general_stats->number_of_passengers += 1;
}

void set_unique_passengers_from_general_stats(GeneralStats *general_stats) {
  general_stats->unique_passengers += 1;
}

void set_reservations_from_general_stats(GeneralStats *general_stats) {
  general_stats->reservations += 1;
}

void set_users_from_general_stats(GeneralStats *general_stats) {
  general_stats->number_of_users += 1;
}

// GETTERS

int get_key_from_general_stats(GeneralStats *general_stats) {
  int key = general_stats->key;
  return key;
}

int get_number_of_flights_from_general_stats(GeneralStats *general_stats) {
  int number_of_flights = general_stats->number_of_flights;
  return number_of_flights;
}

int get_number_of_passengers_from_general_stats(GeneralStats *general_stats) {
  int number_of_passengers = general_stats->number_of_passengers;
  return number_of_passengers;
}

int get_unique_passengers_from_general_stats(GeneralStats *general_stats) {
  int unique_passengers = general_stats->unique_passengers;
  return unique_passengers;
}

int get_reservations_from_general_stats(GeneralStats *general_stats) {
  int reservations = general_stats->reservations;
  return reservations;
}

int get_users_from_general_stats(GeneralStats *general_stats) {
  int number_of_users = general_stats->number_of_users;
  return number_of_users;
}

// SET UP

GeneralStats *create_general_stats(int key, int number_of_users,
                                   int number_of_flights,
                                   int number_of_passengers,
                                   int unique_passengers, int reservations) {
  GeneralStats *new_general_stats = malloc(sizeof(GeneralStats));
  new_general_stats->key = key;
  new_general_stats->number_of_users = number_of_users;
  new_general_stats->number_of_flights = number_of_flights;
  new_general_stats->number_of_passengers = number_of_passengers;
  new_general_stats->unique_passengers = unique_passengers;
  new_general_stats->reservations = reservations;
  return new_general_stats;
}

GeneralStats *update_general_stats(GeneralStats *general_stats, int key,
                                   int number_of_users, int number_of_flights,
                                   int number_of_passengers,
                                   int unique_passengers, int reservations) {
  if (general_stats != NULL) {
    general_stats->number_of_users += number_of_users;
    general_stats->number_of_flights += number_of_flights;
    general_stats->number_of_passengers += number_of_passengers;
    general_stats->unique_passengers += unique_passengers;
    general_stats->reservations += reservations;
    return general_stats;
  } else {
    GeneralStats *new_general_stats = create_general_stats(
        key, number_of_users, number_of_flights, number_of_passengers,
        unique_passengers, reservations);
    return new_general_stats;
  }
}

// DESTROYER

void destroy_general_stats(GeneralStats *general_stats) { free(general_stats); }