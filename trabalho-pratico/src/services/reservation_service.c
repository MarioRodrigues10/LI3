#include "services/reservation_service.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verify_reservation_input(char **parameters, UsersData *users_data) {
  if (!validate_parameter_not_empty(parameters[0])) return 0;
  if (!validate_parameter_not_empty(parameters[1]) ||
      get_user_by_username(users_data, parameters[1]) == NULL)
    return 0;
  if (!validate_parameter_not_empty(parameters[2])) return 0;

  if (!validate_parameter_not_empty(parameters[3])) return 0;

  if (!validate_parameter_not_empty(parameters[4]) ||
      !validate_number_of_stars(parameters[4]))
    return 0;

  if (!validate_parameter_not_empty(parameters[5]) ||
      !validate_city_tax(parameters[5]))
    return 0;

  if (!validate_parameter_not_empty(parameters[6])) return 0;

  if (!validate_parameter_not_empty(parameters[7]) ||
      !validate_date_format_without_time(parameters[7]))
    return 0;

  if (!validate_parameter_not_empty(parameters[8]) ||
      !validate_date_format_without_time(parameters[8]))
    return 0;

  if (!validate_parameter_not_empty(parameters[9]) ||
      !validate_price_per_night(strtol(parameters[9], NULL, 10)))
    return 0;

  if (!validate_includes_breakfast(parameters[10])) return 0;

  if (!validate_parameter_not_empty(parameters[11])) return 0;

  if (!validate_parameter_not_empty(parameters[12]) ||
      !validate_rating(parameters[12]))
    return 0;

  if (compare_dates(parameters[7], parameters[8]) == 1) return 0;
  return 1;
}

void construct_reservation(char **parameters,
                           ReservationsData *reservations_data,
                           UsersData *users_data, GeneralData *general_data,
                           FILE *errors_file) {
  if (!verify_reservation_input(parameters, users_data)) {
    int i;
    for (i = 0; i < MAX_TOKENS_RESERVATION - 1; i++) {
      if (parameters[i] == NULL) {
        fprintf(errors_file, ";");
      }
      fprintf(errors_file, "%s;", parameters[i]);
    }
    if (parameters[i] != NULL) fprintf(errors_file, "%s", parameters[i]);
    fprintf(errors_file, "\n");
    return;
  }

  ReservationInfo *reservation_info = create_reservation();
  int reservation_id = normalize_reservation_id(parameters[0]);
  int begin_date_day = normalize_date(parameters[7]);
  int begin_date_month = normalize_date_month(parameters[7]);
  int begin_date_year = normalize_date_year(parameters[7]);
  set_reservation_id(reservation_info, reservation_id);
  set_user_id_reservation(reservation_info, parameters[1]);
  set_hotel_id(reservation_info, normalize_hotel_id(parameters[2]));
  set_hotel_name(reservation_info, parameters[3]);
  set_hotel_stars(reservation_info, strtol(parameters[4], NULL, 10));
  set_city_tax(reservation_info, strtol(parameters[5], NULL, 10));
  set_begin_date(reservation_info, begin_date_day);
  set_end_date(reservation_info, normalize_date(parameters[8]));
  set_price_per_night(reservation_info, strtol(parameters[9], NULL, 10));
  set_includes_breakfast(reservation_info,
                         normalize_includes_breakfast(parameters[10]));
  set_rating(reservation_info, strtol(parameters[12], NULL, 10));

  add_reservation(reservations_data, reservation_info);

  update_user_stats_controller(users_data, parameters[1], 0, 1, 0.0);
  update_user_stats_controller(
      users_data, parameters[1], 0, 0,
      calculate_total_price(
          calculate_number_of_nights(parameters[7], parameters[8]),
          strtol(parameters[9], NULL, 10), strtol(parameters[5], NULL, 10)));
  update_hotel_stats_controller(reservations_data, parameters[2],
                                strtol(parameters[12], NULL, 10),
                                reservation_id);
  UserStats *user_stats = get_user_stats_by_user_id(users_data, parameters[1]);

  update_user_reservations(user_stats, parameters[1], reservation_id);
  update_general_stats_controller(general_data, begin_date_day, 0, 0, 0, 0, 1,
                                  NULL);
  update_general_stats_controller(general_data, begin_date_month, 0, 0, 0, 0, 1,
                                  NULL);
  update_general_stats_controller(general_data, begin_date_year, 0, 0, 0, 0, 1,
                                  NULL);
}
