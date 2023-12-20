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

char** parse_line(char* line, int num_tokens) {
  char** tokens = malloc(num_tokens * sizeof(char*));
  if (!tokens) {
    printf("Memory allocation error");
  }

  char* token;
  int token_count = 0;

  while ((token = string_separator(&line, SEPARATOR)) != NULL &&
         token_count < num_tokens) {
    size_t len = strlen(token);
    tokens[token_count] = malloc((len + 1) * sizeof(char));
    if (!tokens[token_count]) {
      printf("Memory allocation error");
    }
    strcpy(tokens[token_count], token);
    token_count++;
  }

  return tokens;
}

void free_tokens(char** tokens, int num_tokens) {
  for (int i = 0; i < num_tokens; ++i) {
    free(tokens[i]);
  }

  free(tokens);
}

int parse_file(FILE* file, FILE* errors_file, FlightsData* flights_data,
               PassengersData* passengers_data,
               ReservationsData* reservations_data, UsersData* users_data,
               StatsUserInfo* users_stats, int type, int num_tokens) {
  char line[MAX_LINE_LENGTH];
  char* result;

  // Skip headers of the file
  fgets(line, MAX_LINE_LENGTH, file);

  while ((result = fgets(line, MAX_LINE_LENGTH, file)) != NULL) {
    if (result[strlen(result) - 1] == '\n') {
      result[strlen(result) - 1] = '\0';
    }

    char** tokens = parse_line(line, num_tokens);

    switch (type) {
      case 0:
        construct_flight(tokens, flights_data, errors_file);
        break;
      case 1:
        construct_passenger(tokens, users_data, flights_data, errors_file);
        break;
      case 2:
        construct_reservation(tokens, reservations_data, users_data,
                              errors_file);
        break;
      case 3:
        construct_user(tokens, users_data, users_stats, errors_file);
        break;
      default:
        // This is not supposed to happen
        printf("Invalid type");
        break;
    }

    // free_tokens(tokens, num_tokens);
  }

  return 0;
}
