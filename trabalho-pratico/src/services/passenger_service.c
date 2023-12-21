#include "services/passenger_service.h"

#include <stdio.h>

int verify_passenger_input(char **parameters, UsersData *users_data,
                           FlightsData *flights_data) {
  if (!validate_parameter_not_empty(parameters[0]) ||
      get_flight_by_flight_id(flights_data, parameters[0]) == NULL)
    return 0;
  if (!validate_parameter_not_empty(parameters[1]) ||
      get_user_by_username(users_data, parameters[1]) == NULL)
    return 0;

  return 1;
}

void construct_passenger(char **parameters, UsersData *users_data,
                         FlightsData *flights_data, FILE *errors_file) {
  if (!verify_passenger_input(parameters, users_data, flights_data)) {
    int i;
    for (i = 0; i < MAX_TOKENS_PASSENGER - 1; i++) {
      if (parameters[i] == NULL) {
        fprintf(errors_file, ";");
      }
      fprintf(errors_file, "%s;", parameters[i]);
    }
    if (parameters[i] != NULL) fprintf(errors_file, "%s", parameters[i]);
    fprintf(errors_file, "\n");
    return;
  }

  UserStats *user_stats = get_user_stats_by_user_id(users_data, parameters[1]);
  update_user_stats_controller(users_data, parameters[1], 1, 0, 0.0);
  update_flight_stats_controller(flights_data, parameters[0], 1);
  update_user_flights(user_stats, parameters[1], parameters[0]);
}
