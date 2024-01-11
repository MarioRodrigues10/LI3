#include "components/input_getter.h"

#include <ncurses.h>

void get_input(char *input) {
  echo();
  getstr(input);
  noecho();
}
