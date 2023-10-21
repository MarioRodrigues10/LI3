#include "catalogs/flights_catalog.h"
#include "entities/flights.h"

#include <glib.h>

struct flights_catalog{
    GHashTable *flights;
};

FLIGHTS_CATALOG creat_flights_catalog() {
    FLIGHTS_CATALOG new_catalog= malloc(sizeof(struct flights_catalog));
    new_catalog -> flights  = g_hash_table_new_full(NULL, g_direct_equal, NULL,(GDestroyNotify)free_flights);

    return new_catalog;
};
