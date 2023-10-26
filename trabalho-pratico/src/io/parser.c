#include "../includes/io/parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** parse_line(char* line, int line_size) {
  char* token;
  char** tokens = (char**)malloc(sizeof(char**) * line_size);
  token = strtok(line, SEPARATOR);
  int iterator = 0;

  while (token != NULL) {
    tokens[iterator] = (char*)malloc(sizeof(char) * (strlen(token) + 1));
    strcpy(tokens[iterator], token);
    token = strtok(NULL, SEPARATOR);
    iterator++;
  }
  free(token);
  return tokens;
}
