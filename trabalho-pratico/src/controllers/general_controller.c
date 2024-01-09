#include "controllers/general_controller.h"

#include <glib.h>

struct general_data {
  GHashTable *general_stats;
};

GeneralData *general_data_new() {
  GeneralData *general_data = malloc(sizeof(GeneralData));
  general_data->general_stats =
      g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL,
                            (GDestroyNotify)destroy_general_stats);
  return general_data;
}

void general_data_free(GeneralData *general_data) {
  g_hash_table_destroy(general_data->general_stats);
  free(general_data);
}

GeneralStats *get_general_stats_by_key(GeneralData *general_data, int key) {
  return g_hash_table_lookup(general_data->general_stats, GINT_TO_POINTER(key));
}

// GENERAL STATS

void add_general_stats_controller(GeneralData *general_data,
                                  GeneralStats *general_stats) {
  int key = get_key_from_general_stats(general_stats);
  g_hash_table_insert(general_data->general_stats, GINT_TO_POINTER(key),
                      general_stats);
}

void update_general_stats_controller(GeneralData *general_data, int key,
                                     int number_of_users, int number_of_flights,
                                     int number_of_passengers, int reservations,
                                     char *user_id) {
  GeneralStats *general_stats =
      g_hash_table_lookup(general_data->general_stats, GINT_TO_POINTER(key));
  if (general_stats == NULL) {
    GeneralStats *general_stats =
        create_general_stats(key, number_of_users, number_of_flights,
                             number_of_passengers, reservations, user_id);
    add_general_stats_controller(general_data, general_stats);
    return;
  } else {
    general_stats = update_general_stats(
        general_stats, key, number_of_users, number_of_flights,
        number_of_passengers, reservations, user_id);
  }
}