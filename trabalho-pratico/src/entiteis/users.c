#include "entities/users.h"

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct users{
    gpointer  id;
    char *name;
    char *email;
    char *phone_number;
    char *birth_date;
    char *sex;
    char *passport;
    char *coutry_code;
    char *address;
    char *account_creation;
    char *pay_method;
    char* account_status;
};