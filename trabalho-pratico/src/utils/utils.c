#define _GNU_SOURCE
#include "utils/utils.h"

#include <glib.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* calculate_age(char* birth_date_str) {
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

double calculate_total_price(int num_nights, int price_per_night,
                             int city_tax) {
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

  sscanf(begin_date_str, "%d/%d/%d", &begin_year, &begin_month, &begin_day);
  sscanf(end_date_str, "%d/%d/%d", &end_year, &end_month, &end_day);

  int begin_date = begin_year * 10000 + begin_month * 100 + begin_day;
  int end_date = end_year * 10000 + end_month * 100 + end_day;

  int nights = end_date - begin_date;
  return nights;
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

struct query4_result {
  char** reservation_id;
  char** begin_date;
  char** end_date;
  char** user_id;
  int* rating;
  float* total_price;
  int iterator;
};

void sort_by_date_and_value(void* result, int N) {
  QUERY4_RESULT query_result = (QUERY4_RESULT)result;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (strcmp(query_result->begin_date[i], query_result->begin_date[j]) >
          0) {
        char* temp = query_result->reservation_id[i];
        char* temp1 = query_result->begin_date[i];
        char* temp2 = query_result->end_date[i];
        char* temp3 = query_result->user_id[i];
        int temp4 = query_result->rating[i];
        float temp5 = query_result->total_price[i];

        query_result->reservation_id[i] = query_result->reservation_id[j];
        query_result->begin_date[i] = query_result->begin_date[j];
        query_result->end_date[i] = query_result->end_date[j];
        query_result->user_id[i] = query_result->user_id[j];
        query_result->rating[i] = query_result->rating[j];
        query_result->total_price[i] = query_result->total_price[j];

        query_result->reservation_id[j] = temp;
        query_result->begin_date[j] = temp1;
        query_result->end_date[j] = temp2;
        query_result->user_id[j] = temp3;
        query_result->rating[j] = temp4;
        query_result->total_price[j] = temp5;

      } else if (strcmp(query_result->begin_date[i],
                        query_result->begin_date[j]) == 0) {
        if (strcmp(query_result->reservation_id[i],
                   query_result->reservation_id[j]) < 0) {
          char* temp = query_result->reservation_id[i];
          char* temp1 = query_result->begin_date[i];
          char* temp2 = query_result->end_date[i];
          char* temp3 = query_result->user_id[i];
          int temp4 = query_result->rating[i];
          float temp5 = query_result->total_price[i];

          query_result->reservation_id[i] = query_result->reservation_id[j];
          query_result->begin_date[i] = query_result->begin_date[j];
          query_result->end_date[i] = query_result->end_date[j];
          query_result->user_id[i] = query_result->user_id[j];
          query_result->rating[i] = query_result->rating[j];
          query_result->total_price[i] = query_result->total_price[j];

          query_result->reservation_id[j] = temp;
          query_result->begin_date[j] = temp1;
          query_result->end_date[j] = temp2;
          query_result->user_id[j] = temp3;
          query_result->rating[j] = temp4;
          query_result->total_price[j] = temp5;
        }
      }
    }
  }
}

void sort_by_date(char** flight_ids, char** flight_dates, char** flight_types,
                  int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (strcmp(flight_dates[i], flight_dates[j]) > 0) {
        char* temp = flight_dates[i];
        char* temp2 = flight_ids[i];
        char* temp3 = flight_types[i];
        flight_dates[i] = flight_dates[j];
        flight_dates[j] = temp;
        flight_ids[i] = flight_ids[j];
        flight_ids[j] = temp2;
        flight_types[i] = flight_types[j];
        flight_types[j] = temp3;
      } else if (strcmp(flight_dates[i], flight_dates[j]) == 0) {
        if (strcmp(flight_ids[i], flight_ids[j]) < 0) {
          char* temp = flight_dates[i];
          char* temp2 = flight_ids[i];
          char* temp3 = flight_types[i];
          flight_dates[i] = flight_dates[j];
          flight_dates[j] = temp;
          flight_ids[i] = flight_ids[j];
          flight_ids[j] = temp2;
          flight_types[i] = flight_types[j];
          flight_types[j] = temp3;
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

char* remove_quotation_marks(char* str) {
  char* lineWithoutQuotes = malloc(strlen(str));
  int i, j;
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

char* strcat_with_space(const char* str1, const char* str2) {
  size_t len1 = strlen(str1);
  size_t len2 = strlen(str2);
  size_t total_len = len1 + len2 + 1;  // 1 for the space

  char* result = (char*)malloc(total_len);
  strcpy(result, str1);
  result[len1] = ' ';

  strcpy(result + len1 + 1, str2);

  return result;
}

char* create_prefix(char** parameters, int N) {
  char* prefix = malloc(sizeof(char) * 100);
  prefix = parameters[0];
  for (int i = 1; i < N; i++) {
    if (strcmp(parameters[i], prefix) == 0) break;
    strcat(prefix, " ");
    strcat(prefix, parameters[i]);
  }
  return remove_quotation_marks(prefix);
}

struct user_info {
  char* user_id;
  char* user_name;
};

int compare(const void* a, const void* b) {
  setlocale(LC_COLLATE, "en_US.UTF-8");
  const UserInfoStats* user_a = (const UserInfoStats*)a;
  const UserInfoStats* user_b = (const UserInfoStats*)b;

  int nameComparison = strcoll(user_a->user_name, user_b->user_name);

  if (nameComparison != 0) {
    return nameComparison;
  } else {
    return strcmp(user_a->user_id, user_b->user_id);
  }
}

void sort_by_name_and_id(char** user_ids, char** user_names, int N) {
  UserInfoStats* users = malloc(N * sizeof(UserInfoStats));

  for (int i = 0; i < N; i++) {
    users[i].user_id = user_ids[i];
    users[i].user_name = user_names[i];
  }

  qsort(users, N, sizeof(UserInfoStats), compare);

  for (int i = 0; i < N; i++) {
    user_ids[i] = users[i].user_id;
    user_names[i] = users[i].user_name;
  }

  free(users);
}
