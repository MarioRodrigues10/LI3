#include "../includes/parser.h"

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isLineValid(char* line, char* pattern) {
  regex_t regex;
  if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
    fprintf(stderr, "Failed to compile regex\n");
    return 1;
  }

  int result = regexec(&regex, line, 0, NULL, 0);
  printf("%d\n", result);
  regfree(&regex);
  return result;
}

Flight* parse_flights(char* filename) {
  FILE* file = fopen(filename, "r");

  Flight* flights = NULL;
  Flight* tail = NULL;

  char line[MAX_FIELD_SIZE * 13];

  while (fgets(line, sizeof(line), file) != NULL) {
    if (!isLineValid(
            line,
            "^[0-9]+;[A-Za-z0-9.]+;[A-Za-z0-9 "
            "]+;[0-9]+;[A-Z]+;[A-Z]+;[0-9]{4}/[0-9]{2}/[0-9]{2} "
            "[0-9]{2}:[0-9]{2}:[0-9]{2};[0-9]{4}/[0-9]{2}/[0-9]{2} "
            "[0-9]{2}:[0-9]{2}:[0-9]{2};[0-9]{4}/[0-9]{2}/[0-9]{2} "
            "[0-9]{2}:[0-9]{2}:[0-9]{2};[0-9]{4}/[0-9]{2}/[0-9]{2} "
            "[0-9]{2}:[0-9]{2}:[0-9]{2};[A-Za-z ]+;[A-Za-z ]+;[^;]*")) {
      Flight* flight = (Flight*)malloc(sizeof(Flight));
      char* token = strtok(line, ";");

      flight->id = atoll(token);
      strcpy(flight->airline, strtok(NULL, ";"));
      strcpy(flight->plane_model, strtok(NULL, ";"));
      flight->total_seats = atoi(strtok(NULL, ";"));
      strcpy(flight->origin, strtok(NULL, ";"));
      strcpy(flight->destination, strtok(NULL, ";"));
      strcpy(flight->schedule_departure_date, strtok(NULL, ";"));
      strcpy(flight->schedule_arrival_date, strtok(NULL, ";"));
      strcpy(flight->real_departure_date, strtok(NULL, ";"));
      strcpy(flight->real_arrival_date, strtok(NULL, ";"));
      strcpy(flight->pilot, strtok(NULL, ";"));
      strcpy(flight->copilot, strtok(NULL, ";"));
      strcpy(flight->notes, strtok(NULL, ";"));

      flight->next = NULL;

      if (flights == NULL) {
        flights = flight;
        tail = flight;
      } else {
        tail->next = flight;
        tail = flight;
      }
    }
  }

  fclose(file);
  return flights;
}

Passenger* parse_passengers(char* filename) {
  FILE* file = fopen(filename, "r");

  char line[MAX_FIELD_SIZE * 2];
  Passenger* head = NULL;
  Passenger* tail = NULL;
  while (fgets(line, sizeof(line), file) != NULL) {
    if (!isLineValid(line, "^[0-9]+;[A-Za-z0-9]+")) {
      Passenger* passenger = (Passenger*)malloc(sizeof(Passenger));
      char* token = strtok(line, ";");

      passenger->flight_id = atoll(token);
      strcpy(passenger->user_id, strtok(NULL, ";"));

      passenger->next = NULL;

      if (head == NULL) {
        head = passenger;
        tail = passenger;
      } else {
        tail->next = passenger;
        tail = passenger;
      }
    }
  }
  fclose(file);
  return head;
}

Reservation* parse_reservations(char* filename) {
  FILE* file = fopen(filename, "r");

  Reservation* head = NULL;
  Reservation* tail = NULL;

  char line[MAX_FIELD_SIZE * 14];

  if (fgets(line, sizeof(line), file) == NULL) {
    fclose(file);
    return NULL;
  }

  while (fgets(line, sizeof(line), file) != NULL) {
    if (!isLineValid(line,
                     "^[A-Za-z0-9]+;[A-Za-z]+;[A-Za-z0-9]+;[^;]+;[0-9]+;[0-9]+;"
                     "[^;]+;[0-9]{4}/[0-9]{2}/[0-9]{2};[0-9]{4}/[0-9]{2}/"
                     "[0-9]{2};[0-9]+;(true|false);[^;]+;[0-9]+;[^;]+")) {
      Reservation* newReservation = (Reservation*)malloc(sizeof(Reservation));
      strcpy(newReservation->id, strtok(line, ";"));
      printf("ID: %s\n", newReservation->id);
      strcpy(newReservation->user_id, (strtok(NULL, ";")));
      strcpy(newReservation->hotel_id, strtok(NULL, ";"));
      strcpy(newReservation->hotel_name, strtok(NULL, ";"));
      newReservation->hotel_stars = atoi(strtok(NULL, ";"));
      newReservation->city_tax = atof(strtok(NULL, ";"));
      strcpy(newReservation->address, strtok(NULL, ";"));
      strcpy(newReservation->begin_date, strtok(NULL, ";"));
      strcpy(newReservation->end_date, strtok(NULL, ";"));
      newReservation->price_per_night = atof(strtok(NULL, ";"));
      newReservation->includes_breakfast = atoi(strtok(NULL, ";"));
      strcpy(newReservation->room_details, strtok(NULL, ";"));
      newReservation->rating = atof(strtok(NULL, ";"));
      strcpy(newReservation->comment, strtok(NULL, ";"));

      newReservation->next = NULL;

      if (head == NULL) {
        head = newReservation;
        tail = newReservation;
      } else {
        tail->next = newReservation;
        tail = newReservation;
      }
    }
  }

  fclose(file);
  return head;
}

User* parse_users(char* filename) {
  FILE* file = fopen(filename, "r");

  if (file == NULL) {
    perror("Error opening file");
    return NULL;
  }

  User* users = NULL;
  User* tail = NULL;

  char line[MAX_FIELD_SIZE * 13];

  if (fgets(line, sizeof(line), file) == NULL) {
    fclose(file);
    return NULL;
  }

  while (fgets(line, sizeof(line), file) != NULL) {
    printf("%s\n", line);
    if (!isLineValid(line,
                     "^(.+);(.+);([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{"
                     "2,});\\(\\d+\\) "
                     "\\d{3}-\\d{4};\\d{4}/\\d{2}/"
                     "\\d{2};[MF];[A-Z0-9]+;[A-Z]{2};(.+);\\d{4}/\\d{2}/\\d{2} "
                     "\\d{2}:\\d{2}:\\d{2};(debit_card|credit_card|cash);("
                     "active|inactive|Active|Inactive)$")) {
      User* user = (User*)malloc(sizeof(User));
      strcpy(user->id, strtok(line, ";"));
      printf("USER ID: %s\n", user->id);
      strcpy(user->name, strtok(NULL, ";"));
      strcpy(user->email, strtok(NULL, ";"));
      strcpy(user->phone_number, strtok(NULL, ";"));
      strcpy(user->birth_date, strtok(NULL, ";"));
      strcpy(user->sex, strtok(NULL, ";"));
      strcpy(user->passport, strtok(NULL, ";"));
      strcpy(user->country_code, strtok(NULL, ";"));
      strcpy(user->address, strtok(NULL, ";"));
      strcpy(user->account_creation, strtok(NULL, ";"));
      strcpy(user->pay_method, strtok(NULL, ";"));
      strcpy(user->account_status, strtok(NULL, "\0"));

      user->next = NULL;

      if (users == NULL) {
        users = user;
        tail = user;
      } else {
        tail->next = user;
        tail = user;
      }
    }
  }

  fclose(file);
  return users;
}

void free_users(User* users) {
  while (users != NULL) {
    User* temp = users;
    users = users->next;
    free(temp);
  }
}