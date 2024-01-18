#include "services/queries/query4.h"

#include <glib.h>
#include <locale.h>

struct query4_result_helper {
  char *reservation_id;
  char *begin_date;
  char *end_date;
  char *user_id;
  double total_price;
  char rating;
};

struct query4_result {
  GArray *query4_result;
};

void write_query4(bool has_f, FILE *output_file, GArray *query_result_array) {
  int j;
  for (guint i = 0; i < query_result_array->len; i++) {
    QUERY4_RESULT_HELPER query_result =
        g_array_index(query_result_array, QUERY4_RESULT_HELPER, i);
    j = i + 1;
    if (has_f) {
      if (i != 0) fprintf(output_file, "\n");
      fprintf(output_file,
              "--- %d ---\nid: %s\nbegin_date: %s\nend_date: "
              "%s\nuser_id: %s\nrating: %d\ntotal_price: %.3f\n",
              j, query_result->reservation_id, query_result->begin_date,
              query_result->end_date, query_result->user_id,
              query_result->rating, query_result->total_price);
    } else {
      fprintf(output_file, "%s;%s;%s;%s;%d;%.3f\n",
              query_result->reservation_id, query_result->begin_date,
              query_result->end_date, query_result->user_id,
              query_result->rating, query_result->total_price);
    }
  }
}

int compare_query4_result(const void *a, const void *b) {
  setlocale(LC_COLLATE, "en_US.UTF-8");
  const QUERY4_RESULT_HELPER *query4_result_a = (const QUERY4_RESULT_HELPER *)a;
  const QUERY4_RESULT_HELPER *query4_result_b = (const QUERY4_RESULT_HELPER *)b;

  int dateComparison =
      strcoll((*query4_result_b)->begin_date, (*query4_result_a)->begin_date);

  if (dateComparison != 0) {
    return dateComparison;
  } else {
    return strcoll((*query4_result_a)->reservation_id,
                   (*query4_result_b)->reservation_id);
  }
}

void sort_by_date_and_value(void *result, int N) {
  QUERY4_RESULT *query_result = (QUERY4_RESULT *)result;

  qsort((*query_result)->query4_result, N, sizeof(QUERY4_RESULT),
        compare_query4_result);
}

void query4(bool has_f, char **query_parameters,
            ReservationsData *reservations_data, FILE *output_file) {
  char *id = query_parameters[0];
  HotelStats *hotel_stats = get_hotel_stats_by_hotel_id(reservations_data, id);
  if (hotel_stats == NULL) return;
  GArray *reservations = get_hotel_reservations(hotel_stats);
  if (reservations == NULL) return;

  QUERY4_RESULT result = malloc(sizeof(struct query4_result));
  result->query4_result =
      g_array_new(FALSE, FALSE, sizeof(QUERY4_RESULT_HELPER));

  guint i = 0;
  int j = 0;
  for (i = 0; i < reservations->len; i++) {
    int reservation_id = g_array_index(reservations, int, i);
    if (reservation_id > 0) {
      QUERY4_RESULT_HELPER result_helper =
          malloc(sizeof(struct query4_result_helper));
      ReservationInfo *reservation =
          get_reservation_by_reservation_id(reservations_data, reservation_id);
      char *begin_date = date_to_string(get_begin_date(reservation));
      char *end_date = date_to_string(get_end_date(reservation));
      char rating = get_rating(reservation);
      int price_per_night = get_price_per_night(reservation);
      double total_price = calculate_total_price(
          calculate_number_of_nights(begin_date, end_date), price_per_night,
          get_city_tax(reservation));
      char *user_id = get_user_id_reservation(reservation);
      char *id = int_to_reservation_id(reservation_id);
      result_helper->reservation_id = g_strdup(id);
      result_helper->begin_date = g_strdup(begin_date);
      result_helper->end_date = g_strdup(end_date);
      result_helper->user_id = g_strdup(user_id);
      result_helper->rating = rating;
      result_helper->total_price = total_price;
      g_array_append_val(result->query4_result, result_helper);
      j++;
      free(id);
      free(begin_date);
      free(end_date);
      free(user_id);
    }
  }
  int N = j--;

  sort_by_date_and_value(result, N);
  write_query4(has_f, output_file, result->query4_result);

  for (int i = 0; i < N; i++) {
    free(g_array_index(result->query4_result, QUERY4_RESULT_HELPER, i)
             ->reservation_id);
    free(g_array_index(result->query4_result, QUERY4_RESULT_HELPER, i)
             ->begin_date);
    free(g_array_index(result->query4_result, QUERY4_RESULT_HELPER, i)
             ->end_date);
    free(
        g_array_index(result->query4_result, QUERY4_RESULT_HELPER, i)->user_id);
    free(g_array_index(result->query4_result, QUERY4_RESULT_HELPER, i));
  }

  g_array_free(result->query4_result, TRUE);
  free(result);
}
