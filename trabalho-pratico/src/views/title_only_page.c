#include "views/title_only_page.h"

#include <ncurses.h>
#include <string.h>
#include <unistd.h>

void title_only_page(char *title, int time) {
  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  clear();
  mvprintw(yMax / 2, (xMax - strlen(title)) / 2, title);
  refresh();
  sleep(time);
}
