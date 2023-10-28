#ifndef PARSER_H
#define PARSER_H

#include "../includes/entities/flights.h"
#include "../includes/entities/passengers.h"
#include "../includes/entities/reservations.h"
#include "../includes/entities/users.h"

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