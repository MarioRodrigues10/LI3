#define _DEFAULT_SOURCE

#include "services/queries_service.h"

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

#include "services/queries/query1.h"
#include "services/queries/query10.h"
#include "services/queries/query2.h"
#include "services/queries/query3.h"
#include "services/queries/query4.h"
#include "services/queries/query5.h"
#include "services/queries/query6.h"
#include "services/queries/query7.h"
#include "services/queries/query8.h"
#include "services/queries/query9.h"

void query_manager(char *line, FlightsData *flights_data,
                   ReservationsData *reservations_data,
                   GeneralData *general_data, UsersData *users_data,
                   StatsUserInfo *users_stats, Maping *map, FILE *output_file) {
  int query_type;
  char modifier;
  char *parameters = malloc(sizeof(char) * 100);
  sscanf(line, "%d%c %[^\n]", &query_type, &modifier, parameters);

  bool has_f = (modifier == 'F');

  char **query_parameters = NULL;
  int num_parameters = 0;
  char *parameters_copy = parameters;

  char *token = strsep(&parameters_copy, " ");
  while (token != NULL) {
    query_parameters =
        realloc(query_parameters, (num_parameters + 1) * sizeof(char *));
    query_parameters[num_parameters] = malloc(strlen(token) + 1);
    strcpy(query_parameters[num_parameters], token);
    num_parameters++;
    token = strsep(&parameters_copy, " ");
  }
  free(parameters_copy);
  free(parameters);

  switch (query_type) {
    case 1:
      query1(has_f, query_parameters, flights_data, reservations_data,
             users_data, map, output_file);
      break;
    case 2:
      query2(has_f, query_parameters, flights_data, reservations_data,
             users_data, output_file, num_parameters);
      break;
    case 3:
      query3(has_f, query_parameters, reservations_data, output_file);
      break;
    case 4:
      query4(has_f, query_parameters, reservations_data, output_file);
      break;
    case 5:
      query5(has_f, query_parameters, flights_data, map, output_file);
      break;
    case 6:
      query6(has_f, query_parameters, flights_data, output_file);
      break;
    case 7:
      query7(has_f, query_parameters, flights_data, output_file);
      break;
    case 8:
      query8(has_f, query_parameters, reservations_data, output_file);
      break;
    case 9:
      query9(has_f, query_parameters, users_data, users_stats, output_file,
             num_parameters);
      break;
    case 10:
      query10(has_f, query_parameters, num_parameters, general_data,
              output_file);
      break;
    default:
      // This is not supposed to happen
      printf("Error choosing the query\n");
      break;
  }

  for (int i = 0; i < num_parameters; ++i) {
    free(query_parameters[i]);
  }
  free(query_parameters);
}

void write_input(bool has_f, int query_type, int line, double time) {
  if (has_f) {
    if (line == 0) {
      printf(GREEN "Query %dF is correct\n" RESET, query_type);
    } else {
      printf(RED "Query %dF is wrong\n", query_type);
      printf(RED "Diferença na linha %d\n" RESET, line);
    }
  } else {
    if (line == 0) {
      printf(GREEN "Query %d is correct\n" RESET, query_type);
    } else {
      printf(RED "Query %d is wrong\n", query_type);
      printf(RED "Diferença na linha %d\n" RESET, line);
    }
  }
  printf(YELLOW "This Query took %f seconds to execute \n" RESET, time);
}

void query_manager_test(char *line, FlightsData *flights_data,
                        ReservationsData *reservations_data,
                        GeneralData *general_data, UsersData *users_data,
                        StatsUserInfo *users_stats, Maping *map,
                        FILE *output_file, FILE *output_file_expected) {
  int query_type;
  char modifier;
  char *parameters = malloc(sizeof(char) * 100);
  sscanf(line, "%d%c %[^\n]", &query_type, &modifier, parameters);

  bool has_f = (modifier == 'F');

  char **query_parameters = NULL;
  int num_parameters = 0;
  char *parameters_copy = parameters;

  char *token = strsep(&parameters_copy, " ");
  while (token != NULL) {
    query_parameters =
        realloc(query_parameters, (num_parameters + 1) * sizeof(char *));
    query_parameters[num_parameters] = malloc(strlen(token) + 1);
    strcpy(query_parameters[num_parameters], token);
    num_parameters++;
    token = strsep(&parameters_copy, " ");
  }
  free(parameters_copy);
  free(parameters);

  clock_t start_time, end_time;
  double time_taken;
  int lineNum;

  switch (query_type) {
    case 1:
      start_time = clock();
      query1(has_f, query_parameters, flights_data, reservations_data,
             users_data, map, output_file);

      end_time = clock();
      time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

      lineNum = compare_files(output_file, output_file_expected);
      write_input(has_f, query_type, lineNum, time_taken);

      break;
    case 2:
      start_time = clock();

      query2(has_f, query_parameters, flights_data, reservations_data,
             users_data, output_file, num_parameters);
      end_time = clock();
      time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

      lineNum = compare_files(output_file, output_file_expected);
      write_input(has_f, query_type, lineNum, time_taken);
      break;
    case 3:
      start_time = clock();

      query3(has_f, query_parameters, reservations_data, output_file);
      end_time = clock();
      time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

      lineNum = compare_files(output_file, output_file_expected);
      write_input(has_f, query_type, lineNum, time_taken);
      break;

    case 4:
      start_time = clock();

      query4(has_f, query_parameters, reservations_data, output_file);
      end_time = clock();
      time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

      lineNum = compare_files(output_file, output_file_expected);
      write_input(has_f, query_type, lineNum, time_taken);
      break;
    case 5:
      start_time = clock();

      query5(has_f, query_parameters, flights_data, map, output_file);
      end_time = clock();
      time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

      lineNum = compare_files(output_file, output_file_expected);
      write_input(has_f, query_type, lineNum, time_taken);
      break;
    case 6:
      start_time = clock();

      query6(has_f, query_parameters, flights_data, output_file);

      end_time = clock();
      time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

      lineNum = compare_files(output_file, output_file_expected);
      write_input(has_f, query_type, lineNum, time_taken);

      break;
    case 7:
      start_time = clock();

      query7(has_f, query_parameters, flights_data, output_file);

      end_time = clock();
      time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

      lineNum = compare_files(output_file, output_file_expected);
      write_input(has_f, query_type, lineNum, time_taken);

      break;
    case 8:
      start_time = clock();

      query8(has_f, query_parameters, reservations_data, output_file);

      end_time = clock();
      time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

      lineNum = compare_files(output_file, output_file_expected);
      write_input(has_f, query_type, lineNum, time_taken);
      break;
    case 9:
      start_time = clock();

      query9(has_f, query_parameters, users_data, users_stats, output_file,
             num_parameters);
      end_time = clock();
      time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

      lineNum = compare_files(output_file, output_file_expected);
      write_input(has_f, query_type, lineNum, time_taken);
      break;
    case 10:
      start_time = clock();

      query10(has_f, query_parameters, num_parameters, general_data,
              output_file);

      end_time = clock();
      time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

      lineNum = compare_files(output_file, output_file_expected);
      write_input(has_f, query_type, lineNum, time_taken);

      break;
    default:
      // This is not suppose\d to happen
      printf("Error choosing the query\n");
      break;
  }

  for (int i = 0; i < num_parameters; ++i) {
    free(query_parameters[i]);
  }
  free(query_parameters);
}
