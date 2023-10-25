#include <glib.h>

#include "catalogs/flights_catalog.h"
#include "entities/flight.h"

struct flights_catalog {
  GHashTable *flight;
};

FlIGHTS_CATALOG create_flights_catalog() {
  FlIGHTS_CATALOG new_catalog = malloc(sizeof(struct flights_catalog));
  new_catalog->flights = g_hash_table_new_full(NULL, g_direct_equal, NULL,
                                               (GDestroyNotify)free_flight);

  return new_catalog;
};

void free_flights_catalog(FlIGHTS_CATALOG flights_catalog) {
  g_hash_table_destroy(flights_catalog->flight);
  g_free(flights_catalog);
}