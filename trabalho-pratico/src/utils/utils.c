#define _GNU_SOURCE
#include "utils/utils.h"

#include <ctype.h>
#include <dirent.h>
#include <glib.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_input_file(const char* path) {
  size_t len = strlen(path);

  if (len < 9) {
    return 0;
  }

  if (strcmp(path + len - 9, "input.txt") == 0) {
    return 1;
  } else {
    return 0;
  }
}

char* concatenate_strings(const char* str1, const char* str2) {
  size_t size_str1 = strlen(str1);
  size_t size_str2 = strlen(str2);
  size_t total_size = size_str1 + size_str2 + 1;

  char* result = (char*)malloc(total_size);

  if (result == NULL) {
    printf("Memory allocation error!\n");
    return NULL;
  }

  strcpy(result, str1);
  strcat(result, str2);

  return result;
}

int check_dataset_path(const char* path) {
  DIR* directory;
  struct dirent* file;

  directory = opendir(path);

  if (directory) {
    int users = 0, flights = 0, passengers = 0, reservations = 0;

    while ((file = readdir(directory)) != NULL) {
      if (strcmp(file->d_name, "users.csv") == 0) {
        users = 1;
      } else if (strcmp(file->d_name, "flights.csv") == 0) {
        flights = 1;
      } else if (strcmp(file->d_name, "passengers.csv") == 0) {
        passengers = 1;
      } else if (strcmp(file->d_name, "reservations.csv") == 0) {
        reservations = 1;
      }
    }

    closedir(directory);

    if (users && flights && passengers && reservations) {
      return 1;
    }
  }

  return 0;
}

int calculate_age(int birth_date) {
  int birth_date_year, birth_date_month, birth_date_day;
  int master_date_year, master_date_month, master_date_day;

  birth_date_year = birth_date / 10000;
  birth_date_month = (birth_date % 10000) / 100;
  birth_date_day = birth_date % 100;

  sscanf(MASTER_DATE, "%d/%d/%d", &master_date_year, &master_date_month,
         &master_date_day);

  int age = master_date_year - birth_date_year;

  if (master_date_month < birth_date_month ||
      (master_date_month == birth_date_month &&
       master_date_day < birth_date_day)) {
    age--;
  }

  return age;
}

double calculate_total_price(int num_nights, int price_per_night,
                             char city_tax) {
  double total_price =
      num_nights * price_per_night +
      ((double)(num_nights * price_per_night) / 100) * city_tax;

  return total_price;
}

int calculate_number_of_nights(const char* begin_date_str,
                               const char* end_date_str) {
  if (strcmp(begin_date_str, end_date_str) == 0) return 1;
  int begin_year, begin_month, begin_day;
  int end_year, end_month, end_day;
  if (begin_date_str != NULL && strcmp(begin_date_str, end_date_str) == 0)
    return 1;

  sscanf(begin_date_str, "%d/%d/%d", &begin_year, &begin_month, &begin_day);
  sscanf(end_date_str, "%d/%d/%d", &end_year, &end_month, &end_day);

  int begin_date = begin_year * 10000 + begin_month * 100 + begin_day;
  int end_date = end_year * 10000 + end_month * 100 + end_day;

  int nights = end_date - begin_date;
  return nights;
}

int is_day_next(const char* begin_date_str, const char* end_date_str) {
  int begin_year, begin_month, begin_day;
  int end_year, end_month, end_day;

  sscanf(begin_date_str, "%d/%d/%d", &begin_year, &begin_month, &begin_day);
  sscanf(end_date_str, "%d/%d/%d", &end_year, &end_month, &end_day);

  int begin_date = begin_year * 10000 + begin_month * 100 + begin_day;
  int end_date = end_year * 10000 + end_month * 100 + end_day;

  if (end_date - begin_date == 1 || end_date - begin_date == 2) return 1;
  return 0;
}

int calculate_delay(char* scheduled_date, char* actual_date) {
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

char* format_date(int year, int month, int day) {
  char* new_date = malloc(38 * sizeof(char));
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

char* remove_quotation_marks(char* str) {
  static char lineWithoutQuotes[100];
  int j;
  size_t i;
  for (i = j = 0; i < strlen(str); i++) {
    if (str[i] == '"') {
      if (i == strlen(str) - 1)
        break;
      else
        i++;
    }
    lineWithoutQuotes[j] = str[i];
    j++;
  }
  lineWithoutQuotes[j] = '\0';
  return lineWithoutQuotes;
}

char* create_prefix(char** paramenters, int N) {
  if (paramenters[1] != NULL) {
    for (int i = 1; i < N; i++) {
      strcat(paramenters[0], " ");
      strcat(paramenters[0], paramenters[i]);
    }
    return remove_quotation_marks(paramenters[0]);
  } else {
    return remove_quotation_marks(paramenters[0]);
  }
}

char* concatenate_and_modify_strings(char* str1, char* str2) {
  size_t size = strlen(str1) + strlen(str2) + 2;

  char* result = (char*)malloc(size * sizeof(char));
  if (result == NULL) {
    printf("Erro ao alocar memória.\n");
    return NULL;
  }

  strcpy(result, str1);
  strcat(result, " ");
  strcat(result, str2);

  result[strlen(result) - 1] = '\0';
  memmove(result, result + 1, strlen(result));

  return result;
}

void normalize_string_to_upper(char* string) {
  int i = 0;
  while (string[i]) {
    string[i] = toupper(string[i]);
    i++;
  }
}

bool normalize_includes_breakfast(char* includes_breakfast) {
  for (int i = 0; includes_breakfast[i]; i++) {
    if (isalpha(includes_breakfast[i])) {
      includes_breakfast[i] = tolower(includes_breakfast[i]);
    }
  }

  if ((strcmp(includes_breakfast, "t") == 0) ||
      (strcmp(includes_breakfast, "true") == 0) ||
      (strcmp(includes_breakfast, "1") == 0)) {
    return true;
  }
  return false;
}

int normalize_hotel_id(char* hotel_id) {
  int hotel_id_int;
  sscanf(hotel_id, "HTL%d", &hotel_id_int);
  return hotel_id_int;
}

int normalize_date(char* date) {
  int year, month, day;
  sscanf(date, "%d/%d/%d", &year, &month, &day);
  int new_date = year * 10000 + month * 100 + day;
  return new_date;
}

int normalize_date_month(char* date) {
  int year, month, day;
  sscanf(date, "%d/%d/%d", &year, &month, &day);
  int new_date = year * 10000 + month * 100;
  return new_date;
}

int normalize_date_year(char* date) {
  int year, month, day;
  sscanf(date, "%d/%d/%d", &year, &month, &day);
  int new_date = year * 10000;
  return new_date;
}

int normalize_date_with_day(char* date) {
  int year, month, day, hour, minute, second;
  sscanf(date, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute,
         &second);
  int new_date = year * 10000 + month * 100 + day;
  return new_date;
}

int normalize_date_with_month(char* date) {
  int year, month, day, hour, minute, second;
  sscanf(date, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute,
         &second);
  int new_date = year * 10000 + month * 100;
  return new_date;
}

int normalize_date_with_year(char* date) {
  int year, month, day, hour, minute, second;
  sscanf(date, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute,
         &second);
  int new_date = year * 10000;
  return new_date;
}

char* date_to_string(int date) {
  int year = date / 10000;
  int month = (date % 10000) / 100;
  int day = date % 100;
  return format_date(year, month, day);
}

int normalize_reservation_id(char* reservation_id) {
  int reservation_id_int = 0;
  sscanf(reservation_id, "Book%d", &reservation_id_int);
  return reservation_id_int;
}

char* int_to_reservation_id(int reservation_id) {
  char* reservation_id_str = malloc(sizeof(char) * 16);
  sprintf(reservation_id_str, "Book%0*d", 10, reservation_id);

  return reservation_id_str;
}

int count_digits(int n) {
  int counter = 0;
  while (n > 0) {
    counter = counter + 1;
    n = n / 10;
  }
  return counter;
}

gint ascending_order(gconstpointer a, gconstpointer b) {
  int int_a = *(const int*)a;
  int int_b = *(const int*)b;

  if (int_a < int_b) return -1;
  if (int_a > int_b) return 1;

  return 0;
}

char* int_to_flight_id(int flight_id, int num_digits) {
  char* flight_id_str = malloc(num_digits + 1 + 10);
  sprintf(flight_id_str, "%0*d", 10, flight_id);

  return flight_id_str;
}

int calculate_number_unique_passengers(GList* users_list, UsersData* users_data,
                                       FlightsData* flights_data, char* date,
                                       int chars_to_compare) {
  int number_of_unique_passengers = 0;
  while (users_list != NULL) {
    UserStats* user_stats =
        get_user_stats_by_user_id(users_data, users_list->data);

    GArray* flights = get_user_flights_from_user_stats(user_stats);
    if (flights != NULL) {
      for (guint i = 0; i < flights->len; i++) {
        int flight = g_array_index(flights, int, i);
        FlightInfo* flight_info = get_flight_by_flight_id(flights_data, flight);
        char* schedule_departure_date =
            get_schedule_departure_date(flight_info);
        if (strncmp(date, schedule_departure_date, chars_to_compare) == 0) {
          number_of_unique_passengers++;
          free(schedule_departure_date);
          break;
        }
        free(schedule_departure_date);
      }
    }
    users_list = users_list->next;
  }
  return number_of_unique_passengers;
}

int remove_duplicates(GArray* data) {
  int count = 0;
  for (guint i = 0; i < data->len; i++) {
    char* current_str = g_array_index(data, char*, i);
    gboolean found = FALSE;
    for (guint j = i + 1; j < data->len; j++) {
      char* existing_str = g_array_index(data, char*, j);
      if (strcmp(current_str, existing_str) == 0) {
        found = TRUE;
        break;
      }
    }
    if (!found) count++;
  }
  return count;
}

int compare_files(FILE* fp1, FILE* fp2, char* error_line, char* correct_line) {
  char line1[16384], line2[16384];
  int lineNum = 0;

  while (fgets(line1, sizeof(line1), fp1) != NULL &&
         fgets(line2, sizeof(line2), fp2) != NULL) {
    lineNum++;

    line1[strcspn(line1, "\n")] = '\0';
    line2[strcspn(line2, "\n")] = '\0';

    if (strcmp(line1, line2) != 0 || strlen(line1) != strlen(line2)) {
      strcpy(error_line, line1);
      strcpy(correct_line, line2);
      return lineNum;
    }
  }

  if (strcmp(line1, line2) != 0) {
    return lineNum;
  }
  return 0;
}