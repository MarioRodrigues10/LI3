#ifndef PARSER_H
#define PARSER_H

#include "entities/flights.h"
#include "entities/passengers.h"
#include "entities/reservations.h"
#include "entities/users.h"

#define SEPARATOR ";"

/**
 * @brief Parses a line
 *
 * @param line The line to be parsed
 * @param num_tokens The number of tokens
 *
 * @return an array of strings
 */
char** parse_line(char* line, int num_tokens);

#endif