#ifndef PARSER_H
#define PARSER_H

#include "../includes/entities/flights.h"
#include "../includes/entities/passengers.h"
#include "../includes/entities/reservations.h"
#include "../includes/entities/users.h"

#define MAX_FIELD_SIZE 256

typedef struct line* Line;

/**
 * @brief Parses a line
 * @param line The line to be parsed
 * @return The parsed line and its size
 */
Line parseLines(char* line);

/**
 * @brief Parses a file
 * @param filename The path of the file to be parsed
 * @param size The length of the line to be parsed
 * @param type The type of the file to be parsed
 */
void parse_file(char* filename, int size);

#endif