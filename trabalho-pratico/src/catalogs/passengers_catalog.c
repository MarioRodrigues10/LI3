#include "entities/passengers.h"
#include "catalogs/passengers_catalog.h"

#include <glib.h>

struct passengers_catalog{
    GHashTable *passengers;
};

PASSENGERS_CATALOG creat_passengers_catalog() {
    PASSENGERS_CATALOG new_catalog = malloc(sizeof(struct passengers_catalog));
    new_catalog -> passengers = g_hash_table_new_full(NULL, g_direct_equal,NULL,(GDestroyNotify)free_passengers);
    
    return new_catalog;
}
