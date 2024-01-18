#include "models/flight.h"

#include <glib.h>

struct flight {
  char *origin;
  char *destination;
  char *schedule_departure_date;
  char *schedule_arrival_date;
  char *real_departure_date;
  int flight_id;
  short int total_seats;
  char airline;
  char plane_model;
};

// CREATE

FlightInfo *create_flight() {
  FlightInfo *flight = g_malloc(sizeof(FlightInfo));

  return flight;
}

// SETTERS

void set_flight_id(FlightInfo *flight, int flight_id) {
  flight->flight_id = flight_id;
}

void set_airline(FlightInfo *flight, char airline) {
  flight->airline = airline;
}

void set_plane_model(FlightInfo *flight, char plane_model) {
  flight->plane_model = plane_model;
}

void set_total_seats(FlightInfo *flight, short int total_seats) {
  flight->total_seats = total_seats;
}

void set_origin(FlightInfo *flight, char *origin) {
  flight->origin = g_strdup(origin);
}

void set_destination(FlightInfo *flight, char *destination) {
  flight->destination = g_strdup(destination);
}

void set_schedule_departure_date(FlightInfo *flight,
                                 char *schedule_departure_date) {
  flight->schedule_departure_date = g_strdup(schedule_departure_date);
}

void set_schedule_arrival_date(FlightInfo *flight,
                               char *schedule_arrival_date) {
  flight->schedule_arrival_date = g_strdup(schedule_arrival_date);
}

void set_real_departure_date(FlightInfo *flight, char *real_departure_date) {
  flight->real_departure_date = g_strdup(real_departure_date);
}

// GETTERS

int get_flight_id(FlightInfo *flight) {
  int flight_id = flight->flight_id;
  return flight_id;
}

char get_airline(FlightInfo *flight) {
  char airline = flight->airline;
  return airline;
}

char get_plane_model(FlightInfo *flight) {
  char plane_model = flight->plane_model;
  return plane_model;
}

short int get_total_seats(FlightInfo *flight) {
  short int total_seats = flight->total_seats;
  return total_seats;
}

char *get_origin(FlightInfo *flight) {
  char *origin = g_strdup(flight->origin);
  return origin;
}

char *get_destination(FlightInfo *flight) {
  char *destination = g_strdup(flight->destination);
  return destination;
}

char *get_schedule_departure_date(FlightInfo *flight) {
  char *schedule_departure_date = g_strdup(flight->schedule_departure_date);
  return schedule_departure_date;
}

char *get_schedule_arrival_date(FlightInfo *flight) {
  char *schedule_arrival_date = g_strdup(flight->schedule_arrival_date);
  return schedule_arrival_date;
}

char *get_real_departure_date(FlightInfo *flight) {
  char *real_departure_date = g_strdup(flight->real_departure_date);
  return real_departure_date;
}

// DESTROYER

void destroy_flight(FlightInfo *flight) {
  g_free(flight->origin);
  g_free(flight->destination);
  g_free(flight->schedule_departure_date);
  g_free(flight->schedule_arrival_date);
  g_free(flight->real_departure_date);
  g_free(flight);
}
