#include "entities/flights.h"

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/utils.h"

struct flight {
  gpointer id;
  char *airline;
  char *plane_model;
  int total_seats;
  char *origin;
  char *destination;
  char *schedule_departure_date;
  char *schedule_arrival_date;
  char *real_departure_date;
  char *real_arrival_date;
  char *pilot;
  char *copilot;
  char *notes;
};

int verify_flight_input(char **parameters) {
  if (!parameters[0]) return 0;
  if (!parameters[1]) return 0;
  if (!parameters[2]) return 0;
  if (!parameters[3]) return 0;
  if (!parameters[4]) return 0;
  if (!parameters[5]) return 0;
  if (!parameters[6]) return 0;
  if (!parameters[7]) return 0;
  if (!parameters[8]) return 0;
  if (!parameters[9]) return 0;
  if (!parameters[10]) return 0;
  if (!parameters[11]) return 0;
  if (!parameters[12]) return 0;

  return 1;
}

FLIGHT create_flight() {
  FLIGHT newflight = g_malloc(sizeof(struct flight));

  return newflight;
}

void build_flight(char **flight_params, void *catalog) {
  if (!verify_flight_input(flight_params)) return;

  FLIGHT flight = create_flight();
  FLIGHTS_CATALOG flights_catalog = (FLIGHTS_CATALOG)catalog;

  set_flight_id(flight, flight_params[0]);
  set_flight_airline(flight, flight_params[1]);
  set_flight_planel_model(flight, flight_params[2]);
  set_flight_total_seats(flight, string_to_int(flight_params[3]));
  set_flight_origin(flight, flight_params[4]);
  set_flight_destination(flight, flight_params[5]);
  set_flight_schedule_departure_date(flight, flight_params[5]);
  set_flight_schedule_arrival_date(flight, flight_params[6]);
  set_flight_real_departure_date(flight, flight_params[7]);
  set_flight_real_arrival_date(flight, flight_params[8]);
  set_flight_pilot(flight, flight_params[9]);
  set_flight_copilot(flight, flight_params[10]);
  set_flight_notes(flight, flight_params[11]);

  add_flight_to_catalog(flights_catalog, flight, flight->id);
}

void set_flight_id(FLIGHT flight, char *flight_id) {
  gpointer id_pointer = GINT_TO_POINTER(string_to_int(flight_id));
  flight->id = id_pointer;
}

void set_flight_airline(FLIGHT flight, char *airline) {
  flight->airline = g_strdup(airline);
}

void set_flight_planel_model(FLIGHT flight, char *planelmodel) {
  flight->plane_model = g_strdup(planelmodel);
}

void set_flight_total_seats(FLIGHT flight, int totalseats) {
  flight->total_seats = totalseats;
}

void set_flight_origin(FLIGHT flight, char *origin) {
  flight->origin = g_strdup(origin);
}

void set_flight_destination(FLIGHT flight, char *destination) {
  flight->destination = g_strdup(destination);
}

void set_flight_schedule_departure_date(FLIGHT flight,
                                        char *schedule_departure_date) {
  flight->schedule_departure_date = g_strdup(schedule_departure_date);
}

void set_flight_schedule_arrival_date(FLIGHT flight,
                                      char *schedule_arrival_date) {
  flight->schedule_arrival_date = g_strdup(schedule_arrival_date);
}

void set_flight_real_departure_date(FLIGHT flight, char *real_departure_date) {
  flight->real_departure_date = g_strdup(real_departure_date);
}

void set_flight_real_arrival_date(FLIGHT flight, char *real_arrival_date) {
  flight->real_arrival_date = g_strdup(real_arrival_date);
}

void set_flight_pilot(FLIGHT flight, char *pilot) {
  flight->pilot = g_strdup(pilot);
}

void set_flight_copilot(FLIGHT flight, char *copilot) {
  flight->copilot = g_strdup(copilot);
}

void set_flight_notes(FLIGHT flight, char *notes) {
  flight->notes = g_strdup(notes);
}

void free_flight(FLIGHT flight) {
  g_free(flight->id);
  g_free(flight->airline);
  g_free(flight->plane_model);
  g_free(flight->origin);
  g_free(flight->schedule_departure_date);
  g_free(flight->schedule_arrival_date);
  g_free(flight->real_departure_date);
  g_free(flight->real_arrival_date);
  g_free(flight->pilot);
  g_free(flight->copilot);
  g_free(flight->notes);
}

int get_flight_Id(FLIGHT flight) {
  int id = GPOINTER_TO_INT(flight->id);
  return id;
}

char *get_flight_airline(FLIGHT flight) {
  char *airline = g_strdup(flight->airline);
  return airline;
}

char *get_flight_plane_model(FLIGHT flight) {
  char *plane_model = g_strdup(flight->plane_model);
  return plane_model;
}

int get_flight_total_seats(FLIGHT flight) {
  int totalseats = flight->total_seats;
  return totalseats;
}

char *get_flight_origin(FLIGHT flight) {
  char *origin = g_strdup(flight->origin);
  return origin;
}

char *get_flight_destination(FLIGHT flight) {
  char *destination = g_strdup(flight->destination);
  return destination;
}

char *get_flight_schedule_departure_date(FLIGHT flight) {
  char *schedule_departure_date = g_strdup(flight->schedule_departure_date);
  return schedule_departure_date;
}

char *get_flight_schedule_arrival_date(FLIGHT flight) {
  char *schedule_arrival_date = g_strdup(flight->schedule_arrival_date);
  return schedule_arrival_date;
}

char *get_flight_real_departure_date(FLIGHT flight) {
  char *real_departure_date = g_strdup(flight->real_departure_date);
  return real_departure_date;
}

char *get_flight_real_arrival_date(FLIGHT flight) {
  char *real_arrival_date = g_strdup(flight->real_arrival_date);
  return real_arrival_date;
}

char *get_flight_pilot(FLIGHT flight) {
  char *pilot = g_strdup(flight->pilot);
  return pilot;
}

char *get_flight_copilot(FLIGHT flight) {
  char *copilot = g_strdup(flight->copilot);
  return copilot;
}

char *get_flight_notes(FLIGHT flight) {
  char *notes = g_strdup(flight->notes);
  return notes;
}
