#ifndef PARSER_H
#define PARSER_H

#include "../includes/entities/flights.h"
#include "../includes/entities/passengers.h"
#include "../includes/entities/reservations.h"
#include "../includes/entities/users.h"

#define SEPARATOR ";"
#define MAX_LINE_SIZE 1024

/**
 * @brief Parses a line
 * @param line The line to be parsed
 * @return an array of strings
 */
char** parse_line(char* line, int line_size);

#endif