#include "../includes/io/parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** parse_line(char* line) {
  char* token;
  char** tokens = NULL;
  int size = 0;
  token = strtok(line, SEPARATOR);
  int iterator = 0;

  while (token != NULL) {
    if (iterator >= size) {
      size = (size == 0) ? 1 : size * 2;
      tokens = (char**)realloc(tokens, sizeof(char*) * size);
    }
    tokens[iterator] = (char*)malloc(sizeof(char) * (strlen(token) + 1));
    strcpy(tokens[iterator], token);
    token = strtok(NULL, SEPARATOR);
    iterator++;
  }
  free(token);
  return tokens;
}
