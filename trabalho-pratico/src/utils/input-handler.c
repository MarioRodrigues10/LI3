#include "utils/input-handler.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

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

int input_handler(char **argv) {
  // MODO BATCH
  FlightsData *flights_data = flights_data_new();
  PassengersData *passengers_data = passengers_data_new();
  ReservationsData *reservations_data = reservations_data_new();
  UsersData *users_data = users_data_new();
  StatsUserInfo *users_stats = create_stats_user_information();

  char *data_folder = argv[1];
  if (create_directory("Resultados") != 0) {
    return 1;
  }

  feeder(data_folder, flights_data, passengers_data, reservations_data,
         users_data, users_stats);

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

    query_manager(line, flights_data, passengers_data, reservations_data,
                  users_data, users_stats, output_file);

    fclose(output_file);
    number_of_queries++;
  }

  fclose(queries_file);

  flights_data_free(flights_data);
  passengers_data_free(passengers_data);
  reservations_data_free(reservations_data);
  users_data_free(users_data);
  free_stats_user_information(users_stats);

  return 0;
}
