#include "services/queries/query1.h"

#include <ctype.h>

void write_query1_for_reservation(bool has_f, FILE *output_file, char *hotel_id,
                                  char *hotel_name, char hotel_stars,
                                  char *begin_date, char *end_date,
                                  char *includes_breakfast,
                                  int number_of_nights, double total_price) {
  if (has_f) {
    fprintf(output_file,
            "--- 1 ---\nhotel_id: %s\nhotel_name: %s\nhotel_stars: "
            "%d\nbegin_date: %s\nend_date: %s\nincludes_breakfast: "
            "%s\nnights: %d\ntotal_price: %.3f\n",
            hotel_id, hotel_name, hotel_stars, begin_date, end_date,
            includes_breakfast, number_of_nights, total_price);
  } else {
    fprintf(output_file, "%s;%s;%d;%s;%s;%s;%d;%.3f\n", hotel_id, hotel_name,
            hotel_stars, begin_date, end_date, includes_breakfast,
            number_of_nights, total_price);
  }
}

void write_query1_for_flight(bool has_f, FILE *output_file,
                             char *airline_company, char *plane_model,
                             char *origin, char *destination,
                             char *schedule_departure_date,
                             char *schedule_arrival_date, int passengers,
                             int delay) {
  if (has_f) {
    fprintf(output_file,
            "--- 1 ---\nairline: %s\nplane_model: %s\norigin: "
            "%s\ndestination: %s\nschedule_departure_date: "
            "%s\nschedule_arrival_date: %s\npassengers: %d\ndelay: %d\n",
            airline_company, plane_model, origin, destination,
            schedule_departure_date, schedule_arrival_date, passengers, delay);
  } else {
    fprintf(output_file, "%s;%s;%s;%s;%s;%s;%d;%d\n", airline_company,
            plane_model, origin, destination, schedule_departure_date,
            schedule_arrival_date, passengers, delay);
  }
}

void write_query1_for_user(bool has_f, FILE *output_file, char *name, char *sex,
                           int age, char *country_code, char *passport,
                           int number_of_flights, int number_of_reservations,
                           double total_spent) {
  if (has_f) {
    fprintf(output_file,
            "--- 1 ---\nname: %s\nsex: %s\nage: %d\ncountry_code: "
            "%s\npassport: %s\nnumber_of_flights: "
            "%d\nnumber_of_reservations: %d\ntotal_spent: %.3f\n",
            name, sex, age, country_code, passport, number_of_flights,
            number_of_reservations, total_spent);
  } else {
    fprintf(output_file, "%s;%s;%d;%s;%s;%d;%d;%.3f\n", name, sex, age,
            country_code, passport, number_of_flights, number_of_reservations,
            total_spent);
  }
}

void query1(bool has_f, char **query_parameters, FlightsData *flights_data,
            ReservationsData *reservations_data, UsersData *users_data,
            Maping *map, FILE *output_file) {
  char *id = query_parameters[0];

  if (strncmp(id, "Book", 4) == 0) {
    ReservationInfo *reservation_info = get_reservation_by_reservation_id(
        reservations_data, normalize_reservation_id(id));

    if (reservation_info == NULL) return;

    int price_per_night = get_price_per_night(reservation_info);
    char city_tax = get_city_tax(reservation_info);

    int hotel_id_int = get_hotel_id(reservation_info);
    char *hotel_id = malloc(sizeof(char) * 10);
    sprintf(hotel_id, "HTL%d", hotel_id_int);
    char *hotel_name = char_to_string(map, get_hotel_name(reservation_info));
    char hotel_stars = get_hotel_stars(reservation_info);
    char *begin_date = date_to_string(get_begin_date(reservation_info));
    char *end_date = date_to_string(get_end_date(reservation_info));
    char *breakfast =
        get_includes_breakfast(reservation_info) ? "True" : "False";
    int number_of_nights = calculate_number_of_nights(begin_date, end_date);
    double total_price =
        calculate_total_price(number_of_nights, price_per_night, city_tax);

    write_query1_for_reservation(has_f, output_file, hotel_id, hotel_name,
                                 hotel_stars, begin_date, end_date, breakfast,
                                 number_of_nights, total_price);
    free(begin_date);
    free(end_date);
    free(hotel_id);
    free(hotel_name);
  }

  if (isdigit(id[0]) && isdigit(id[1])) {
    int new_id = strtol(id, NULL, 10);
    FlightInfo *flight_info = get_flight_by_flight_id(flights_data, new_id);

    if (flight_info == NULL) return;

    char *real_departure_date = get_real_departure_date(flight_info);

    char *airline_company = char_to_string(map, get_airline(flight_info));
    char *plane_model = char_to_string(map, get_plane_model(flight_info));
    char *origin = get_origin(flight_info);
    char *destination = get_destination(flight_info);
    char *schedule_departure_date = get_schedule_departure_date(flight_info);
    char *schedule_arrival_date = get_schedule_arrival_date(flight_info);
    int passengers = get_number_of_passengers_from_flight_stats(
        get_flight_stats_by_flight_id(flights_data, new_id));
    int delay = calculate_delay(schedule_departure_date, real_departure_date);

    write_query1_for_flight(has_f, output_file, airline_company, plane_model,
                            origin, destination, schedule_departure_date,
                            schedule_arrival_date, passengers, delay);
    free(schedule_departure_date);
    free(schedule_arrival_date);
    free(plane_model);
    free(origin);
    free(destination);
    free(airline_company);
    free(real_departure_date);
  }

  UserInfo *user_info = get_user_by_username(users_data, id);

  if (user_info == NULL) return;

  bool account_status = get_account_status(user_info);

  if (account_status) {
    char *name = get_name(user_info);
    char *sex = get_sex(user_info) ? "M" : "F";
    int age = calculate_age(get_birth_date(user_info));
    char *country_code = get_country_code(user_info);
    char *passport = get_passport(user_info);
    int number_of_flights = get_number_of_flights_from_user_stats(
        get_user_stats_by_user_id(users_data, id));
    int number_of_reservations = get_number_of_reservations_from_user_stats(
        get_user_stats_by_user_id(users_data, id));
    double total_spent = get_total_spent_from_user_stats(
        get_user_stats_by_user_id(users_data, id));

    write_query1_for_user(has_f, output_file, name, sex, age, country_code,
                          passport, number_of_flights, number_of_reservations,
                          total_spent);
    free(name);
    free(country_code);
    free(passport);
  }
}
