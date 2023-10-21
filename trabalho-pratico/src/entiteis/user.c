#include "entities/user.h"

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user{
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

User creat_user(){
    User new_user = malloc(sizeof(struct user));
    new_user -> id = NULL;

    return new_user;     
}

void set_user_id(User user, char *id){
    int id_int = string_to_int(id);
    gpointer id_pointer = GINT_TO_POINTER(id_int);
    user -> id = id_pointer;
}

void set_user_name(User user, char *name){
    user -> name = g_strdup(name);
}

void set_user_email(User user, char *email){
    user -> email = g_strdup(email);
}

void set_user_phone_number(User user, char *phone_number){
    user -> phone_number= g_strdup(phone_number);
}

void set_user_birth_date(User user, char *birth_date){
    user -> birth_date = g_strdup(birth_date);
}

void set_user_sex(User user ,char *sex){
    user -> sex = g_strdup(sex);
}

void set_user_passport(User user , char *passport){
    user -> passport = g_strdup(passport);
}

void set_user_country_code(User user, char *country_code){
    user -> country_code = g_strdup(country_code);
}

void set_user_address(User user ,char *address){
    user -> address = g_strdup(address);
}

void set_user_account_creation(User user, char *account_creation){
    user -> account_creation = g_strdup(account_creation);
}

void set_user_pay_method(User user , char *pay_method){
    user -> pay_method = g_strdup(pay_method);
}

void set_user_account_status(User user, char *account_status){
    user -> account_status = g_strdup(account_status);
}

void free_user(User user){
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