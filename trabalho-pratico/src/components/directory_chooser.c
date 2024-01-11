#include "components/directory_chooser.h"

#include <dirent.h>
#include <glib.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

void choose_directory(char *dataset_path) {
  clear();
  refresh();

  int max_y, max_x;
  getmaxyx(stdscr, max_y, max_x);

  int win_height = max_y - 4;
  int win_width = 60;
  int starty = (max_y - win_height) / 2;
  int startx = (max_x - win_width) / 2;

  WINDOW *win = newwin(win_height, win_width, starty, startx);
  box(win, 0, 0);
  mvwprintw(win, 1, (win_width - 24) / 2, "Selecione a pasta do Dataset:");
  mvwprintw(win, 2, (win_width - 29) / 2,
            "(Use as Setas para navegar e Enter para selecionar)");

  wrefresh(win);

  int ch;
  int highlight = 0;
  DIR *dir;
  struct dirent *ent;
  char **directories = malloc(100 * sizeof(char *));
  int num_dirs = 0;
  char current_dir[256];
  getcwd(current_dir, sizeof(current_dir));

  if ((dir = opendir(current_dir)) != NULL) {
    while ((ent = readdir(dir)) != NULL) {
      struct stat path_stat;
      stat(ent->d_name, &path_stat);
      if (S_ISDIR(path_stat.st_mode)) {
        directories[num_dirs] = g_strdup(ent->d_name);
        num_dirs++;
      }
    }
    closedir(dir);

    int selected = 0;
    do {
      werase(win);

      box(win, 0, 0);
      mvwprintw(win, 1, (win_width - 30) / 2, "Selecione a pasta do Dataset:");
      mvwprintw(win, 2, (win_width - 50) / 2,
                "(Use as Setas para navegar e Enter para selecionar)");

      for (int i = 0; i < num_dirs; i++) {
        if (i == highlight) {
          wattron(win, A_REVERSE);
        }
        mvwprintw(win, i + 4, 2, "%s", directories[i]);
        wattroff(win, A_REVERSE);
      }
      wrefresh(win);

      ch = getch();

      switch (ch) {
        case KEY_UP:
          if (highlight > 0) {
            highlight--;
          }
          break;
        case KEY_DOWN:
          if (highlight < num_dirs - 1) {
            highlight++;
          }
          break;
        case KEY_LEFT:
          chdir("..");
          getcwd(current_dir, sizeof(current_dir));
          num_dirs = 0;
          if ((dir = opendir(current_dir)) != NULL) {
            while ((ent = readdir(dir)) != NULL) {
              struct stat path_stat;
              stat(ent->d_name, &path_stat);
              if (S_ISDIR(path_stat.st_mode)) {
                directories[num_dirs] = g_strdup(ent->d_name);
                num_dirs++;
              }
            }
            closedir(dir);
          }
          break;
        case KEY_RIGHT:
          chdir(directories[highlight]);
          getcwd(current_dir, sizeof(current_dir));
          num_dirs = 0;
          if ((dir = opendir(current_dir)) != NULL) {
            while ((ent = readdir(dir)) != NULL) {
              struct stat path_stat;
              stat(ent->d_name, &path_stat);
              if (S_ISDIR(path_stat.st_mode)) {
                directories[num_dirs] = g_strdup(ent->d_name);
                num_dirs++;
              }
            }
            closedir(dir);
          }
          break;
        case '\n':
          selected = 1;
          break;
        default:
          break;
      }
    } while (!selected);

    strcpy(dataset_path, directories[highlight]);
    for (int i = 0; i < num_dirs; i++) {
      free(directories[i]);
    }
    free(directories);
  }

  delwin(win);
}
