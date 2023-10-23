#include "catalogs/flight_catalog.h"

#include <glib.h>

#include "entities/flight.h"

struct flight_catalog {
  GHashTable *flight;
};

Flight_Catalog create_flight_catalog() {
  Flight_Catalog new_catalog = malloc(sizeof(struct flight_catalog));
  new_catalog->flights = g_hash_table_new_full(NULL, g_direct_equal, NULL,
                                               (GDestroyNotify)free_flight);

  return new_catalog;
};

void free_flight_catalog(Flight_Catalog flight_catalog) {
  g_hash_table_destroy(flight_catalog->flight);
  g_free(flight_catalog);
}