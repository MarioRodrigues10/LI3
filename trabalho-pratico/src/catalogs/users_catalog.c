#include "catalogs/users_catalog.h"

struct users_catalog {
  GHashTable *users;
};

USERS_CATALOG create_users_catalog() {
  USERS_CATALOG new_catalog = malloc(sizeof(struct users_catalog));
  new_catalog->users = g_hash_table_new_full(
      NULL, g_direct_equal, NULL, (GDestroyNotify)free_users_catalog);

  return new_catalog;
}

void add_user_to_catalog(USERS_CATALOG users_catalog, USER user, gpointer key) {
  g_hash_table_insert(users_catalog->users, key, user);
}

void free_users_catalog(USERS_CATALOG users_catalog) {
  g_hash_table_destroy(users_catalog->users);
  g_free(users_catalog);
}
