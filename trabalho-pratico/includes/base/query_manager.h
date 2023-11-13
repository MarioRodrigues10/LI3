#ifndef QUERY_MANAGER_H
#define QUERY_MANAGER_H

#include "catalogs/flights_catalog.h"
#include "catalogs/passengers_catalog.h"
#include "catalogs/reservations_catalog.h"
#include "catalogs/users_catalog.h"
#include "entities/flights.h"
#include "entities/passengers.h"
#include "entities/reservations.h"
#include "entities/users.h"
#include "utils/utils.h"

#define MAX_LINE_SIZE 4

typedef void *(*query_function_pointer)(
    char **query_params, FLIGHTS_CATALOG flights_catalog,
    PASSENGERS_CATALOG passengers_catalog,
    RESERVATIONS_CATALOG reservations_catalog, USERS_CATALOG users_catalog);

/**
 * @brief Function that executes the query manager
 *
 * @param line - The line to be processed
 * @param flights_catalog - The flights catalog of type 'FLIGHTS_CATALOG'
 * @param passengers_catalog - The passengers catalog of type
 * 'PASSENGERS_CATALOG'
 * @param reservations_catalog - The reservations catalog of type
 * 'RESERVATIONS_CATALOG'
 * @param users_catalog - The users catalog of type 'USERS_CATALOG'
 *
 * @return The result of the query
 *
 */
void *query_manager(char *line, FLIGHTS_CATALOG flights_catalog,
                    PASSENGERS_CATALOG passengers_catalog,
                    RESERVATIONS_CATALOG reservations_catalog,
                    USERS_CATALOG users_catalog);

/**
 * @brief Function that executes the query 1
 *
 * @param query_params - The query parameters
 * @param flights_catalog - The flights catalog of type 'FLIGHTS_CATALOG'
 * @param passengers_catalog - The passengers catalog of type
 * 'PASSENGERS_CATALOG'
 * @param reservations_catalog - The reservations catalog of type
 * 'RESERVATIONS_CATALOG'
 * @param users_catalog - The users catalog of type 'USERS_CATALOG'
 *
 * @return The result of the query
 *
 */
void *query1(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog);

/**
 * @brief Function that executes the query 2
 *
 * @param query_params - The query parameters
 * @param flights_catalog - The flights catalog of type 'FLIGHTS_CATALOG'
 * @param passengers_catalog - The passengers catalog of type
 * 'PASSENGERS_CATALOG'
 * @param reservations_catalog - The reservations catalog of type
 * 'RESERVATIONS_CATALOG'
 * @param users_catalog - The users catalog of type 'USERS_CATALOG'
 *
 * @return The result of the query
 *
 */
void *query2(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog);

/**
 * @brief Function that executes the query 3
 *
 * @param query_params - The query parameters
 * @param flights_catalog - The flights catalog of type 'FLIGHTS_CATALOG'
 * @param passengers_catalog - The passengers catalog of type
 * 'PASSENGERS_CATALOG'
 * @param reservations_catalog - The reservations catalog of type
 * 'RESERVATIONS_CATALOG'
 * @param users_catalog - The users catalog of type 'USERS_CATALOG'
 *
 * @return The result of the query
 *
 */
void *query3(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog);

/**
 * @brief Function that executes the query 4
 *
 * @param query_params - The query parameters
 * @param flights_catalog - The flights catalog of type 'FLIGHTS_CATALOG'
 * @param passengers_catalog - The passengers catalog of type
 * 'PASSENGERS_CATALOG'
 * @param reservations_catalog - The reservations catalog of type
 * 'RESERVATIONS_CATALOG'
 * @param users_catalog - The users catalog of type 'USERS_CATALOG'
 *
 * @return The result of the query
 *
 */
void *query4(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog);

/**
 * @brief Function that executes the query 5
 *
 * @param query_params - The query parameters
 * @param flights_catalog - The flights catalog of type 'FLIGHTS_CATALOG'
 * @param passengers_catalog - The passengers catalog of type
 * 'PASSENGERS_CATALOG'
 * @param reservations_catalog - The reservations catalog of type
 * 'RESERVATIONS_CATALOG'
 * @param users_catalog - The users catalog of type 'USERS_CATALOG'
 *
 * @return The result of the query
 *
 */
void *query5(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog);

/**
 * @brief Function that executes the query 6
 *
 * @param query_params - The query parameters
 * @param flights_catalog - The flights catalog of type 'FLIGHTS_CATALOG'
 * @param passengers_catalog - The passengers catalog of type
 * 'PASSENGERS_CATALOG'
 * @param reservations_catalog - The reservations catalog of type
 * 'RESERVATIONS_CATALOG'
 * @param users_catalog - The users catalog of type 'USERS_CATALOG'
 *
 * @return The result of the query
 *
 */
void *query6(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog);

/**
 * @brief Function that executes the query 7
 *
 * @param query_params - The query parameters
 * @param flights_catalog - The flights catalog of type 'FLIGHTS_CATALOG'
 * @param passengers_catalog - The passengers catalog of type
 * 'PASSENGERS_CATALOG'
 * @param reservations_catalog - The reservations catalog of type
 * 'RESERVATIONS_CATALOG'
 * @param users_catalog - The users catalog of type 'USERS_CATALOG'
 *
 * @return The result of the query
 *
 */
void *query7(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog);

/**
 * @brief Function that executes the query 8
 *
 * @param query_params - The query parameters
 * @param flights_catalog - The flights catalog of type 'FLIGHTS_CATALOG'
 * @param passengers_catalog - The passengers catalog of type
 * 'PASSENGERS_CATALOG'
 * @param reservations_catalog - The reservations catalog of type
 * 'RESERVATIONS_CATALOG'
 * @param users_catalog - The users catalog of type 'USERS_CATALOG'
 *
 * @return The result of the query
 *
 */
void *query8(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog);

/**
 * @brief Function that executes the query 9
 *
 * @param query_params - The query parameters
 * @param flights_catalog - The flights catalog of type 'FLIGHTS_CATALOG'
 * @param passengers_catalog - The passengers catalog of type
 * 'PASSENGERS_CATALOG'
 * @param reservations_catalog - The reservations catalog of type
 * 'RESERVATIONS_CATALOG'
 * @param users_catalog - The users catalog of type 'USERS_CATALOG'
 *
 * @return The result of the query
 *
 */
void *query9(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog);

/**
 * @brief Function that executes the query 10
 *
 * @param query_params - The query parameters
 * @param flights_catalog - The flights catalog of type 'FLIGHTS_CATALOG'
 * @param passengers_catalog - The passengers catalog of type
 * 'PASSENGERS_CATALOG'
 * @param reservations_catalog - The reservations catalog of type
 * 'RESERVATIONS_CATALOG'
 * @param users_catalog - The users catalog of type 'USERS_CATALOG'
 *
 * @return The result of the query
 *
 */
void *query10(char **query_params, FLIGHTS_CATALOG flights_catalog,
              PASSENGERS_CATALOG passengers_catalog,
              RESERVATIONS_CATALOG reservations_catalog,
              USERS_CATALOG users_catalog);
#endif