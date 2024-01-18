#ifndef QUERY9_H
#define QUERY9_H

#include <locale.h>
#include <stdbool.h>
#include <stdio.h>

#include "controllers/user_controller.h"
#include "models/user.h"
#include "services/user_service.h"
#include "stats/user_stats.h"
#include "utils/utils.h"

/**
 * @brief Writes the query9 output to the output file.
 *
 * @param has_f Whether the output should be formatted or not.
 * @param output_file The output file.
 * @param user_ids The user ids.
 * @param user_names The user names.
 * @param N The length of the array.
 */
void write_query9(bool has_f, FILE *output_file, char **user_ids,
                  char **user_names, int N);

/**
 * @brief Queries the data structs.
 *
 * @param has_f If the query has the modifier 'F'.
 * @param line The line with the quey parameters.
 * @param users_data The users data struct.
 * @param output_file The pointer to the output file.
 * @param num_parameters The number of parameters.
 */
void query9(bool has_f, char **query_parameters, UsersData *users_data,
            StatsUserInfo *users_stats, FILE *output_file, int num_parameters);

#endif
