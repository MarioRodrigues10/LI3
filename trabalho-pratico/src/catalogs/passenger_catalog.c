#include "catalogs/passenger_catalog.h"
#include "entities/passenger.h"

#include <glib.h>


struct passengers_catalog {
  GHashTable *passenger;
};

PASSENGERS_CATALOG create_passengers_catalog() {
  PASSENGERS_CATALOG new_catalog = malloc(sizeof(struct passengers_catalog));
  new_catalog->passenger = g_hash_table_new_full(
      NULL, g_direct_equal, NULL, (GDestroyNotify)free_passenger);

  return new_catalog;
}

void free_passengesrs_catalog(PASSENGERS_CATALOG passengers_catalog){
  g_hash_table_destroy(passengers_catalog->passenger);
  g_free(passengers_catalog);
}