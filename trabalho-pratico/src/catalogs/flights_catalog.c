#include "catalogs/flights_catalog.h"

#include <glib.h>

struct flights_catalog {
  GHashTable* flights;
};

FLIGHTS_CATALOG create_flights_catalog() {
  FLIGHTS_CATALOG new_catalog = g_malloc(sizeof(struct flights_catalog));
  new_catalog->flights = g_hash_table_new_full(NULL, g_direct_equal, NULL,
                                               (GDestroyNotify)free_flight);

  return new_catalog;
}

void add_flight_to_catalog(FLIGHTS_CATALOG flights_catalog, FLIGHT flight,
                           void* key) {
  g_hash_table_insert(flights_catalog->flights, key, flight);
}

void free_flights_catalog(FLIGHTS_CATALOG flights_catalog) {
  g_hash_table_destroy(flights_catalog->flights);
  g_free(flights_catalog);
}
