#include "utils/output-handler.h"

#include <stdbool.h>
#include <stdio.h>

void write_query1_for_reservation(bool has_f, FILE *output_file, char *hotel_id,
                                  char *hotel_name, int hotel_stars,
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
                           char *age, char *country_code, char *passport,
                           int number_of_flights, int number_of_reservations,
                           double total_spent) {
  if (has_f) {
    fprintf(output_file,
            "--- 1 ---\nname: %s\nsex: %s\nage: %s\ncountry_code: "
            "%s\npassport: %s\nnumber_of_flights: "
            "%d\nnumber_of_reservations: %d\ntotal_spent: %.3f\n",
            name, sex, age, country_code, passport, number_of_flights,
            number_of_reservations, total_spent);
  } else {
    fprintf(output_file, "%s;%s;%s;%s;%s;%d;%d;%.3f\n", name, sex, age,
            country_code, passport, number_of_flights, number_of_reservations,
            total_spent);
  }
}

void write_query2(bool has_f, FILE *output_file, char **ids, char **dates,
                  char **types, int N) {
  int j;
  for (int i = 0; i < N; i++) {
    j = i + 1;
    if (types[i] == NULL) {
      if (has_f) {
        if (i != 0) fprintf(output_file, "\n");
        fprintf(output_file, "--- %d ---\nid: %s\ndate: %s\n", j, ids[i],
                dates[i]);
      } else {
        fprintf(output_file, "%s;%s\n", ids[i], dates[i]);
      }
    } else {
      if (has_f) {
        if (i != 0) fprintf(output_file, "\n");
        fprintf(output_file, "--- %d ---\nid: %s\ndate: %s\ntype: %s\n", j,
                ids[i], dates[i], types[i]);
      } else {
        fprintf(output_file, "%s;%s;%s\n", ids[i], dates[i], types[i]);
      }
    }
  }
}

void write_query3(bool has_f, FILE *output_file, double media_of_ratings) {
  if (has_f) {
    fprintf(output_file, "--- 1 ---\nrating: %.3f\n", media_of_ratings);
  } else {
    fprintf(output_file, "%.3f\n", media_of_ratings);
  }
}

struct query4_result {
  char **reservation_id;
  char **begin_date;
  char **end_date;
  char **user_id;
  int *rating;
  float *total_price;
  int iterator;
};
void write_query4(bool has_f, FILE *output_file, QUERY4_RESULT query_result) {
  int j;
  for (int i = 0; i < query_result->iterator; i++) {
    j = i + 1;
    if (has_f) {
      if (i != 0) fprintf(output_file, "\n");
      fprintf(output_file,
              "--- %d ---\nid: %s\nbegin_date: %s\nend_date: "
              "%s\nuser_id: %s\nrating: %d\ntotal_price: %.3f\n",
              j, query_result->reservation_id[i], query_result->begin_date[i],
              query_result->end_date[i], query_result->user_id[i],
              query_result->rating[i], query_result->total_price[i]);
    } else {
      fprintf(output_file, "%s;%s;%s;%s;%d;%.3f\n",
              query_result->reservation_id[i], query_result->begin_date[i],
              query_result->end_date[i], query_result->user_id[i],
              query_result->rating[i], query_result->total_price[i]);
    }
  }
}

void write_query8(bool has_f, FILE *output_file, double revenue) {
  if (has_f) {
    fprintf(output_file, "--- 1 ---\nrevenue: %.f\n", revenue);
  } else {
    fprintf(output_file, "%.f\n", revenue);
  }
}

void write_query9(bool has_f, FILE *output_file, char **user_ids,
                  char **user_names, int N) {
  if (has_f) {
    for (int i = 0; i < N; i++) {
      if (i != 0) fprintf(output_file, "\n");
      fprintf(output_file, "--- %d ---\nid: %s\nname: %s\n", i + 1, user_ids[i],
              user_names[i]);
    }
  } else {
    for (int i = 0; i < N; i++) {
      fprintf(output_file, "%s;%s\n", user_ids[i], user_names[i]);
    }
  }
}