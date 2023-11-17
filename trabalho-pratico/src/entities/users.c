#include "entities/users.h"

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/utils.h"

struct user {
  char *id;
  char *name;
  char *email;
  char *phone_number;
  char *birth_date;
  char *sex;
  char *passport;
  char *country_code;
  char *address;
  char *account_creation;
  char *pay_method;
  char *account_status;
};

int verify_user_input(char **parameters) {
  if (!validate_parameter_not_empty(parameters[0])) return 0;

  if (!validate_parameter_not_empty(parameters[1])) return 0;

  if (!validate_parameter_not_empty(parameters[2]) ||
      !validate_email(parameters[2]))
    return 0;
  if (!validate_parameter_not_empty(parameters[3])) return 0;

  if (!validate_parameter_not_empty(parameters[4]) ||
      !validate_date_format_without_time(parameters[4]))
    return 0;
  if (!validate_parameter_not_empty(parameters[5])) return 0;
  if (!validate_parameter_not_empty(parameters[6])) return 0;
  if (!validate_parameter_not_empty(parameters[7]) ||
      !validate_country_code(parameters[7]))
    return 0;
  if (!validate_parameter_not_empty(parameters[8])) return 0;
  if (!validate_parameter_not_empty(parameters[9]) ||
      !validate_date_format_with_time(parameters[9]))
    return 0;
  if (!validate_parameter_not_empty(parameters[10])) return 0;
  if (!validate_parameter_not_empty(parameters[11]) ||
      !validate_account_status(parameters[11]))
    return 0;

  return 1;
}

USER create_user() {
  USER new_user = malloc(sizeof(struct user));
  new_user->id = NULL;

  return new_user;
}

void build_user(char **user_params, void *catalog, STATS stats,
                FILE *errors_file) {
  if (!verify_user_input(user_params)) {
    int i;
    for (i = 0; i < MAX_TOKENS_USER - 1; i++) {
      if (user_params[i] == NULL) {
        fprintf(errors_file, ";");
      }
      fprintf(errors_file, "%s;", user_params[i]);
    }
    if (user_params[i] != NULL) fprintf(errors_file, "%s", user_params[i]);
    fprintf(errors_file, "\n");
    return;
  }
  USER user = create_user();
  USERS_CATALOG users_catalog = (USERS_CATALOG)catalog;

  set_user_id(user, user_params[0]);
  set_user_name(user, user_params[1]);
  set_user_email(user, user_params[2]);
  set_user_phone_number(user, user_params[3]);
  set_user_birth_date(user, user_params[4]);
  set_user_sex(user, user_params[5]);
  set_user_passport(user, user_params[6]);
  set_user_country_code(user, user_params[7]);
  set_user_address(user, user_params[8]);
  set_user_account_creation(user, user_params[9]);
  set_user_pay_method(user, user_params[10]);
  set_user_account_status(user, standardize_account_status(user_params[11]));

  add_user_to_catalog(users_catalog, user, user->id);
}

void set_user_id(USER user, char *id) {
  user->id = g_strdup(id);
  // gpointer id_pointer = g_strdup(id);
  // user->id = id_pointer;
}

void set_user_name(USER user, char *name) { user->name = g_strdup(name); }

void set_user_email(USER user, char *email) { user->email = g_strdup(email); }

void set_user_phone_number(USER user, char *phone_number) {
  user->phone_number = g_strdup(phone_number);
}

void set_user_birth_date(USER user, char *birth_date) {
  user->birth_date = g_strdup(birth_date);
}

void set_user_sex(USER user, char *sex) { user->sex = g_strdup(sex); }

void set_user_passport(USER user, char *passport) {
  user->passport = g_strdup(passport);
}

void set_user_country_code(USER user, char *country_code) {
  user->country_code = g_strdup(country_code);
}

void set_user_address(USER user, char *address) {
  user->address = g_strdup(address);
}

void set_user_account_creation(USER user, char *account_creation) {
  user->account_creation = g_strdup(account_creation);
}

void set_user_pay_method(USER user, char *pay_method) {
  user->pay_method = g_strdup(pay_method);
}

void set_user_account_status(USER user, char *account_status) {
  user->account_status = g_strdup(account_status);
}

void free_user(USER user) {
  g_free(user->name);
  g_free(user->email);
  g_free(user->phone_number);
  g_free(user->birth_date);
  g_free(user->sex);
  g_free(user->passport);
  g_free(user->country_code);
  g_free(user->address);
  g_free(user->account_creation);
  g_free(user->pay_method);
  g_free(user->account_status);
}

char *get_user_id_from_user(USER user) {
  char *id = g_strdup(user->id);
  return id;
}

char *get_user_name(USER user) {
  char *name = g_strdup(user->name);
  return name;
}

char *get_user_email(USER user) {
  char *email = g_strdup(user->email);
  return email;
}

char *get_user_phone_number(USER user) {
  char *phone_number = g_strdup(user->phone_number);
  return phone_number;
}

char *get_user_birth_date(USER user) {
  char *birth_date = g_strdup(user->birth_date);
  return birth_date;
}

char *get_user_sex(USER user) {
  char *sex = g_strdup(user->sex);
  return sex;
}

char *get_user_passport(USER user) {
  char *passport = g_strdup(user->passport);
  return passport;
}

char *get_user_country_code(USER user) {
  char *country_code = g_strdup(user->country_code);
  return country_code;
}

char *get_user_address(USER user) {
  char *address = g_strdup(user->address);
  return address;
}

char *get_user_account_creation(USER user) {
  char *account_creation = g_strdup(user->account_creation);
  return account_creation;
}

char *get_user_pay_method(USER user) {
  char *pay_method = g_strdup(user->pay_method);
  return pay_method;
}

char *get_user_account_status(USER user) {
  if (user == NULL) {
    return NULL;
  } else {
    char *account_status = g_strdup(user->account_status);

    return standardize_account_status(account_status);
  }
}
