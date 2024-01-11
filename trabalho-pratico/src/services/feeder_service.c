#include "services/feeder_service.h"

#include <stdio.h>
#include <stdlib.h>

// FILES

char* create_filename(const char* data_folder, const char* name) {
  int len1 = 0, len2 = 0;

  while (data_folder[len1] != '\0') {
    len1++;
  }
  while (name[len2] != '\0') {
    len2++;
  }

  char* filename = (char*)malloc((len1 + len2 + 1) * sizeof(char));

  if (filename == NULL) {
    printf("Memory allocation error");
  }

  int i, j;

  for (i = 0; i < len1; i++) {
    filename[i] = data_folder[i];
  }

  for (j = 0; j < len2; j++) {
    filename[i + j] = name[j];
  }

  filename[i + j] = '\0';

  return filename;
}

void free_filename(char* filename) { free(filename); }

FILE** open_csv_files_read(char* filenames[], int num_files) {
  FILE** files = malloc(num_files * sizeof(FILE*));

  if (files == NULL) {
    printf("Memory allocation error");
  }

  for (int i = 0; i < num_files; ++i) {
    files[i] = fopen(filenames[i], "r");
    if (files[i] == NULL) {
      printf("Error opening file %s\n", filenames[i]);
    }
  }

  return files;
}

FILE** open_csv_files_write(char* filenames[], int num_files) {
  FILE** files = malloc(num_files * sizeof(FILE*));

  if (files == NULL) {
    printf("Memory allocation error");
  }

  for (int i = 0; i < num_files; ++i) {
    files[i] = fopen(filenames[i], "w");
    if (files[i] == NULL) {
      printf("Error opening file %s\n", filenames[i]);
    }
  }

  return files;
}

void close_csv_files(FILE** files, int num_files) {
  for (int i = 0; i < num_files; ++i) {
    fclose(files[i]);
  }

  free(files);
}

// FEEDER

#include <ncurses.h>

void feeder(char* data_folder, FlightsData* flights_data,
            GeneralData* general_data, ReservationsData* reservations_data,
            UsersData* users_data, StatsUserInfo* users_stats) {
  // Create filenames
  char* flights_filename = create_filename(data_folder, FLIGHTS_FILENAME);
  char* passengers_filename = create_filename(data_folder, PASSENGERS_FILENAME);
  char* reservations_filename =
      create_filename(data_folder, RESERVATIONS_FILENAME);
  char* users_filename = create_filename(data_folder, USERS_FILENAME);

  if (flights_filename == NULL || passengers_filename == NULL ||
      reservations_filename == NULL || users_filename == NULL) {
    printf("Error creating filenames\n");
  }

  // Open files
  FILE** files =
      open_csv_files_read((char*[]){flights_filename, passengers_filename,
                                    reservations_filename, users_filename},
                          NUM_FILES);

  char* users_errors_filename = "Resultados/users_errors.csv";
  char* flights_errors_filename = "Resultados/flights_errors.csv";
  char* reservations_errors_filename = "Resultados/reservations_errors.csv";
  char* passengers_errors_filename = "Resultados/passengers_errors.csv";

  if (flights_errors_filename == NULL || passengers_errors_filename == NULL ||
      reservations_errors_filename == NULL || users_errors_filename == NULL) {
    printf("Error creating filenames!\n");
    return;
  }

  FILE* users_errors_file = fopen(users_errors_filename, "w");
  FILE* flights_errors_file = fopen(flights_errors_filename, "w");
  FILE* reservations_errors_file = fopen(reservations_errors_filename, "w");
  FILE* passengers_errors_file = fopen(passengers_errors_filename, "w");

  if (users_errors_file == NULL || flights_errors_file == NULL ||
      reservations_errors_file == NULL || passengers_errors_file == NULL) {
    printf("Error opening files!\n");
    return;
  }

  fprintf(flights_errors_file,
          "id;airline;plane_model;total_seats;origin;destination;schedule_"
          "departure_date;schedule_arrival_date;real_departure_date;real_"
          "arrival_date;pilot;copilot;notes\n");
  fprintf(users_errors_file,
          "id;name;email;phone_number;birth_date;sex;passport;country_code;"
          "address;account_creation;pay_method;account_status\n");
  fprintf(reservations_errors_file,
          "id;user_id;hotel_id;hotel_name;hotel_stars;city_tax;address;begin_"
          "date;end_date;price_per_night;includes_breakfast;room_details;"
          "rating;comment\n");
  fprintf(passengers_errors_file, "flight_id;user_id\n");

  // Parse files
  parse_file(files[0], flights_errors_file, flights_data, general_data,
             reservations_data, users_data, users_stats, 0);
  parse_file(files[3], users_errors_file, flights_data, general_data,
             reservations_data, users_data, users_stats, 3);
  parse_file(files[2], reservations_errors_file, flights_data, general_data,
             reservations_data, users_data, users_stats, 2);
  parse_file(files[1], passengers_errors_file, flights_data, general_data,
             reservations_data, users_data, users_stats, 1);

  // Close files
  close_csv_files(files, NUM_FILES);
  fclose(flights_errors_file);
  fclose(users_errors_file);
  fclose(reservations_errors_file);
  fclose(passengers_errors_file);

  // Free filenames
  free_filename(flights_filename);
  free_filename(passengers_filename);
  free_filename(reservations_filename);
  free_filename(users_filename);
}
