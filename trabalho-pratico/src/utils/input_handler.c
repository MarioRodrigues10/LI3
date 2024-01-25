#include "utils/input_handler.h"

#include <locale.h>
#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "utils/utils.h"
#include "views/load_dataset_page.h"
#include "views/query_menu_page.h"
#include "views/query_result_page.h"
#include "views/title_only_page.h"

int create_directory(const char *folder) {
  struct stat st = {0};

  if (stat(folder, &st) == 0) {
    return 0;
  } else {
    if (mkdir(folder, 0777) == 0) {
      return 0;
    } else {
      return 1;
    }
  }
}

FILE *create_output_file(int queries_counter) {
  char *filename = malloc(sizeof(char) * 256);
  sprintf(filename, "Resultados/command%d_output.txt", queries_counter);
  FILE *output_file = fopen(filename, "w");
  free(filename);

  return output_file;
}

int batch(char **argv) {
  // MODO BATCH

  setlocale(LC_ALL, "");

  FlightsData *flights_data = flights_data_new();
  ReservationsData *reservations_data = reservations_data_new();
  UsersData *users_data = users_data_new();
  StatsUserInfo *users_stats = create_stats_user_information();
  GeneralData *general_data = general_data_new();
  Maping *map = maping_init();

  char *data_folder = argv[1];
  if (create_directory("Resultados") != 0) {
    return 1;
  }

  feeder(data_folder, flights_data, general_data, reservations_data, users_data,
         users_stats, map);

  char *queries_filename = argv[2];
  FILE *queries_file = fopen(queries_filename, "r");
  if (queries_file == NULL) {
    return -1;
  }

  // Create results directory

  char line[256];
  int number_of_queries = 1;

  while (fgets(line, sizeof(line), queries_file) != NULL) {
    // Remove '\n' from line
    line[strcspn(line, "\n")] = '\0';

    FILE *output_file = create_output_file(number_of_queries);
    if (output_file == NULL) {
      return 1;
    }

    printf("[STATUS] Solving query %d\n\n", number_of_queries);

    query_manager(line, flights_data, reservations_data, general_data,
                  users_data, users_stats, map, output_file);

    fclose(output_file);
    number_of_queries++;
  }

  printf("[STATUS] Freeing data...\n");

  fclose(queries_file);

  flights_data_free(flights_data);
  reservations_data_free(reservations_data);
  users_data_free(users_data);
  free_stats_user_information(users_stats);
  general_data_free(general_data);
  maping_free(map);

  return 0;
}

int interactive() {
  // MODO INTERATIVO

  setlocale(LC_ALL, "");

  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);

  char dataset_path[256];
  do {
    dataset_path[0] = '\0';
    dataset_page(dataset_path);
    if (!check_dataset_path(dataset_path)) {
      title_only_page("Invalid dataset...", 2);
    }
  } while (!check_dataset_path(dataset_path));

  FlightsData *flights_data = flights_data_new();
  ReservationsData *reservations_data = reservations_data_new();
  UsersData *users_data = users_data_new();
  StatsUserInfo *users_stats = create_stats_user_information();
  GeneralData *general_data = general_data_new();
  Maping *map = maping_init();

  title_only_page("Loading dataset...", 1);

  if (create_directory("Resultados") != 0) {
    return 1;
  }

  feeder(dataset_path, flights_data, general_data, reservations_data,
         users_data, users_stats, map);

  char line[256];
  line[0] = '\0';
  int number_of_queries = 1;

  int choice = 0;
  while (choice != 11) {
    FILE *output_file = create_output_file(number_of_queries);
    if (output_file == NULL) {
      return 1;
    }
    choice = query_menu_page(line);

    if (choice == 11) {
      break;

    } else if (choice >= 1 && choice <= 10) {
      query_manager(line, flights_data, reservations_data, general_data,
                    users_data, users_stats, map, output_file);
    }
    fclose(output_file);
    query_result_page(number_of_queries);
    number_of_queries++;
  }

  title_only_page("Freeing dataset...", 1);

  flights_data_free(flights_data);
  reservations_data_free(reservations_data);
  users_data_free(users_data);
  free_stats_user_information(users_stats);
  general_data_free(general_data);
  maping_free(map);

  endwin();
  return 0;
}
