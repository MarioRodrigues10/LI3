#include "../includes/parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** parseLine(char* line) {
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

  return tokens;
}

char*** parseFile(char* filename) {
  FILE* file = fopen(filename, "r");

  if (file == NULL) {
    printf("Error opening file\n");
    exit(1);
  }

  char line[MAX_FIELD_SIZE * 13];
  char*** lines = NULL;
  int counter = 0;
  int size = 0;

  while (fgets(line, sizeof(line), file) != NULL) {
    char** parsedLine = parseLine(line);
    if (parsedLine == NULL) {
      break;
    }
    if (counter >= size) {
      size = (size == 0) ? 1 : size * 2;
      lines = (char***)realloc(lines, sizeof(char**) * size);
    }
    lines[counter] = (char**)malloc(sizeof(char*) * (MAX_FIELD_SIZE + 1));
    int iterator = 0;
    while (parsedLine[iterator] != NULL) {
      lines[counter][iterator] =
          (char*)malloc(sizeof(char) * (strlen(parsedLine[iterator]) + 1));
      strcpy(lines[counter][iterator], parsedLine[iterator]);
      free(parsedLine[iterator]);
      iterator++;
    }
    free(parsedLine);
    counter++;
  }
  fclose(file);

  return lines;
}
