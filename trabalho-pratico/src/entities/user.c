#include "entities/user.h"

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

int verifyUserInput(char **parameters) {
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

User createUser() {
  User new_user = malloc(sizeof(struct user));
  new_user->id = NULL;

  return new_user;
}

void setUserId(User user, char *id) {
  int id_int = string_to_int(id);
  gpointer id_pointer = GINT_TO_POINTER(id_int);
  user->id = id_pointer;
}

void setUserName(User user, char *name) { user->name = g_strdup(name); }

void setUserEmail(User user, char *email) { user->email = g_strdup(email); }

void setUserPhoneNumber(User user, char *phone_number) {
  user->phone_number = g_strdup(phone_number);
}

void setUserBirthDate(User user, char *birth_date) {
  user->birth_date = g_strdup(birth_date);
}

void setUserSex(User user, char *sex) { user->sex = g_strdup(sex); }

void setUserPassport(User user, char *passport) {
  user->passport = g_strdup(passport);
}

void setUserCountryCode(User user, char *country_code) {
  user->country_code = g_strdup(country_code);
}

void setUserAddress(User user, char *address) {
  user->address = g_strdup(address);
}

void setUserAccountCreation(User user, char *account_creation) {
  user->account_creation = g_strdup(account_creation);
}

void setUserPayMethod(User user, char *pay_method) {
  user->pay_method = g_strdup(pay_method);
}

void setUserAccountStatus(User user, char *account_status) {
  user->account_status = g_strdup(account_status);
}

void freeUser(User user) {
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

int getUserId(User user) {
  int id = GPOINTER_TO_INT(user->id);
  return id
}

char *getUserName(User user) {
  char *name = strdup(user->name);
  return name;
}

char *getUserEmail(User user) {
  char *email = strdup(user->email);
  return email;
}

char *getUserPhoneNumber(User user) {
  char *phone_number = strdup(user->phone_number);
  return phone_number;
}

char *getUserBirthDate(User user) {
  char *birth_date = strdup(user->birth_date);
  return birth_date;
}

char *getUserSex(User user) {
  char *sex = strdup(user->sex);
  return sex;
}

char *getUserPassport(User user) {
  char *passport = strdup(user->passport);
  return passport;
}

char *getUserCountryCode(User user) {
  char *country_code = strdup(user->country_code);
  return country_code;
}

char *getUserAddress(User user) {
  char *address = strdup(user->address);
  return address;
}

char *getUserAccountCreation(User user) {
  char *account_creation = strdup(user->account_creation);
  return account_creation;
}

char *getUserPayMethod(User user) {
  char *pay_method = strdup(user->pay_method);
  return pay_method;
}

char *getUserAccountStatus(User user) {
  char *account_status = strdup(user->account_status);
  return account_status;
}