#include "catalogs/flights_catalog.h"

#include <glib.h>

struct flights_catalog {
  GHashTable *flights;
};

FLIGHTS_CATALOG create_flights_catalog() {
  FLIGHTS_CATALOG new_catalog = g_malloc(sizeof(struct flights_catalog));
  new_catalog->flights = g_hash_table_new_full(g_str_hash, g_str_equal, NULL,
                                               (GDestroyNotify)free_flight);

  return new_catalog;
}

void add_flight_to_catalog(FLIGHTS_CATALOG flights_catalog, FLIGHT flight,
                           char *id) {
  g_hash_table_insert(flights_catalog->flights, id, flight);
}

FLIGHT get_flight_by_id(FLIGHTS_CATALOG catalog, char *id) {
  gpointer flight = g_hash_table_lookup(catalog->flights, id);

  if (flight == NULL) return NULL;

  return (FLIGHT)flight;
}

void free_flights_catalog(FLIGHTS_CATALOG flights_catalog) {
  g_hash_table_destroy(flights_catalog->flights);
  g_free(flights_catalog);
}
