#include "utils/utils.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* get_error_as_string(ERRORS error) {
  switch (error) {
    case ERR_OPENING_FLIGHTS_FILE:
      return "Error opening flights file!";

    case ERR_OPENING_PASSENGERS_FILE:
      return "Error opening passengers file!";

    case ERR_OPENING_RESERVATIONS_FILE:
      return "Error opening reservations file!";

    case ERR_OPENING_USERS_FILE:
      return "Error opening users file!";

    case ERR_CREATING_DIRECTORY:
      return "Error creating directory!";

    case ERR_OPENING_QUERIES_FILE:
      return "Error opening queries file!";

    case ERR_OPENING_OUTPUT_FILE:
      return "Error opening output file!";

    case ERROR_WRITING_TO_ERRORS_FILE:
      return "Error writing in errors file!";

    default:
      return "Unknown error.";
  }
}

int print_errors_to_file(char* line[], int size_of_line, const char* file_name,
                         int num_lines) {
  FILE* file = fopen(file_name, "a");

  if (file == NULL) {
    return ERROR_WRITING_TO_ERRORS_FILE;
  }

  for (int i = 0; i < size_of_line; i++) {
    fprintf(file, "%s", line[i]);
    if (i < size_of_line - 1) {
      fprintf(file, ";");
    }
  }

  fprintf(file, "\n");

  fclose(file);
  return num_lines++;
}

char* create_filename(char* folder, const char* string) {
  char* filename = malloc(sizeof(char) * (strlen(folder) + strlen(string) + 1));
  strcpy(filename, folder);
  strcat(filename, string);

  return filename;
}

int create_directory(char* folder) {
  int ret = g_mkdir_with_parents(folder, 0777);

  if (ret == -1) {
    return ERR_CREATING_DIRECTORY;
  }

  return 0;
}

FILE* create_output_file(int queries_counter) {
  char* filename = malloc(sizeof(char) * 256);
  sprintf(filename, "Resultados/command%d_output.txt", queries_counter);

  FILE* output_file = fopen(filename, "w");
  free(filename);

  return output_file;
}

char standardize_account_status(char* account_status) {
  if (account_status != NULL) {
    for (int i = 0; account_status[i]; i++) {
      account_status[i] = tolower(account_status[i]);
    }

    if (strcmp(account_status, "active") == 0) {
      return 'a';
    } else if (strcmp(account_status, "inactive") == 0) {
      return 'i';
    }
  }

  return 'x';
}

char stantdardize_includes_breakfast(char* includes_breakfast) {
  if ((strcmp(includes_breakfast, "t") == 0) ||
      (strcmp(includes_breakfast, "true") == 0) ||
      (strcmp(includes_breakfast, "1") == 0))
    return 't';
  else
    return 'f';
}

char* standardize_airport_name(char* airport_name) {
  if (airport_name != NULL) {
    for (int i = 0; airport_name[i]; i++) {
      airport_name[i] = tolower(airport_name[i]);
    }
  }

  return airport_name;
}

bool validate_date_format_without_time(char* date) {
  if (strlen(date) != 10) return false;

  for (int i = 0; i < 10; i++) {
    if (i == 4 || i == 7) {
      if (date[i] != '/') return false;
    } else {
      if (!isdigit(date[i])) return false;
    }
  }

  int year, month, day;
  sscanf(date, "%4d/%2d/%2d", &year, &month, &day);

  if (month < 1 || month > 12 || day < 1 || day > 31) return false;

  return true;
}

bool validate_date_format_with_time(char* date) {
  if (strlen(date) != 19) return false;

  for (int i = 0; i < 19; i++) {
    if (i == 4 || i == 7) {
      if (date[i] != '/') return false;
    } else if (i == 10) {
      if (date[i] != ' ') return false;
    } else if (i == 13 || i == 16) {
      if (date[i] != ':') return false;
    } else {
      if (!isdigit(date[i])) return false;
    }
  }

  int year, month, day, hour, minutes, seconds;
  sscanf(date, "%4d/%2d/%2d %2d:%2d:%2d", &year, &month, &day, &hour, &minutes,
         &seconds);

  if (month < 1 || month > 12 || day < 1 || day > 31 || hour < 0 || hour > 23 ||
      minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59)
    return false;

  return true;
}

bool validate_email(char* email) {
  char* username = strtok(email, "@");
  if (username == NULL || strlen(username) < 1) return false;

  char* domain = strtok(NULL, ".");
  char* tld = strtok(NULL, ".");
  if (domain == NULL || strlen(domain) < 1 || tld == NULL || strlen(tld) < 2)
    return false;

  return true;
}

bool validate_country_code(char* country_code) {
  if (strlen(country_code) != 2) return false;

  for (int i = 0; i < 2; i++) {
    if (!isalpha(country_code[i])) return false;
  }

  return true;
}

bool validate_account_status(char* account_status) {
  for (int i = 0; account_status[i]; i++) {
    account_status[i] = tolower(account_status[i]);
  }

  return (strcmp(account_status, "active") == 0 ||
          strcmp(account_status, "inactive") == 0);
}

bool validate_total_seats(int total_seats, int number_of_passengers) {
  return total_seats >= number_of_passengers;
}

bool validate_airports(char* airport1, char* airport2) {
  if (strlen(airport1) < 3 || strlen(airport2) < 3) return false;

  char airport1_lower[4];
  char airport2_lower[4];

  for (int i = 0; i < 3; i++) {
    airport1_lower[i] = tolower(airport1[i]);
    airport2_lower[i] = tolower(airport2[i]);
  }

  airport1_lower[3] = '\0';
  airport2_lower[3] = '\0';

  return (strcmp(airport1_lower, airport2_lower) == 0);
}

bool validate_number_of_stars(int hotel_stars) {
  return (hotel_stars >= 1 && hotel_stars <= 5);
}

bool validate_city_tax(int city_tax) { return (city_tax >= 0); }

bool validate_price_per_night(int price_per_night) {
  return (price_per_night > 0);
}

bool validate_includes_breakfast(char* includes_breakfast) {
  for (int i = 0; includes_breakfast[i]; i++) {
    includes_breakfast[i] = tolower(includes_breakfast[i]);
  }

  return (strcmp(includes_breakfast, "f") == 0 ||
          strcmp(includes_breakfast, "false") == 0 ||
          strcmp(includes_breakfast, "0") == 0 ||
          strcmp(includes_breakfast, "") == 0);
}

bool validate_rating(int rating) { return (rating >= 1 && rating <= 5); }

bool validate_parameter_not_empty(char* parameter) {
  return (parameter != NULL && strlen(parameter) > 0);
}
