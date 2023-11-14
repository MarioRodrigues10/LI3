#include "utils/utils.h"

#include <ctype.h>
#include <glib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculate_delay(char* scheduled_date, char* actual_date) {
  static char result[20];

  int scheduled_year, scheduled_month, scheduled_day, scheduled_hour,
      scheduled_minute, scheduled_second;
  int actual_year, actual_month, actual_day, actual_hour, actual_minute,
      actual_second;

  sscanf(scheduled_date, "%d/%d/%d %d:%d:%d", &scheduled_year, &scheduled_month,
         &scheduled_day, &scheduled_hour, &scheduled_minute, &scheduled_second);
  sscanf(actual_date, "%d/%d/%d %d:%d:%d", &actual_year, &actual_month,
         &actual_day, &actual_hour, &actual_minute, &actual_second);

  int time_difference_seconds =
      ((actual_year - scheduled_year) * 365 * 24 * 60 * 60) +
      ((actual_month - scheduled_month) * 30 * 24 * 60 * 60) +
      ((actual_day - scheduled_day) * 24 * 60 * 60) +
      ((actual_hour - scheduled_hour) * 60 * 60) +
      ((actual_minute - scheduled_minute) * 60) +
      (actual_second - scheduled_second);

  return time_difference_seconds;
}

double calculate_total_price(int num_nights, int price_per_night,
                             int city_tax) {
  double total_price =
      num_nights * price_per_night +
      ((double)(num_nights * price_per_night) / 100) * city_tax;

  return total_price;
}

int calculate_number_of_nights(const char* begin_date_str,
                               const char* end_date_str) {
  int begin_year, begin_month, begin_day;
  int end_year, end_month, end_day;

  sscanf(begin_date_str, "%d/%d/%d", &begin_year, &begin_month, &begin_day);
  sscanf(end_date_str, "%d/%d/%d", &end_year, &end_month, &end_day);

  int begin_date = begin_year * 10000 + begin_month * 100 + begin_day;
  int end_date = end_year * 10000 + end_month * 100 + end_day;

  int nights = end_date - begin_date;

  return nights;
}

char* calculate_age(const char* birth_date_str) {
  static char result[3];

  int birth_date_year, birth_date_month, birth_date_day;
  int master_date_year, master_date_month, master_date_day;

  sscanf(birth_date_str, "%d/%d/%d", &birth_date_year, &birth_date_month,
         &birth_date_day);
  sscanf(MASTER_DATE, "%d/%d/%d", &master_date_year, &master_date_month,
         &master_date_day);

  int age = master_date_year - birth_date_year;

  if (master_date_month < birth_date_month ||
      (master_date_month == birth_date_month &&
       master_date_day < birth_date_day)) {
    age--;
  }

  sprintf(result, "%d", age);

  return result;
}

int extract_number(char* input) {
  while (*input && !isdigit(*input)) input++;
  return strtol(input, NULL, 10);
}

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

char* standardize_account_status(char* account_status) {
  if (account_status != NULL) {
    for (int i = 0; account_status[i]; i++) {
      account_status[i] = tolower(account_status[i]);
    }

    if (strcmp(account_status, "active") == 0) {
      return "ACTIVE";
    } else if (strcmp(account_status, "inactive") == 0) {
      return "INACTIVE";
    }
  }

  return "NO STATUS";
}

char* standardize_includes_breakfast(char* includes_breakfast) {
  if ((strcmp(includes_breakfast, "t") == 0) ||
      (strcmp(includes_breakfast, "true") == 0) ||
      (strcmp(includes_breakfast, "1") == 0))
    return "TRUE";
  else
    return "FALSE";
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

int setup_catalogs_and_stats(char* folder, FLIGHTS_CATALOG flights_catalog,
                             PASSENGERS_CATALOG passengers_catalog,
                             RESERVATIONS_CATALOG reservations_catalog,
                             USERS_CATALOG users_catalog, STATS stats) {
  char* flights_filename = create_filename(folder, "/flights.csv");
  char* passengers_filename = create_filename(folder, "/passengers.csv");
  char* reservations_filename = create_filename(folder, "/reservations.csv");
  char* users_filename = create_filename(folder, "/users.csv");

  if (flights_filename == NULL || passengers_filename == NULL ||
      reservations_filename == NULL || users_filename == NULL) {
    printf("Error creating filenames!\n");
    return -1;
  }

  FILE* flights_file = fopen(flights_filename, "r");
  FILE* passengers_file = fopen(passengers_filename, "r");
  FILE* reservations_file = fopen(reservations_filename, "r");
  FILE* users_file = fopen(users_filename, "r");

  if (flights_file == NULL || passengers_file == NULL ||
      reservations_file == NULL || users_file == NULL) {
    printf("Error opening files!\n");
    return -1;
  }

  parse_file(flights_file, flights_catalog, build_flight, stats,
             MAX_TOKENS_FLIGHT);
  parse_file(reservations_file, reservations_catalog, build_reservation, stats,
             MAX_TOKENS_RESERVATION);
  parse_file(users_file, users_catalog, build_user, stats, MAX_TOKENS_USER);
  parse_file(passengers_file, passengers_catalog, build_passenger, stats,
             MAX_TOKENS_PASSENGER);

  free(flights_filename);
  free(passengers_filename);
  free(reservations_filename);
  free(users_filename);
  return 0;
}

struct query2_result {
  char** id;
  char** date;
  char** type;
  int iterator;
  bool has_f;
};

void sort_by_date(void* result, int N) {
  QUERY2_RESULT query_result = (QUERY2_RESULT)result;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (strcmp(query_result->date[i], query_result->date[j]) > 0) {
        char* temp = query_result->date[i];
        char* temp2 = query_result->id[i];
        char* temp3 = query_result->type[i];
        query_result->date[i] = query_result->date[j];
        query_result->date[j] = temp;
        query_result->id[i] = query_result->id[j];
        query_result->id[j] = temp2;
        query_result->type[i] = query_result->type[j];
        query_result->type[j] = temp3;
      } else if (strcmp(query_result->date[i], query_result->date[j]) == 0) {
        if (strcmp(query_result->id[i], query_result->id[j]) < 0) {
          char* temp = query_result->date[i];
          char* temp2 = query_result->id[i];
          char* temp3 = query_result->type[i];
          query_result->date[i] = query_result->date[j];
          query_result->date[j] = temp;
          query_result->id[i] = query_result->id[j];
          query_result->id[j] = temp2;
          query_result->type[i] = query_result->type[j];
          query_result->type[j] = temp3;
        }
      }
    }
  }
}

char* format_date(int year, int month, int day) {
  char* new_date = malloc(sizeof(char) * 11);
  if (day < 10 && month < 10) {
    sprintf(new_date, "%d/0%d/0%d", year, month, day);
  } else if (day < 10) {
    sprintf(new_date, "%d/%d/0%d", year, month, day);
  } else if (month < 10) {
    sprintf(new_date, "%d/0%d/%d", year, month, day);
  } else {
    sprintf(new_date, "%d/%d/%d", year, month, day);
  }

  return new_date;
}