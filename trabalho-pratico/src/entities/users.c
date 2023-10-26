#include "entities/users.h"

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user {
  gpointer id;
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
  if (!parameters[0]) return 0;
  if (!parameters[1]) return 0;
  if (!parameters[2]) return 0;
  if (!parameters[3]) return 0;
  if (!parameters[4]) return 0;
  if (!parameters[5]) return 0;
  if (!parameters[6]) return 0;
  if (!parameters[7]) return 0;
  if (!parameters[8]) return 0;
  if (!parameters[9]) return 0;
  if (!parameters[10]) return 0;
  if (!parameters[11]) return 0;

  return 1;
}

USER create_user() {
  USER new_user = malloc(sizeof(struct user));
  new_user->id = NULL;

  return new_user;
}

void set_user_id(USER user, char *id) {
  int id_int = string_to_int(id);
  gpointer id_pointer = GINT_TO_POINTER(id_int);
  user->id = id_pointer;
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

int get_user_id(USER user) {
  int id = GPOINTER_TO_INT(user->id);
  return id
}

char *get_user_name(USER user) {
  char *name = strdup(user->name);
  return name;
}

char *get_user_email(USER user) {
  char *email = strdup(user->email);
  return email;
}

char *get_user_phone_number(USER user) {
  char *phone_number = strdup(user->phone_number);
  return phone_number;
}

char *get_user_birth_date(USER user) {
  char *birth_date = strdup(user->birth_date);
  return birth_date;
}

char *get_user_sex(USER user) {
  char *sex = strdup(user->sex);
  return sex;
}

char *get_user_passport(USER user) {
  char *passport = strdup(user->passport);
  return passport;
}

char *get_user_country_code(USER user) {
  char *country_code = strdup(user->country_code);
  return country_code;
}

char *get_user_address(USER user) {
  char *address = strdup(user->address);
  return address;
}

char *get_user_account_creation(USER user) {
  char *account_creation = strdup(user->account_creation);
  return account_creation;
}

char *get_user_pay_method(USER user) {
  char *pay_method = strdup(user->pay_method);
  return pay_method;
}

char *get_user_account_status(USER user) {
  char *account_status = strdup(user->account_status);
  return account_status;
}