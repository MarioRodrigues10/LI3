#include "catalogs/reservation_catalog.h"

#include <glib.h>

#include "entities/reservation.h"

struct reservations_catalog {
  GHashTable *reservation;
};

Reservation_Catalog create_reservations_catalog() {
  Reservation_Catalog new_catalog = malloc(sizeof(struct reservations_catalog));
  new_catalog->reservations = g_hash_table_new_full(
      NULL, g_direct_equal, NULL, (GDestroyNotify)free_reservation);

  return new_catalog;
}

void free_reservations_catalog(Reservation_Catalog catalog) {
  g_hash_table_destroy(catalog->reservations);
  free(catalog);
}
