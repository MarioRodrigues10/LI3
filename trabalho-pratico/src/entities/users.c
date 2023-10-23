#include "../includes/entities/users.h"

#include <stdio.h>
#include <stdlib.h>

struct user {
  char id[MAX_FIELD_SIZE];
  char name[MAX_FIELD_SIZE];
  char email[MAX_FIELD_SIZE];
  char phone_number[MAX_FIELD_SIZE];
  char birth_date[MAX_FIELD_SIZE];
  char sex[MAX_FIELD_SIZE];
  char passport[MAX_FIELD_SIZE];
  char country_code[MAX_FIELD_SIZE];
  char address[MAX_FIELD_SIZE];
  char account_creation[MAX_FIELD_SIZE];
  char pay_method[MAX_FIELD_SIZE];
  char account_status[MAX_FIELD_SIZE];
};