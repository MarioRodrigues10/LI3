#include "services/queries/query10.h"

#include <ctype.h>

void write_query10(bool has_f, FILE *output_file, int *date, int *number_users,
                   int *number_flights, int *number_passengers,
                   int *number_unique_passengers, int *number_reservations,
                   char *flag, int N) {
  if (has_f) {
    for (int i = 0; i < N; i++) {
      if (i != 0) fprintf(output_file, "\n");
      fprintf(output_file,
              "--- %d ---\n%s: %d\nusers: %d\nflights: %d\npassengers: "
              "%d\nunique_passengers: %d\nreservations: %d\n",
              i + 1, flag, date[i], number_users[i], number_flights[i],
              number_passengers[i], number_unique_passengers[i],
              number_reservations[i]);
    }
  } else {
    for (int i = 0; i < N; i++) {
      fprintf(output_file, "%d;%d;%d;%d;%d;%d\n", date[i], number_users[i],
              number_flights[i], number_passengers[i],
              number_unique_passengers[i], number_reservations[i]);
    }
  }
}

void query10(bool has_f, char **query_parameters, int num_parameters,
             GeneralData *general_data, FILE *output_file) {
  char *parameter = query_parameters[0];
  if (num_parameters == 1 && !isdigit(parameter[0])) {
    int pos = 0;
    int years_array[14];
    int number_of_users_array[14];
    int number_of_flights_array[14];
    int number_of_passengers_array[14];
    int number_of_reservations_array[14];
    int number_of_unique_passengers_array[14];
    for (int year = 2010; year < 2024; year++) {
      int date_temp = year * 10000;
      GeneralStats *general_stats =
          get_general_stats_by_key(general_data, date_temp);
      if (general_stats != NULL) {
        int number_of_users = get_users_from_general_stats(general_stats);
        int number_of_flights =
            get_number_of_flights_from_general_stats(general_stats);
        int number_of_passengers =
            get_number_of_passengers_from_general_stats(general_stats);
        int number_of_unique_passengers =
            get_unique_passengers_from_general_stats(general_stats);
        int number_of_reservations =
            get_reservations_from_general_stats(general_stats);

        years_array[pos] = year;
        number_of_users_array[pos] = number_of_users;
        number_of_flights_array[pos] = number_of_flights;
        number_of_passengers_array[pos] = number_of_passengers;
        number_of_reservations_array[pos] = number_of_reservations;
        number_of_unique_passengers_array[pos] =
            number_of_unique_passengers - 1;
      }
      pos++;
    }
    write_query10(has_f, output_file, years_array, number_of_users_array,
                  number_of_flights_array, number_of_passengers_array,
                  number_of_unique_passengers_array,
                  number_of_reservations_array, "year", pos);
  } else if (num_parameters == 1 && isdigit(parameter[0])) {
    int year = strtol(query_parameters[0], NULL, 10);
    int months_array[12];
    int number_of_users_array[12];
    int number_of_flights_array[12];
    int number_of_passengers_array[12];
    int number_of_reservations_array[12];
    int number_of_unique_passengers_array[12];
    int month, pos = 0;
    for (month = 1; month < 13; month++) {
      int date_temp = year * 10000 + month * 100;
      GeneralStats *general_stats =
          get_general_stats_by_key(general_data, date_temp);
      if (general_stats != NULL) {
        int number_of_users = get_users_from_general_stats(general_stats);
        int number_of_flights =
            get_number_of_flights_from_general_stats(general_stats);
        int number_of_passengers =
            get_number_of_passengers_from_general_stats(general_stats);
        int number_of_unique_passengers =
            get_unique_passengers_from_general_stats(general_stats);
        int number_of_reservations =
            get_reservations_from_general_stats(general_stats);

        months_array[pos] = month;
        number_of_users_array[pos] = number_of_users;
        number_of_flights_array[pos] = number_of_flights;
        number_of_passengers_array[pos] = number_of_passengers;
        number_of_reservations_array[pos] = number_of_reservations;
        number_of_unique_passengers_array[pos] =
            number_of_unique_passengers - 1;
        pos++;
      } else
        break;
    }
    write_query10(has_f, output_file, months_array, number_of_users_array,
                  number_of_flights_array, number_of_passengers_array,
                  number_of_unique_passengers_array,
                  number_of_reservations_array, "month", pos);
  } else if (num_parameters == 2) {
    int year = strtol(query_parameters[0], NULL, 10),
        month = strtol(query_parameters[1], NULL, 10), pos = 0;
    int days_array[31], number_of_users_array[31], number_of_flights_array[31],
        number_of_passengers_array[31], number_of_reservations_array[31],
        number_of_unique_passengers_array[31];

    for (int day = 1; day < 32; day++) {
      int date_temp = year * 10000 + month * 100 + day;
      GeneralStats *general_stats =
          get_general_stats_by_key(general_data, date_temp);
      if (general_stats != NULL) {
        int number_of_users = get_users_from_general_stats(general_stats);
        int number_of_flights =
            get_number_of_flights_from_general_stats(general_stats);
        int number_of_passengers =
            get_number_of_passengers_from_general_stats(general_stats);
        int number_of_unique_passengers =
            get_unique_passengers_from_general_stats(general_stats);
        int number_of_reservations =
            get_reservations_from_general_stats(general_stats);

        days_array[pos] = day;
        number_of_users_array[pos] = number_of_users;
        number_of_flights_array[pos] = number_of_flights;
        number_of_passengers_array[pos] = number_of_passengers;
        number_of_reservations_array[pos] = number_of_reservations;
        number_of_unique_passengers_array[pos] =
            number_of_unique_passengers - 1;
        pos++;
      }
    }
    write_query10(has_f, output_file, days_array, number_of_users_array,
                  number_of_flights_array, number_of_passengers_array,
                  number_of_unique_passengers_array,
                  number_of_reservations_array, "day", pos);
  }
}
