#ifndef UTILS_H
#define UTILS_H

#include <glib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int string_to_int(char* c) {
  int result = 0;
  int i = 0;
  while (c[i] != '\0') {
    result = result * 10 + c[i] - '0';
    i++;
  }
  return result;
}

int extract_number(char *input) {
  while (*input && !isdigit(*input)) input++;
  return string_to_int(input);
}

#endif