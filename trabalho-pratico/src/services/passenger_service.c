#include "services/passenger_service.h"

#include <stdio.h>

int verify_passenger_input(char **parameters, UsersData *users_data,
                           FlightsData *flights_data) {
  if (!validate_parameter_not_empty(parameters[0]) ||
      get_flight_by_flight_id(flights_data, strtol(parameters[0], NULL, 10)) ==
          NULL)
    return 0;
  if (!validate_parameter_not_empty(parameters[1]) ||
      get_user_by_username(users_data, parameters[1]) == NULL)
    return 0;

  return 1;
}

void construct_passenger(char **parameters, UsersData *users_data,
                         FlightsData *flights_data, GeneralData *general_data,
                         FILE *errors_file) {
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
  int id = strtol(parameters[0], NULL, 10);

  UserStats *user_stats = get_user_stats_by_user_id(users_data, parameters[1]);
  user_stats =
      update_user_stats_controller(users_data, parameters[1], 1, 0, 0.0);
  update_flight_stats_controller(flights_data, id, 1);
  update_user_flights(user_stats, parameters[1], id);
  FlightInfo *flight_info = get_flight_by_flight_id(flights_data, id);
  char *schedule_departure_date = get_schedule_departure_date(flight_info);
  int departure_date_day = normalize_date_with_day(schedule_departure_date);
  int departure_date_month = normalize_date_with_month(schedule_departure_date);
  int departure_date_year = normalize_date_with_year(schedule_departure_date);

  free(schedule_departure_date);
  char *user = g_strdup(parameters[1]);
  update_general_stats_controller(general_data, departure_date_day, 0, 0, 1, 0,
                                  user);
  update_general_stats_controller(general_data, departure_date_month, 0, 0, 1,
                                  0, user);
  update_general_stats_controller(general_data, departure_date_year, 0, 0, 1, 0,
                                  user);
}
