#include "models/user.h"

#include <glib.h>
#include <stdbool.h>

struct user {
  char *user_id;
  char *name;
  int birth_date;
  bool sex;
  char *passport;
  char *country_code;
  char *account_creation;
  char *account_status;
};

// CREATE

UserInfo *create_user() {
  UserInfo *user = g_malloc(sizeof(UserInfo));

  return user;
}

// SETTERS

void set_user_id(UserInfo *user, char *user_id) {
  user->user_id = g_strdup(user_id);
}

void set_name(UserInfo *user, char *name) { user->name = g_strdup(name); }

void set_birth_date(UserInfo *user, int birth_date) {
  user->birth_date = birth_date;
}

void set_sex(UserInfo *user, bool sex) { user->sex = sex; }

void set_passport(UserInfo *user, char *passport) {
  user->passport = g_strdup(passport);
}

void set_country_code(UserInfo *user, char *country_code) {
  user->country_code = g_strdup(country_code);
}

void set_account_creation(UserInfo *user, char *account_creation) {
  user->account_creation = g_strdup(account_creation);
}

void set_account_status(UserInfo *user, char *account_status) {
  user->account_status = g_strdup(account_status);
}

// GETTERS

char *get_user_id(UserInfo *user) {
  char *user_id = g_strdup(user->user_id);
  return user_id;
}

char *get_name(UserInfo *user) {
  char *name = g_strdup(user->name);
  return name;
}

int get_birth_date(UserInfo *user) { return user->birth_date; }

bool get_sex(UserInfo *user) { return user->sex; }

char *get_passport(UserInfo *user) {
  char *passport = g_strdup(user->passport);
  return passport;
}

char *get_country_code(UserInfo *user) {
  char *country_code = g_strdup(user->country_code);
  return country_code;
}

char *get_account_creation(UserInfo *user) {
  char *account_creation = g_strdup(user->account_creation);
  return account_creation;
}

char *get_account_status(UserInfo *user) {
  if (user == NULL) return NULL;
  char *account_status = g_strdup(user->account_status);
  return account_status;
}

// DESTROYER

void destroy_user(UserInfo *user) {
  g_free(user->user_id);
  g_free(user->name);
  g_free(user->passport);
  g_free(user->country_code);
  g_free(user->account_creation);
  g_free(user->account_status);
  g_free(user);
}
