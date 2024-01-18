#include "controllers/passenger_controller.h"

#include <glib.h>

struct passengers_data {
  GHashTable *passengers;
};

// SET UP

PassengersData *passengers_data_new() {
  PassengersData *passengers_data = malloc(sizeof(PassengersData));
  passengers_data->passengers = g_hash_table_new_full(
      g_str_hash, g_str_equal, g_free, (GDestroyNotify)destroy_passenger);
  return passengers_data;
}

void add_passenger(PassengersData *passengers_data, PassengerInfo *passenger) {
  char *flight_id = get_flight_id_passenger(passenger);
  g_hash_table_insert(passengers_data->passengers, flight_id, passenger);
}

void passengers_data_free(PassengersData *passengers_data) {
  g_hash_table_destroy(passengers_data->passengers);
  free(passengers_data);
}

// ACCESS

PassengerInfo *get_passenger_by_passenger_id(PassengersData *passengers_data,
                                             char *passenger_id) {
  return g_hash_table_lookup(passengers_data->passengers, passenger_id);
}
