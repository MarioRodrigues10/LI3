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
    char *country_code;
    char *address;
    char *account_creation;
    char *pay_method;
    char* account_status;
};

USERS creat_users(){
    USERS new_users = malloc(sizeof(struct users));
    new_users -> id = NULL;

    return new_users;     
}

void set_users_id(USERS user, char *id){
    int id_int = string_to_int(id);
    gpointer id_pointer = GINT_TO_POINTER(id_int);
    user -> id = id_pointer;
}

void set_users_name(USERS user, char *name){
    user -> name = g_strdup(name);
}

void set_users_email(USERS user, char *email){
    user -> email = g_strdup(email);
}

void set_users_phone_number(USERS user, char *phone_number){
    user -> phone_number= g_strdup(phone_number);
}

void set_users_birth_date(USERS user, char *birth_date){
    user -> birth_date = g_strdup(birth_date);
}

void set_users_sex(USERS user ,char *sex){
    user -> sex = g_strdup(sex);
}

void set_users_passport(USERS user , char *passport){
    user -> passport = g_strdup(passport);
}

void set_users_country_code(USERS user, char *country_code){
    user -> country_code = g_strdup(country_code);
}

void set_users_address(USERS user ,char *address){
    user -> address = g_strdup(address);
}

void set_users_account_creation(USERS user, char *account_creation){
    user -> account_creation = g_strdup(account_creation);
}

void set_users_pay_method(USERS user , char *pay_method){
    user -> pay_method = g_strdup(pay_method);
}

void set_users_account_status(USERS user, char *account_status){
    user -> account_status = g_strdup(account_status);
}

void free_users(USERS user){
   g_free(user -> name);
   g_free(user -> email);
   g_free(user -> phone_number);
   g_free(user -> birth_date);
   g_free(user -> sex);
   g_free(user -> passport);
   g_free(user -> country_code);
   g_free(user -> address);
   g_free(user -> account_creation);
   g_free(user -> pay_method);
   g_free(user -> account_status);
}


void