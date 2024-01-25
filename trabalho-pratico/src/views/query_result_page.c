#include <glib.h>
#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_LINES_PER_PAGE 20

int read_lines_from_file(const char *filename, char ***lines) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return -1;
  }

  char buffer[256];
  int num_lines = 0;
  *lines = (char **)malloc(1000 * sizeof(char *));

  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    (*lines)[num_lines] = g_strdup(buffer);
    num_lines++;
  }

  fclose(file);
  return num_lines;
}

void free_lines(char **lines, int num_lines) {
  for (int i = 0; i < num_lines; ++i) {
    g_free(lines[i]);
  }
  free(lines);
}

void query_result_page(int number_of_queries) {
  char filename[256];
  sprintf(filename, "Resultados/command%d_output.txt", number_of_queries);
  char **lines = NULL;
  int total_lines = read_lines_from_file(filename, &lines);

  if (total_lines == -1) {
    printf("Error opening file.\n");
    return;
  }

  if (total_lines <= 0) {
    clear();
    mvprintw(LINES / 2,
             (COLS - strlen("The inserted parameters are invalid...")) / 2,
             "The inserted parameters are invalid...");

    refresh();
    sleep(2);
    return;
  }

  int start = 0;
  int end = MAX_LINES_PER_PAGE;
  int page = 1;
  int max_pages = (total_lines + MAX_LINES_PER_PAGE - 1) / MAX_LINES_PER_PAGE;

  int selected_button = 1;

  while (1) {
    clear();

    int line_offset = (LINES - MAX_LINES_PER_PAGE) / 2;
    for (int i = start, j = 0; i < end && i < total_lines; ++i, ++j) {
      int col_offset = (COLS - strlen(lines[i])) / 2;
      mvprintw(line_offset + j, col_offset, "%s", lines[i]);
    }

    mvprintw(line_offset - 4, (COLS - 17) / 2, "Query Result:");

    mvprintw(LINES - 2, (COLS - 10) / 2, "Page %d of %d", page, max_pages);

    int button_row = LINES - 5;
    mvprintw(button_row, COLS - 20, "Previous page");
    mvprintw(button_row + 1, COLS - 20, "Next page");
    mvprintw(button_row + 3, COLS - 20, "Exit");

    mvchgat(button_row, COLS - 20, -1,
            (selected_button == 1) ? A_REVERSE : A_NORMAL, 0, NULL);
    mvchgat(button_row + 1, COLS - 20, -1,
            (selected_button == 2) ? A_REVERSE : A_NORMAL, 0, NULL);
    mvchgat(button_row + 3, COLS - 20, -1,
            (selected_button == 3) ? A_REVERSE : A_NORMAL, 0, NULL);

    refresh();

    int ch = getch();
    if (ch == KEY_UP && selected_button > 1) {
      selected_button--;
    } else if (ch == KEY_DOWN && selected_button < 3) {
      selected_button++;
    } else if (ch == '\n') {
      if (selected_button == 1 && start > 0) {
        start -= MAX_LINES_PER_PAGE;
        end -= MAX_LINES_PER_PAGE;
        page--;
      } else if (selected_button == 2 && end < total_lines) {
        start += MAX_LINES_PER_PAGE;
        end += MAX_LINES_PER_PAGE;
        page++;
      } else if (selected_button == 3) {
        break;
      }
    } else if (ch == 'q' && selected_button == 3) {
      break;
    }
  }

  if (lines) {
    free_lines(lines, total_lines);
  }
}
