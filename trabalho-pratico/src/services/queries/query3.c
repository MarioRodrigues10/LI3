#include "services/queries/query3.h"

void write_query3(bool has_f, FILE *output_file, double media_of_ratings) {
  if (has_f) {
    fprintf(output_file, "--- 1 ---\nrating: %.3f\n", media_of_ratings);
  } else {
    fprintf(output_file, "%.3f\n", media_of_ratings);
  }
}

void query3(bool has_f, char **query_parameters,
            ReservationsData *reservations_data, FILE *output_file) {
  char *id = query_parameters[0];

  HotelStats *hotel_stats = get_hotel_stats_by_hotel_id(reservations_data, id);

  if (hotel_stats == NULL) return;

  int total_rating = get_total_rating_from_hotel_stats(
      get_hotel_stats_by_hotel_id(reservations_data, id));

  int number_of_clients = get_number_of_clients_from_hotel_stats(
      get_hotel_stats_by_hotel_id(reservations_data, id));

  double media_of_ratings = (double)total_rating / number_of_clients;

  write_query3(has_f, output_file, media_of_ratings);
}
