#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "utils/input-handler.h"
#include "utils/utils.h"

int main() {
  setlocale(LC_ALL, "");

  char dataset_path[100];
  char queries_path[100];
  char outputs_path[100];

  printf("===(TESTING)===\n");

  do {
    printf(
        "[DATASET] Insira um caminho válido para a pasta do Dataset a "
        "testar: ");
    scanf("%s", dataset_path);
  } while (!check_dataset_path(dataset_path));

  do {
    printf(
        "[INPUTS] Insira um caminho válido para o ficheiro de inputs "
        "esperados: ");
    scanf("%s", queries_path);
  } while (!check_input_file(queries_path));

  printf(
      "[OUTPUTS] Insira um caminho válido para a pasta de outputs esperados: ");
  scanf("%s", outputs_path);

  printf("\n");

  // MODO BATCH
  struct rusage r_usage;
  getrusage(RUSAGE_SELF, &r_usage);

  FlightsData *flights_data = flights_data_new();
  PassengersData *passengers_data = passengers_data_new();
  ReservationsData *reservations_data = reservations_data_new();
  UsersData *users_data = users_data_new();
  StatsUserInfo *users_stats = create_stats_user_information();
  GeneralData *general_data = general_data_new();
  Maping *map = maping_init();

  char *data_folder = dataset_path;
  if (create_directory("Resultados") != 0) {
    return 1;
  }

  feeder(data_folder, flights_data, general_data, reservations_data, users_data,
         users_stats, map);

  char *queries_filename = queries_path;
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
    char *filename_output_expected = malloc(sizeof(char) * 256);
    sprintf(filename_output_expected, "/command%d_output.txt",
            number_of_queries);

    char *output_path_expected =
        concatenate_strings(outputs_path, filename_output_expected);

    FILE *output_file_expected = fopen(output_path_expected, "r");
    if (output_file_expected == NULL) {
      printf(
          "[ERRO] Verifique se o caminho para a pasta de outputs está "
          "correta...\n");
      return 1;
    }
    free(filename_output_expected);
    free(output_path_expected);
    query_manager_test(line, flights_data, reservations_data, general_data,
                       users_data, users_stats, map, output_file,
                       output_file_expected);

    fclose(output_file);
    number_of_queries++;
  }

  fclose(queries_file);

  flights_data_free(flights_data);
  passengers_data_free(passengers_data);
  reservations_data_free(reservations_data);
  users_data_free(users_data);
  free_stats_user_information(users_stats);
  general_data_free(general_data);
  maping_free(map);

  printf("Memory usage: %ld KB\n", r_usage.ru_maxrss);
  return 0;
}
