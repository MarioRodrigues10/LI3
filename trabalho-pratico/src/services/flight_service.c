#include "services/flight_service.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verify_flight_input(char **parameters) {
  if (!validate_parameter_not_empty(parameters[0])) return 0;
  if (!validate_parameter_not_empty(parameters[1])) return 0;

  if (!validate_parameter_not_empty(parameters[2])) return 0;

  if (!validate_parameter_not_empty(parameters[3]) ||
      !validate_total_seats(parameters[3]))
    return 0;

  if (!validate_parameter_not_empty(parameters[4]) ||
      strlen(parameters[4]) != 3)
    return 0;

  if (!validate_parameter_not_empty(parameters[5]) ||
      strlen(parameters[5]) != 3)
    return 0;

  if (!validate_parameter_not_empty(parameters[6]) ||
      !validate_date_format_with_time(parameters[6]))
    return 0;

  if (!validate_parameter_not_empty(parameters[7]) ||
      !validate_date_format_with_time(parameters[7]))
    return 0;

  if (!validate_parameter_not_empty(parameters[8]) ||
      !validate_date_format_with_time(parameters[8]))
    return 0;

  if (!validate_parameter_not_empty(parameters[9]) ||
      !validate_date_format_with_time(parameters[9]))
    return 0;

  if (!validate_parameter_not_empty(parameters[10])) return 0;

  if (!validate_parameter_not_empty(parameters[11])) return 0;

  if (compare_dates(parameters[6], parameters[7]) >= 0) return 0;
  if (compare_dates(parameters[8], parameters[9]) >= 0) return 0;
  if (strcmp(parameters[4], parameters[5]) == 0) return 0;

  return 1;
}

void construct_flight(char **parameters, void *flights_data,
                      FILE *errors_file) {
  if (!verify_flight_input(parameters)) {
    int i;
    for (i = 0; i < MAX_TOKENS_FLIGHT - 1; i++) {
      if (parameters[i] == NULL) {
        fprintf(errors_file, ";");
      }
      fprintf(errors_file, "%s;", parameters[i]);
    }
    if (parameters[i] != NULL) fprintf(errors_file, "%s", parameters[i]);
    fprintf(errors_file, "\n");
    return;
  }

  FlightInfo *flight_info = create_flight();

  FlightsData *flight_data = (FlightsData *)flights_data;

  set_flight_id(flight_info, parameters[0]);
  set_airline(flight_info, parameters[1]);
  set_plane_model(flight_info, parameters[2]);
  set_total_seats(flight_info, strtol(parameters[3], NULL, 10));
  set_origin(flight_info, parameters[4]);
  set_destination(flight_info, parameters[5]);
  set_schedule_departure_date(flight_info, parameters[6]);
  set_schedule_arrival_date(flight_info, parameters[7]);
  set_real_departure_date(flight_info, parameters[8]);

  add_flight(flight_data, flight_info);
  update_airport_stats_controller(flight_data, parameters[4], parameters[0]);

  // destroy_airport_info(airport_info);
}
