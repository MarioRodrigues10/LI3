#include "entities/passenger.h"
#include "catalogs/passenger_catalog.h"

#include <glib.h>

struct passenger_catalog{
    GHashTable *passenger;
};

Passenger_Catalog create_passenger_catalog() {
    Passenger_Catalog new_catalog = malloc(sizeof(struct passenger_catalog));
    new_catalog -> passenger = g_hash_table_new_full(NULL, g_direct_equal,NULL,(GDestroyNotify)free_passenger);
    
    return new_catalog;
}

void free_passenger_catalog(Passenger_Catalog passenger_catalog){
    g_hash_table_destroy(passenger_catalog -> passenger);
    g_free(passenger_catalog);
}