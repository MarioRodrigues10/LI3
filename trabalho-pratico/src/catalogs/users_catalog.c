#include "catalogs/users_catalog.h"

#include <glib.h>

struct users_catalog {
  GHashTable *users;
};

USERS_CATALOG create_users_catalog() {
  USERS_CATALOG new_catalog = g_malloc(sizeof(struct users_catalog));
  new_catalog->users = g_hash_table_new_full(g_str_hash, g_str_equal, g_free,
                                             (GDestroyNotify)free_user);

  return new_catalog;
}

void add_user_to_catalog(USERS_CATALOG users_catalog, USER user, gpointer key) {
  g_hash_table_insert(users_catalog->users, key, user);
}

USER get_user_by_username(USERS_CATALOG catalog, char *username) {
  gpointer user = g_hash_table_lookup(catalog->users, username);

  if (user == NULL) return NULL;

  return (USER)user;
}

void free_users_catalog(USERS_CATALOG users_catalog) {
  g_hash_table_destroy(users_catalog->users);
  g_free(users_catalog);
}
