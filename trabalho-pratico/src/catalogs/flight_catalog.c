#include "catalogs/flight_catalog.h"
#include "entities/flight.h"

#include <glib.h>

struct flight_catalog{
    GHashTable *flight;
};

Flight_Catalog creat_flight_catalog() {
    Flight_Catalog new_catalog= malloc(sizeof(struct Flight_catalog));
    new_catalog -> flights  = g_hash_table_new_full(NULL, g_direct_equal, NULL,(GDestroyNotify)free_flight);

    return new_catalog;
};
