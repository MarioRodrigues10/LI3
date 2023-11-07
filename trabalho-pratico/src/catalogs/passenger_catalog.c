#include <glib.h>

#include "catalogs/passengers_catalog.h"
#include "entities/passengers.h"

struct passengers_catalog {
  GHashTable *passengers;
};

PASSENGERS_CATALOG create_passengers_catalog() {
  PASSENGERS_CATALOG new_catalog = malloc(sizeof(struct passengers_catalog));
  new_catalog->passengers = g_hash_table_new_full(
      NULL, g_direct_equal, NULL, (GDestroyNotify)free_passengers_catalog);

  return new_catalog;
}


void add_passenger_to_catalog(PASSENGERS_CATALOG passengers_catalog,
                              PASSENGER passenger, gpointer key) {
  g_hash_table_insert(passengers_catalog->passengers, key, passenger);
}

void free_passengers_catalog(PASSENGERS_CATALOG passengers_catalog) {
  g_hash_table_destroy(passengers_catalog->passengers);
  g_free(passengers_catalog);
}