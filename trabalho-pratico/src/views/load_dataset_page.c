#include "views/load_dataset_page.h"

#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "components/directory_chooser.h"
#include "components/input_getter.h"

void display_ascii_art() {
  char *ascii_art[] = {
      "  ______ _ _       _     _     __  __                                  "
      " ",
      " |  ____| (_)     | |   | |   |  \\/  |                                 "
      " ",
      " | |__  | |_  __ _| |__ | |_  | \\  / | __ _ _ __   __ _  __ _  ___ _ "
      "__ ",
      " |  __| | | |/ _` | '_ \\| __| | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ "
      "'__|",
      " | |    | | | (_| | | | | |_  | |  | | (_| | | | | (_| | (_| |  __/ |  "
      " ",
      " |_|    |_|_|\\__, |_| |_|\\__| |_|  |_|\\__,_|_| |_|\\__,_|\\__, "
      "|\\___|_|   ",
      "              __/ |                                      __/ |         "
      " ",
      "             |___/                                      |___/          "
      " "};

  int row, col;
  getmaxyx(stdscr, row, col);

  int start_y = (row - 30) / 2;
  int start_x = (col - 70) / 2;

  for (int i = 0; i < 8; ++i) {
    mvprintw(start_y + i, start_x, "%s", ascii_art[i]);
  }

  char *modo_interativo = "Modo Interativo";
  int text_length = strlen(modo_interativo);
  int text_x = (col - text_length) / 2;
  mvprintw(start_y + 8, text_x, "%s", modo_interativo);

  refresh();
}

void display_buttons(int selected_option) {
  const char *options[] = {"Escolher Dataset", "Escrever Dataset"};
  int row, col;
  getmaxyx(stdscr, row, col);
  int start_y = (row - 20) / 2 + 10;
  int start_x = (col - 16) / 2;

  for (int i = 0; i < 2; ++i) {
    if (i == selected_option) {
      attron(A_REVERSE);
    }
    mvprintw(start_y + i, start_x, "%s", options[i]);
    attroff(A_REVERSE);
  }

  refresh();
}

void input_textbox(char *dataset_path) {
  int row, col;
  getmaxyx(stdscr, row, col);
  int textbox_length = strlen("Digite o caminho para o dataset: ");
  int start_x = (col - textbox_length - 60) / 2;
  int start_y = row / 2 + 5;

  mvprintw(start_y, start_x, "Digite o caminho para o dataset: ");
  refresh();

  get_input(dataset_path);
}

void dataset_page(char *dataset_path) {
  int selected_option = 0;
  int ch;
  bool done = false;
  while (!done) {
    clear();
    display_ascii_art();
    display_buttons(selected_option);
    refresh();
    ch = getch();

    switch (ch) {
      case KEY_UP:
        selected_option--;
        if (selected_option < 0) {
          selected_option = 1;
        }
        break;
      case KEY_DOWN:
        selected_option++;
        if (selected_option > 1) {
          selected_option = 0;
        }
        break;
      case '\n':
        if (selected_option == 0) {
          choose_directory(dataset_path);
          done = true;
        } else {
          input_textbox(dataset_path);
          done = true;
        }
        break;
      default:
        break;
    }
  }
  refresh();
}
