#ifndef PARSER_H
#define PARSER_H

#include "../includes/entities/flights.h"
#include "../includes/entities/passengers.h"
#include "../includes/entities/reservations.h"
#include "../includes/entities/users.h"

#define MAX_FIELD_SIZE 256

typedef struct line* Line;

Line parseLines(char* filename);
void parse_file(char* filename, int size, int type);

#endif