#include "services/parser_service.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* string_separator(char** line, const char* separator) {
  if (*line == NULL) {
    return NULL;
  }

  char* start = *line;
  char* end = *line;

  while (*end != '\0' && strchr(separator, *end) == NULL) {
    end++;
  }

  if (*end != '\0') {
    *end = '\0';
    *line = end + 1;
  } else {
    *line = NULL;
  }

  return start;
}

int parse_line(char* line, char* tokens[], int num_tokens) {
  int token_count = 0;
  char* token = string_separator(&line, SEPARATOR);

  while (token != NULL && token_count < num_tokens) {
    tokens[token_count] = token;
    token_count++;

    token = string_separator(&line, SEPARATOR);
  }

  return token_count;
}

int parse_file(FILE* file, FILE* errors_file, FlightsData* flights_data,
               GeneralData* general_data, ReservationsData* reservations_data,
               UsersData* users_data, StatsUserInfo* users_stats, Maping* map,
               int type) {
  char line[MAX_LINE_LENGTH];
  char* tokens[MAX_TOKENS];
  char* result;

  // Skip headers of the file
  fgets(line, MAX_LINE_LENGTH, file);

  while ((result = fgets(line, MAX_LINE_LENGTH, file)) != NULL) {
    if (result[strlen(result) - 1] == '\n') {
      result[strlen(result) - 1] = '\0';
    }
    parse_line(line, tokens, MAX_TOKENS);

    switch (type) {
      case 0:
        construct_flight(tokens, flights_data, general_data, map, errors_file);
        break;
      case 1:
        construct_passenger(tokens, users_data, flights_data, general_data,
                            errors_file);
        break;
      case 2:
        construct_reservation(tokens, reservations_data, users_data,
                              general_data, map, errors_file);
        break;
      case 3:
        construct_user(tokens, users_data, users_stats, general_data,
                       errors_file);
        break;
      default:
        // This is not supposed to happen
        printf("Invalid type");
        break;
    }
  }

  return 0;
}
