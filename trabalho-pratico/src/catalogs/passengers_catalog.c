#include "entities/passengers.h"


struct passengers_catalog{
    GHashTable *passagers;
};

PASSENGERS creat_passengers_catalog() {
    PASSENGERS_CATALOG new_catalog = maloc(sizeof(struct passengers_catalog));
    new_catalog -> passengers = g_hash_table_new_full(NULL, g_direct_equal,NULL,(GDestroyNotify)free_passengers);

}
   
