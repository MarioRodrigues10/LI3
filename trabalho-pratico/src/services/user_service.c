#include "services/user_service.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// CONSTRUCT VALID DATA

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

void construct_user(char **parameters, void *struct_data,
                    void *struct_users_stats, void *struct_general_data,
                    FILE *errors_file) {
  if (!verify_user_input(parameters)) {
    int i;
    for (i = 0; i < MAX_TOKENS_USER - 1; i++) {
      if (parameters[i] == NULL) {
        fprintf(errors_file, ";");
      }
      fprintf(errors_file, "%s;", parameters[i]);
    }
    if (parameters[i] != NULL) fprintf(errors_file, "%s", parameters[i]);
    fprintf(errors_file, "\n");
    return;
  }

  UserInfo *user_info = create_user();

  UsersData *users_data = (UsersData *)struct_data;
  GeneralData *general_data = (GeneralData *)struct_general_data;

  int account_creation_day = normalize_date_with_day(parameters[9]);
  int account_creation_month = normalize_date_with_month(parameters[9]);
  int account_creation_year = normalize_date_with_year(parameters[9]);
  bool sex = strcmp(parameters[5], "M") ? false : true;
  set_user_id(user_info, parameters[0]);
  set_name(user_info, parameters[1]);
  set_birth_date(user_info, normalize_date(parameters[4]));
  set_sex(user_info, sex);
  set_passport(user_info, parameters[6]);
  set_country_code(user_info, parameters[7]);
  set_account_status(user_info, standardize_account_status(parameters[11]));

  char *user_id = get_user_id(user_info);
  char *user_name = get_name(user_info);
  update_user_stats_info(struct_users_stats, user_id, user_name);
  update_general_stats_controller(general_data, account_creation_day, 1, 0, 0,
                                  0, NULL);
  update_general_stats_controller(general_data, account_creation_month, 1, 0, 0,
                                  0, NULL);
  update_general_stats_controller(general_data, account_creation_year, 1, 0, 0,
                                  0, NULL);

  add_user(users_data, user_info);
  free(user_id);
  free(user_name);
}
