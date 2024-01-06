#include "utils/validation.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool standardize_account_status(char* account_status) {
  if (account_status != NULL) {
    for (int i = 0; account_status[i]; i++) {
      account_status[i] = tolower(account_status[i]);
    }

    if (strcmp(account_status, "active") == 0) {
      return true;
    } else if (strcmp(account_status, "inactive") == 0) {
      return false;
    }
  }

  return false;
}

char* standardize_includes_breakfast(char* includes_breakfast) {
  if (includes_breakfast == NULL) return "FALSE";

  for (int i = 0; includes_breakfast[i]; i++) {
    includes_breakfast[i] = tolower(includes_breakfast[i]);
  }

  if ((strcmp(includes_breakfast, "t") == 0) ||
      (strcmp(includes_breakfast, "true") == 0) ||
      (strcmp(includes_breakfast, "1") == 0))
    return "TRUE";
  else if (strcmp(includes_breakfast, "false") == 0 ||
           strcmp(includes_breakfast, "f") == 0 ||
           strcmp(includes_breakfast, "0") == 0)
    return "FALSE";
  return "ERROR";
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
  char* email_validate = malloc(sizeof(char) * (strlen(email) + 1));
  strcpy(email_validate, email);
  char* username = strtok(email_validate, "@");
  if (username == NULL || strlen(username) < 1) return false;

  char* domain = strtok(NULL, ".");
  char* tld = strtok(NULL, ".");
  if (domain == NULL || strlen(domain) < 1 || tld == NULL || strlen(tld) < 2) {
    free(email_validate);
    return false;
  }
  free(email_validate);
  return true;
}

bool validate_country_code(char* country_code) {
  char* country_code_validation =
      malloc(sizeof(char) * (strlen(country_code) + 1));
  strcpy(country_code_validation, country_code);
  if (strlen(country_code_validation) != 2) {
    free(country_code_validation);
    return false;
  }

  for (int i = 0; i < 2; i++) {
    if (!isalpha(country_code[i])) {
      free(country_code_validation);
      return false;
    }
  }
  free(country_code_validation);
  return true;
}

bool validate_account_status(char* account_status) {
  char* account_status_validate =
      malloc(sizeof(char) * (strlen(account_status) + 1));
  strcpy(account_status_validate, account_status);
  for (int i = 0; account_status[i]; i++) {
    account_status_validate[i] = tolower(account_status[i]);
  }

  if (strcmp(account_status_validate, "active") == 0 ||
      strcmp(account_status_validate, "inactive") == 0) {
    free(account_status_validate);
    return true;
  }
  free(account_status_validate);
  return false;
}

bool validate_total_seats(const char* total_seats) {
  char* total_seats_validate = malloc(sizeof(char) * (strlen(total_seats) + 1));
  strcpy(total_seats_validate, total_seats);
  char* endptr;  // Pointer to the first invalid character in strtol

  // Convert the string to an integer
  long int value = strtol(total_seats, &endptr, 10);

  // Check for conversion errors
  if (*endptr != '\0' || total_seats == endptr || value < 0) {
    // Not a valid integer or empty string
    free(total_seats_validate);
    return false;
  }

  free(total_seats_validate);
  return true;
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

bool validate_number_of_stars(char* hotel_stars) {
  char* endptr;
  long hotel_stars_value = strtol(hotel_stars, &endptr, 10);

  if (*endptr == '\0' && hotel_stars_value >= 1 && hotel_stars_value <= 5) {
    return true;
  }

  return false;
}

bool validate_city_tax(char* city_tax) {
  char* city_tax_validate = malloc(sizeof(char) * (strlen(city_tax) + 1));
  strcpy(city_tax_validate, city_tax);
  char* endptr;
  long tax_value = strtol(city_tax_validate, &endptr, 10);

  if (*endptr == '\0' && tax_value >= 0) {
    free(city_tax_validate);
    return true;
  }
  free(city_tax_validate);
  return false;
}

bool validate_price_per_night(int price_per_night) {
  return (price_per_night > 0);
}

bool validate_includes_breakfast(char* includes_breakfast) {
  char* includes_breakfast_validate =
      malloc(sizeof(char) * (strlen(includes_breakfast) + 1));
  strcpy(includes_breakfast_validate, includes_breakfast);
  if (strlen(includes_breakfast_validate) == 0) {
    free(includes_breakfast_validate);
    return true;
  }
  for (int i = 0; includes_breakfast_validate[i]; i++) {
    includes_breakfast_validate[i] = tolower(includes_breakfast_validate[i]);
  }

  if ((strcmp(includes_breakfast_validate, "t") == 0) ||
      (strcmp(includes_breakfast_validate, "true") == 0) ||
      (strcmp(includes_breakfast_validate, "1") == 0)) {
    free(includes_breakfast_validate);
    return true;
  } else if (strcmp(includes_breakfast_validate, "false") == 0 ||
             strcmp(includes_breakfast_validate, "f") == 0 ||
             strcmp(includes_breakfast_validate, "0") == 0) {
    free(includes_breakfast_validate);
    return true;
  }
  free(includes_breakfast_validate);
  return false;
}

bool validate_rating(char* rating) {
  char* rating_validate = malloc(sizeof(char) * (strlen(rating) + 1));
  strcpy(rating_validate, rating);
  char* endptr;
  double rating_value = strtod(rating, &endptr);

  if (*endptr == '\0' && rating_value >= 1 && rating_value <= 5) {
    free(rating_validate);
    return true;
  }
  free(rating_validate);
  return false;
}

bool validate_parameter_not_empty(char* parameter) {
  return (parameter != NULL && strlen(parameter) > 0);
}

int compare_dates(char* date1, char* date2) {
  int year1, month1, day1, hour1, minute1, second1;
  int year2, month2, day2, hour2, minute2, second2;

  // Parse the first date
  sscanf(date1, "%d/%d/%d %d:%d:%d", &year1, &month1, &day1, &hour1, &minute1,
         &second1);

  // Parse the second date
  sscanf(date2, "%d/%d/%d %d:%d:%d", &year2, &month2, &day2, &hour2, &minute2,
         &second2);

  // Compare years
  if (year1 < year2) {
    return -1;
  } else if (year1 > year2) {
    return 1;
  }

  // Compare months
  if (month1 < month2) {
    return -1;
  } else if (month1 > month2) {
    return 1;
  }

  // Compare days
  if (day1 < day2) {
    return -1;
  } else if (day1 > day2) {
    return 1;
  }

  // Compare hours
  if (hour1 < hour2) {
    return -1;
  } else if (hour1 > hour2) {
    return 1;
  }

  // Compare minutes
  if (minute1 < minute2) {
    return -1;
  } else if (minute1 > minute2) {
    return 1;
  }

  // Compare seconds
  if (second1 < second2) {
    return -1;
  } else if (second1 > second2) {
    return 1;
  }

  return 0;
}