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
    RESERVATIONS_CATALOG reservations_catalog, USERS_CATALOG users_catalog,
    STATS stats);

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
                    USERS_CATALOG users_catalog, STATS stats);

/**
 * @struct query1_result - Struct that represents the result of query 1 to be
 * used in other places of the program
 */
typedef struct query1_result *QUERY1_RESULT;

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
 * @param stats - The stats of type 'STATS'
 *
 * @return The result of the query
 *
 */
void *query1(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog, STATS stats);

/**
 * @struct query2_result - Struct that represents the result of query 2 to be
 * used in other places of the program
 */
typedef struct query2_result *QUERY2_RESULT;

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
 * @param stats - The stats of type 'STATS'
 *
 * @return The result of the query
 *
 */
void *query2(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog, STATS stats);

/**
 * @struct query3_result - Struct that represents the result of query 3 to be
 * used in other places of the program
 */
typedef struct query3_result *QUERY3_RESULT;

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
 * @param stats - The stats of type 'STATS'
 *
 * @return The result of the query
 *
 */
void *query3(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog, STATS stats);

/**
 * @struct query4_result - Struct that represents the result of query 4 to be
 * used in other places of the program
 */
typedef struct query4_result *QUERY4_RESULT;

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
 * @param stats - The stats of type 'STATS'
 *
 * @return The result of the query
 *
 */
void *query4(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog, STATS stats);

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
 * @param stats - The stats of type 'STATS'
 *
 * @return The result of the query
 *
 */
void *query5(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog, STATS stats);

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
 * @param stats - The stats of type 'STATS'
 *
 * @return The result of the query
 *
 */
void *query6(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog, STATS stats);

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
 * @param stats - The stats of type 'STATS'
 *
 * @return The result of the query
 *
 */
void *query7(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog, STATS stats);

/**
 * @struct query8_result - Struct that represents the result of query 4 to be
 * used in other places of the program
 */
typedef struct query8_result *QUERY8_RESULT;

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
 * @param stats - The stats of type 'STATS'
 *
 * @return The result of the query
 *
 */
void *query8(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog, STATS stats);

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
 * @param stats - The stats of type 'STATS'
 *
 * @return The result of the query
 *
 */
void *query9(char **query_params, FLIGHTS_CATALOG flights_catalog,
             PASSENGERS_CATALOG passengers_catalog,
             RESERVATIONS_CATALOG reservations_catalog,
             USERS_CATALOG users_catalog, STATS stats);

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
 * @param stats - The stats of type 'STATS'
 *
 * @return The result of the query
 *
 */
void *query10(char **query_params, FLIGHTS_CATALOG flights_catalog,
              PASSENGERS_CATALOG passengers_catalog,
              RESERVATIONS_CATALOG reservations_catalog,
              USERS_CATALOG users_catalog, STATS stats);

/**
 * @brief Wrapper function that frees the memory allocated for the specified
 * query result
 * @param result The result to be freed of `type void *`
 * @param query_type The type of the query of type `char`
 */
void free_query_result(void *result, char query_type);

typedef void (*free_query_result_function_pointer)(void *result);

/**
 * @brief Function that frees the memory allocated for the result of query 1
 *
 * @param result - The result of type `void *`
 */
void free_query1_result(void *result);

/**
 * @brief Function that frees the memory allocated for the result of query 2
 *
 * @param result - The result of type `void *`
 */
void free_query2_result(void *result);

/**
 * @brief Function that frees the memory allocated for the result of query 3
 *
 * @param result - The result of type `void *`
 */
void free_query3_result(void *result);

/**
 * @brief Function that frees the memory allocated for the result of query 4
 *
 * @param result - The result of type `void *`
 */
void free_query4_result(void *result);

/**
 * @brief Function that frees the memory allocated for the result of query 5
 *
 * @param result - The result of type `void *`
 */
void free_query5_result(void *result);

/**
 * @brief Function that frees the memory allocated for the result of query 6
 *
 * @param result - The result of type `void *`
 */
void free_query6_result(void *result);

/**
 * @brief Function that frees the memory allocated for the result of query 7
 *
 * @param result - The result of type `void *`
 */
void free_query7_result(void *result);

/**
 * @brief Function that frees the memory allocated for the result of query 8
 *
 * @param result - The result of type `void *`
 */
void free_query8_result(void *result);

/**
 * @brief Function that frees the memory allocated for the result of query 9
 *
 * @param result - The result of type `void *`
 */
void free_query9_result(void *result);

/**
 * @brief Function that frees the memory allocated for the result of query 10
 *
 * @param result - The result of type `void *`
 */
void free_query10_result(void *result);

#endif