#include "../includes/parser.h"

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/entities/flights.h"
#include "../includes/entities/passengers.h"
#include "../includes/entities/reservations.h"
#include "../includes/entities/users.h"

struct line {
  char** lines;
  int size;
};

Line parseLines(char* line) {
  char* token;
  char** lines = NULL;

  token = strtok(line, ";");
  int contador = 0;
  while (token != NULL) {
    lines = (char**)realloc(lines, sizeof(char*) * (strlen(token) + 1));
    lines[strlen(token)] = (char*)malloc(sizeof(char) * (strlen(token) + 1));
    strcpy(lines[strlen(token)], token);
    token = strtok(NULL, ";");
    contador++;
  }

  Line lineStruct = malloc(sizeof(Line));
  lineStruct->lines = lines;
  lineStruct->size = contador;
  return lineStruct;
}

void parse_file(char* filename, int size, int type) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file\n");
    exit(1);
  }
  char line[MAX_FIELD_SIZE * 13];

  while (fgets(line, sizeof(line), file) != NULL) {
    Line line_parsed = parseLines(line);
    if (size > line_parsed->size) {
      // TODO: No if acima verificar os erros de cada linha
      // TODO: Criar entidade
    } else {
      // TODO: Escrever no ficheiro de erros
    }
  }
  fclose(file);
}