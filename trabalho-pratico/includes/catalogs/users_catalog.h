#ifndef USERS_CATOLOG_H
#define USERS_CATALOG_H

#include <glib.h>

#include "entities/users.h"
typedef struct users_catalog *USERS_CATALOG;

/**
 * @brief Function that creates the users catalog
 *
 * @return The users catalog created
 */
USERS_CATALOG create_users_catalog();

/**
 * @brief Function that adds a user to the users catalog
 *
 * @param users_catalog - The users catalog to add the user to
 * @param user - The user to be added to the users catalog
 * @param key - The key of the user to be added to the users catalog
 */
void add_user_to_catalog(USERS_CATALOG users_catalog, USER user, gpointer key);

/**
 * @brief Function that frees the memory alocated to the users catalog
 *
 * @param users_catalog - The users catalog to be freed of type
 * 'USERS_CATALOG'
 */
void free_users_catalog(USERS_CATALOG users_catalog);

#endif
