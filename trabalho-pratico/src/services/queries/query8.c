#include "services/queries/query8.h"

void write_query8(bool has_f, FILE *output_file, double revenue) {
  if (has_f) {
    fprintf(output_file, "--- 1 ---\nrevenue: %.f\n", revenue);
  } else {
    fprintf(output_file, "%.f\n", revenue);
  }
}

void query8(bool has_f, char **query_parameters,
            ReservationsData *reservations_data, FILE *output_file) {
  char *id = query_parameters[0];
  char *begin_date_str = query_parameters[1];
  char *end_date_str = query_parameters[2];
  HotelStats *hotel_stats = get_hotel_stats_by_hotel_id(reservations_data, id);
  if (hotel_stats == NULL) return;
  GArray *reservations = get_hotel_reservations(hotel_stats);
  if (reservations == NULL) return;

  double revenue = 0;

  int begin_date = normalize_date(begin_date_str);
  int end_date = normalize_date(end_date_str);

  for (guint i = 0; i < reservations->len; i++) {
    int reservation_id = g_array_index(reservations, int, i);
    ReservationInfo *reservation =
        get_reservation_by_reservation_id(reservations_data, reservation_id);

    int begin_date_reservation = (get_begin_date(reservation));
    int end_date_reservation = (get_end_date(reservation));

    if (begin_date_reservation <= end_date &&
        end_date_reservation >= begin_date) {
      int min_date = (begin_date_reservation > begin_date)
                         ? begin_date_reservation
                         : begin_date;

      int max_date =
          (end_date_reservation < end_date) ? end_date_reservation : end_date;

      int num_nights =
          (max_date - min_date) + ((max_date < end_date_reservation) ? 1 : 0);

      if (num_nights > 0) {
        int price_per_night = get_price_per_night(reservation);
        revenue += price_per_night * num_nights;
      }
    }
  }
  g_array_free(reservations, TRUE);
  write_query8(has_f, output_file, revenue);
}
