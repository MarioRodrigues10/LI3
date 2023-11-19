#ifndef USER_SERVICE_H
#define USER_SERVICE_H

#include <stdio.h>

#include "controllers/user_controller.h"
#include "models/user.h"
#include "utils/validation.h"
/**
 * @brief Verifies if the input is valid.
 *
 * @param parameters Parameters of type 'char**'.
 *
 * @returns 1 if the input is valid, 0 otherwise.
 *
 */
int verify_user_input(char **parameters);

/**
 * @brief Constructs a user.
 *
 * @param parameters Parameters of type 'char**'.
 * @param struct_data Struct data of type 'void*'.
 * @param struct_users_stats Struct users stats of type 'void*'.
 * @param errors_file The errors file
 *
 */
void construct_user(char **parameters, void *struct_data,
                    void *struct_users_stats, FILE *errors_file);

#endif
