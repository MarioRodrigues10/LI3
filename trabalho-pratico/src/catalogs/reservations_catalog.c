#include "entities/reservations.h"
#include "catalogs/reservations_catalog.h"

#include <glib.h>

struct reservations_catalog{
    GHashTable *reservations;
};

RESERVATIONS_CATALOG creat_reservations_catalog() {
    RESERVATIONS_CATALOG new_catalog = malloc(sizeof(struct reservations_catalog));
    new_catalog -> reservations = g_hash_table_new_full(NULL, g_direct_equal,NULL,(GDestroyNotify)free_reservations);

    return new_catalog;
}
   