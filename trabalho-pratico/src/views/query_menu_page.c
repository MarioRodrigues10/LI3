#include "views/query_menu_page.h"

#include <ncurses.h>
#include <string.h>

#include "components/input_getter.h"

void draw_buttons(WINDOW *win, const char *options[], int n_options,
                  int current_option) {
  int max_y, max_x;
  getmaxyx(win, max_y, max_x);

  int title_x = (max_x - strlen("Escolha a query a executar:")) / 2;
  mvwprintw(win, 5, title_x, "Escolha a query a executar:");

  int start_y = (max_y - n_options * 2) / 2 - 2;
  int start_x = max_x / 2;

  int spacing = 2;

  for (int i = 0; i < n_options; ++i) {
    if (i == current_option) {
      wattron(win, A_REVERSE);
    }
    mvwprintw(win, start_y + i * spacing + 3,
              start_x - (strlen(options[i]) / 2), "%s", options[i]);
    wattroff(win, A_REVERSE);
  }

  wrefresh(win);
}

int query_menu_page(char *line) {
  int choice = 0;
  int key;
  const char *options[] = {"Query 1", "Query 2",  "Query 3", "Query 4",
                           "Query 5", "Query 6",  "Query 7", "Query 8",
                           "Query 9", "Query 10", "Sair"};
  int n_options = sizeof(options) / sizeof(options[0]);

  while (1) {
    clear();

    draw_buttons(stdscr, options, n_options, choice);

    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(max_y - 2, (max_x - 210) / 2,
             "_________________________________________________________________"
             "_________________________________________________________________"
             "_________________________________________________________________"
             "______________");

    refresh();

    key = getch();

    switch (key) {
      case KEY_UP:
        choice = (choice - 1 + n_options) % n_options;
        break;
      case KEY_DOWN:
        choice = (choice + 1) % n_options;
        break;
      case 10:
        if (choice + 1 == 11) {
          return 11;
        } else {
          mvprintw(max_y - 1, 1, "                                        ");
          mvprintw(max_y - 1, 1, "Insira os argumentos: %d ", choice + 1);
          refresh();
          flushinp();

          line[0] = '\0';
          char temp[256];
          get_input(temp);
          char choice_string[20];
          sprintf(choice_string, "%d", choice + 1);
          strcat(line, choice_string);
          strcat(line, " ");
          strcat(line, temp);
          return choice + 1;
        }
    }
  }

  return choice + 1;
}
