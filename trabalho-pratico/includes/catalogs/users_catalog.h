#ifndef USERS_CATOLOG_H
#define USERS_CATALOG_H

#include "entities/users.h"
typedef struct users_catalog *USERS_CATALOG;
typedef struct user *USER;

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
void add_user_to_catalog(USERS_CATALOG users_catalog, USER user, void *key);

/**
 * @brief Function that gets a user by username
 *
 * @param catalog - The users catalog to get the user from
 * @param username - The username of the user to be gotten
 * @return The user gotten
 */
USER get_user_by_username(USERS_CATALOG catalog, char *username);

/**
 * @brief Function that frees the memory alocated to the users catalog
 *
 * @param users_catalog - The users catalog to be freed of type
 * 'USERS_CATALOG'
 */
void free_users_catalog(USERS_CATALOG users_catalog);

#endif
