#include "../includes/parser.h"

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isInvalidDateTime(const char* datetime) {
  regex_t regex;
  const char* pattern =
      "^[0-9]{4}/[0-9]{2}/[0-9]{2} [0-9]{2}:[0-9]{2}:[0-9]{2}$";
  if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
    return 1;
  }

  int result = regexec(&regex, datetime, 0, NULL, 0);
  regfree(&regex);
  return result;
}

int isInvalidDate(const char* datetime) {
  regex_t regex;
  printf("%s\n", datetime);
  const char* pattern = "^[0-9]{2}/[0-9]{2}/[0-9]{4}";
  if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
    return 1;
  }

  int result = regexec(&regex, datetime, 0, NULL, 0);
  regfree(&regex);
  return result;
}

Flight* parse_flights(char* filename) {
  FILE* file = fopen(filename, "r");

  if (file == NULL) {
    perror("Error opening file");
    return NULL;
  }

  Flight* flights = NULL;  // Initialize the linked list
  Flight* tail = NULL;     // Pointer to the last Flight

  char line[MAX_FIELD_SIZE * 13];

  if (fgets(line, sizeof(line), file) == NULL) {
    fclose(file);
    return NULL;
  }

  while (fgets(line, sizeof(line), file) != NULL) {
    Flight* flight = (Flight*)malloc(sizeof(Flight));

    if (flight == NULL) {
      perror("Error allocating memory for a new flight");
      fclose(file);
      free_flights(flights);  // Free any allocated memory
      return NULL;
    }

    char* token = strtok(line, ";");

    if (token == NULL) {
      free(flight);
      continue;
    }

    flight->id = atoll(token);
    if (flight->id < 0) {
      free(flight);
      continue;
    }

    strcpy(flight->airline, strtok(NULL, ";"));
    if (!strcmp(flight->airline, "NULL")) {
      free(flight);
      continue;
    }

    strcpy(flight->plane_model, strtok(NULL, ";"));
    if (!strcmp(flight->plane_model, "NULL")) {
      free(flight);
      continue;
    }

    flight->total_seats = atoi(strtok(NULL, ";"));
    if (flight->total_seats < 0) {
      free(flight);
      continue;
    }

    strcpy(flight->origin, strtok(NULL, ";"));
    if (!strcmp(flight->origin, "NULL")) {
      free(flight);
      continue;
    }

    strcpy(flight->destination, strtok(NULL, ";"));
    if (!strcmp(flight->destination, "NULL")) {
      free(flight);
      continue;
    }

    strcpy(flight->schedule_departure_date, strtok(NULL, ";"));
    if (isInvalidDateTime(flight->schedule_departure_date)) {
      free(flight);
      continue;
    }

    strcpy(flight->schedule_arrival_date, strtok(NULL, ";"));
    if (isInvalidDateTime(flight->schedule_arrival_date)) {
      free(flight);
      continue;
    }

    strcpy(flight->real_departure_date, strtok(NULL, ";"));
    if (isInvalidDateTime(flight->real_departure_date)) {
      free(flight);
      continue;
    }

    strcpy(flight->real_arrival_date, strtok(NULL, ";"));
    if (isInvalidDateTime(flight->real_arrival_date)) {
      free(flight);
      continue;
    }

    strcpy(flight->pilot, strtok(NULL, ";"));
    if (!strcmp(flight->pilot, "NULL")) {
      free(flight);
      continue;
    }

    strcpy(flight->copilot, strtok(NULL, ";"));
    if (!strcmp(flight->copilot, "NULL")) {
      free(flight);
      continue;
    }

    strcpy(flight->notes, strtok(NULL, ";"));
    if (!strcmp(flight->notes, "NULL")) {
      free(flight);
      continue;
    }

    flight->next = NULL;

    if (flights == NULL) {
      flights = flight;
      tail = flight;
    } else {
      tail->next = flight;
      tail = flight;
    }
  }

  fclose(file);
  return flights;
}

void free_flights(Flight* flights) {
  while (flights != NULL) {
    Flight* temp = flights;
    flights = flights->next;
    free(temp);
  }
}

Passenger* parse_passengers(char* filename) {
  FILE* file = fopen(filename, "r");

  if (file == NULL) {
    perror("Error opening file");
    return NULL;
  }

  char line[MAX_FIELD_SIZE * 2];
  Passenger* head = NULL;
  Passenger* tail = NULL;  // Pointer to the last Passenger

  while (fgets(line, sizeof(line), file) != NULL) {
    Passenger* passenger = (Passenger*)malloc(sizeof(Passenger));

    if (passenger == NULL) {
      perror("Error allocating memory for a new passenger");
      fclose(file);
      free_passengers(head);  // Free any allocated memory
      return NULL;
    }

    char* token = strtok(line, ";");
    if (token == NULL) {
      free(passenger);
      continue;
    }

    passenger->flight_id = atoll(token);
    if (passenger->flight_id < 0) {
      free(passenger);
      continue;
    }

    token = strtok(NULL, ";");
    if (token == NULL) {
      free(passenger);
      continue;
    }

    passenger->user_id = atoll(token);
    if (passenger->user_id < 0) {
      free(passenger);
      continue;
    }

    passenger->next = NULL;

    if (head == NULL) {
      head = passenger;
      tail = passenger;
    } else {
      tail->next = passenger;
      tail = passenger;
    }
  }

  fclose(file);
  return head;
}

void free_passengers(Passenger* passengers) {
  while (passengers != NULL) {
    Passenger* temp = passengers;
    passengers = passengers->next;
    free(temp);
  }
}

Reservation* parse_reservations(char* filename) {
  FILE* file = fopen(filename, "r");

  if (file == NULL) {
    perror("Error opening file");
    return NULL;
  }

  Reservation* head = NULL;
  Reservation* tail = NULL;

  char line[MAX_FIELD_SIZE * 14];

  if (fgets(line, sizeof(line), file) == NULL) {
    fclose(file);
    return NULL;
  }

  while (fgets(line, sizeof(line), file) != NULL) {
    Reservation* newReservation = (Reservation*)malloc(sizeof(Reservation));

    if (newReservation == NULL) {
      perror("Error allocating memory for a new reservation");
      fclose(file);
      return NULL;
    }

    char* token = strtok(line, ";");

    if (token == NULL) {
      continue;
    }

    newReservation->id = atoll(token);
    if (newReservation->id < 0) {
      continue;
    }

    newReservation->user_id = atoll(strtok(NULL, ";"));
    if (newReservation->user_id < 0) {
      continue;
    }

    newReservation->hotel_id = atoll(strtok(NULL, ";"));
    if (newReservation->hotel_id < 0) {
      continue;
    }

    strcpy(newReservation->hotel_name, strtok(NULL, ";"));
    if (!strcmp(newReservation->hotel_name, "NULL")) {
      continue;
    }

    newReservation->hotel_stars = atoi(strtok(NULL, ";"));
    if (newReservation->hotel_stars < 1) {
      continue;
    }

    newReservation->city_tax = atof(strtok(NULL, ";"));
    if (newReservation->city_tax < 0) {
      continue;
    }

    strcpy(newReservation->address, strtok(NULL, ";"));
    if (!strcmp(newReservation->address, "NULL")) {
      continue;
    }

    strcpy(newReservation->begin_date, strtok(NULL, ";"));
    if (isInvalidDateTime(newReservation->begin_date)) {
      continue;
    }

    strcpy(newReservation->end_date, strtok(NULL, ";"));
    if (isInvalidDateTime(newReservation->end_date)) {
      continue;
    }

    newReservation->price_per_night = atof(strtok(NULL, ";"));
    if (newReservation->price_per_night < 0) {
      continue;
    }

    newReservation->includes_breakfast = atoi(strtok(NULL, ";"));
    if (newReservation->includes_breakfast < 0) {
      continue;
    }

    strcpy(newReservation->room_details, strtok(NULL, ";"));
    if (!strcmp(newReservation->room_details, "NULL")) {
      continue;
    }

    newReservation->rating = atof(strtok(NULL, ";"));
    if (newReservation->rating < 1 || newReservation->rating > 5) {
      continue;
    }

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
    User* user = (User*)malloc(sizeof(User));

    if (user == NULL) {
      perror("Error allocating memory for a new user");
      fclose(file);
      free_users(users);
      return NULL;
    }

    char* token = strtok(line, ";");

    if (token == NULL) {
      free(user);
      continue;
    }

    user->id = atoll(token);
    if (user->id < 0) {
      free(user);
      continue;
    }

    strcpy(user->name, strtok(NULL, ";"));
    if (!strcmp(user->name, "NULL")) {
      free(user);
      continue;
    }

    strcpy(user->email, strtok(NULL, ";"));
    if (!strcmp(user->email, "NULL")) {
      free(user);
      continue;
    }

    strcpy(user->phone_number, strtok(NULL, ";"));
    if (!strcmp(user->phone_number, "NULL")) {
      free(user);
      continue;
    }

    strcpy(user->birth_date, strtok(NULL, ";"));
    if (isInvalidDate(user->birth_date)) {
      printf("Invalid date\n");
      free(user);
      continue;
    }

    printf("Birth date: %s\n", user->birth_date);
    strcpy(user->sex, strtok(NULL, ";"));
    if (!strcmp(user->sex, "NULL")) {
      free(user);
      continue;
    }

    printf("Sex: %s\n", user->sex);
    strcpy(user->passport, strtok(NULL, ";"));
    if (!strcmp(user->passport, "NULL")) {
      free(user);
      continue;
    }

    printf("Passport: %s\n", user->passport);

    strcpy(user->country_code, strtok(NULL, ";"));
    if (!strcmp(user->country_code, "NULL")) {
      free(user);
      continue;
    }

    strcpy(user->address, strtok(NULL, ";"));
    if (!strcmp(user->address, "NULL")) {
      free(user);
      continue;
    }

    strcpy(user->account_creation, strtok(NULL, ";"));
    if (isInvalidDateTime(user->account_creation)) {
      free(user);
      continue;
    }

    strcpy(user->pay_method, strtok(NULL, ";"));
    if (!strcmp(user->pay_method, "NULL")) {
      free(user);
      continue;
    }

    strcpy(user->account_status, strtok(NULL, ";"));
    if (!strcmp(user->account_status, "NULL")) {
      free(user);
      continue;
    }

    user->next = NULL;
    printf("User: %s\n", user->name);
    if (users == NULL) {
      users = user;
      tail = user;
    } else {
      tail->next = user;
      tail = user;
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