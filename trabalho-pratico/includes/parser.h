#ifndef PARSER_H
#define PARSER_H

#include "../includes/entities/flights.h"
#include "../includes/entities/passengers.h"
#include "../includes/entities/reservations.h"
#include "../includes/entities/users.h"

#define SEPARATOR ";"
#define MAX_LINE_SIZE 1024

typedef struct line* Line;

/**
 * @brief Parses a line
 * @param line The line to be parsed
 * @return an array of strings
 */
char** parseLine(char* line);

/**
 * @brief Parses a file
 * @param filename The path of the file to be parsed
 * @return an array of parsed lines
 */
char*** parseFile(char* filename);

#endif