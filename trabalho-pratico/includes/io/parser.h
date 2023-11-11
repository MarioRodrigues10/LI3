#ifndef PARSER_H
#define PARSER_H

#include "catalogs/flights_catalog.h"
#include "catalogs/passengers_catalog.h"
#include "catalogs/reservations_catalog.h"
#include "catalogs/users_catalog.h"
#include "entities/flights.h"
#include "entities/passengers.h"
#include "entities/reservations.h"
#include "entities/users.h"
#include "utils/utils.h"

#define SEPARATOR ";"

typedef void (*function_pointer)(char**, void*);

/**
 * @brief Parses a line
 *
 * @param line The line to be parsed
 * @param num_tokens The number of tokens
 *
 * @return an array of strings
 */
char** parse_line(char* line, int num_tokens);

/**
 * @brief Parses a file
 *
 * @param file The file to be parsed
 * @param catalog The catalog to be used
 * @param function The function to be used
 *
 * @return 0 if successful, -1 otherwise
 */
int parse_file(FILE* file, void* catalog, function_pointer function);

#endif