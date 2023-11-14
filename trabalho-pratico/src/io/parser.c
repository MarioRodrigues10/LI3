#define _GNU_SOURCE
#include "io/parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** parse_line(char* line, int num_tokens) {
  char* token;
  char** tokens = (char**)malloc(sizeof(char*) * num_tokens);
  token = strsep(&line, SEPARATOR);
  int iterator = 0;

  while (token != NULL) {
    tokens[iterator] = (char*)malloc(sizeof(char) * (strlen(token) + 1));
    strcpy(tokens[iterator], token);
    token = strsep(&line, SEPARATOR);
    iterator++;
  }
  return tokens;
}

int parse_file(FILE* file, void* catalog, function_pointer build_function,
               STATS stats, int num_tokens) {
  char* line = NULL;
  size_t len = 0;

  // Skip first line
  getline(&line, &len, file);

  while (getline(&line, &len, file) != -1) {
    line[strlen(line) - 1] = '\0';
    char** tokens = parse_line(line, num_tokens);
    build_function(tokens, catalog, stats);
  }
  free(line);

  return 0;
}
