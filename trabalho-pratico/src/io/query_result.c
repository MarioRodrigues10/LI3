#include "io/query_result.h"

#include <glib.h>
#include <stdlib.h>

#include "base/query_manager.h"
#include "catalogs/flights_catalog.h"
#include "catalogs/passengers_catalog.h"
#include "catalogs/reservations_catalog.h"
#include "catalogs/users_catalog.h"
#include "utils/utils.h"

void write_query_result(FILE *output_file, void *result, char query_type) {
  if (result == NULL) {
    return;
  }

  static file_output_function_pointer table[] = {
      write_query1_result, write_query2_result, write_query3_result,
      write_query4_result, write_query5_result, write_query6_result,
      write_query7_result, write_query8_result, write_query9_result,
      write_query10_result};

  table[query_type - '1'](output_file, result);
}

struct query1_result {
  char *hotel_id;
  char *hotel_name;
  int hotel_stars;
  char *begin_date;
  char *end_date;
  char *includes_breakfast;
  int number_of_nights;
  double total_price;

  char *airline_company;
  char *plane_model;
  char *origin;
  char *destination;
  char *schedule_departure_date;
  char *schedule_arrival_date;
  int passengers;
  int delay;

  char *name;
  char *sex;
  char *age;
  char *country_code;
  char *passport;
  int number_of_flights;
  int number_of_reservations;
  double total_spent;

  char *type;

  bool has_f;
};

void write_query1_result(FILE *output_file, void *result) {
  QUERY1_RESULT query_result = (QUERY1_RESULT)result;

  if (strcmp(query_result->type, "RESERVATION") == 0) {
    if (!query_result->has_f) {
      fprintf(output_file, "%s;%s;%d;%s;%s;%s;%d;%.3f\n",
              query_result->hotel_id, query_result->hotel_name,
              query_result->hotel_stars, query_result->begin_date,
              query_result->end_date, query_result->includes_breakfast,
              query_result->number_of_nights, query_result->total_price);
    } else {
      fprintf(output_file,
              "--- 1 ---\nhotel_id: %s\nhotel_name: %s\nhotel_stars: "
              "%d\nbegin_date: %s\nend_date: %s\nincludes_breakfast: "
              "%s\nnights: %d\ntotal_price: %.3f\n",
              query_result->hotel_id, query_result->hotel_name,
              query_result->hotel_stars, query_result->begin_date,
              query_result->end_date, query_result->includes_breakfast,
              query_result->number_of_nights, query_result->total_price);
    }
  }

  if (strcmp(query_result->type, "FLIGHT") == 0) {
    if (!query_result->has_f) {
      fprintf(output_file, "%s;%s;%s;%s;%s;%s;%d;%d\n",
              query_result->airline_company, query_result->plane_model,
              query_result->origin, query_result->destination,
              query_result->schedule_departure_date,
              query_result->schedule_arrival_date, query_result->passengers,
              query_result->delay);
    } else {
      fprintf(output_file,
              "--- 1 ---\nairline: %s\nplane_model: %s\norigin: "
              "%s\ndestination: %s\nschedule_departure_date: "
              "%s\nschedule_arrival_date: %s\npassengers: %d\ndelay: %d\n",
              query_result->airline_company, query_result->plane_model,
              query_result->origin, query_result->destination,
              query_result->schedule_departure_date,
              query_result->schedule_arrival_date, query_result->passengers,
              query_result->delay);
    }
  }

  if (strcmp(query_result->type, "USER") == 0) {
    if (!query_result->has_f) {
      fprintf(output_file, "%s;%s;%s;%s;%s;%d;%d;%.3f\n", query_result->name,
              query_result->sex, query_result->age, query_result->country_code,
              query_result->passport, query_result->number_of_flights,
              query_result->number_of_reservations, query_result->total_spent);
    } else {
      fprintf(output_file,
              "--- 1 ---\nname: %s\nsex: %s\nage: %s\ncountry_code: "
              "%s\npassport: %s\nnumber_of_flights: "
              "%d\nnumber_of_reservations: %d\ntotal_spent: %.3f\n",
              query_result->name, query_result->sex, query_result->age,
              query_result->country_code, query_result->passport,
              query_result->number_of_flights,
              query_result->number_of_reservations, query_result->total_spent);
    }
  }
}

void write_query2_result(FILE *output_file, void *result) { return; }

struct query3_result {
  double media_of_ratings;
  bool has_f;
};

void write_query3_result(FILE *output_file, void *result) {
  QUERY3_RESULT query_result = (QUERY3_RESULT)result;

  if (query_result->has_f) {
    fprintf(output_file, "--- 1 ---\nrating: %.3f\n",
            query_result->media_of_ratings);
  } else {
    fprintf(output_file, "%.3f\n", query_result->media_of_ratings);
  }
}

void write_query4_result(FILE *output_file, void *result) { return; }

void write_query5_result(FILE *output_file, void *result) { return; }

void write_query6_result(FILE *output_file, void *result) { return; }

void write_query7_result(FILE *output_file, void *result) { return; }

void write_query8_result(FILE *output_file, void *result) { return; }

void write_query9_result(FILE *output_file, void *result) { return; }

void write_query10_result(FILE *output_file, void *result) { return; }