#include <glib.h>

#include "catalogs/reservations_catalog.h"
#include "entities/reservations.h"

struct reservations_catalog {
  GHashTable *reservations;
};

RESERVATIONS_CATALOG create_reservations_catalog() {
  RESERVATIONS_CATALOG new_catalog =
      malloc(sizeof(struct reservations_catalog));
  new_catalog->reservations = g_hash_table_new_full(
      NULL, g_direct_equal, NULL, (GDestroyNotify)free_reservation);

  return new_catalog;
}

void free_reservations_catalog(RESERVATIONS_CATALOG reservations_catalog) {
  g_hash_table_destroy(reservations_catalog->reservations);
  free(reservations_catalog);
}
