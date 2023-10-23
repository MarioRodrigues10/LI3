#include "entities/flight.h"

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct flight {
  gpointer id;
  char *arline;
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

int verifyFlightInput(char **parameters) {
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

Flight createFlight() {
  Flight newflight = gmalloc(sizeof(struct flight));
  newflight->id = NULL;

  return newflights;
}

void setFlightId(Flight flight, char *id) {
  int idint = stringtoint(id);
  gpointer idpointer = GINTTOPOINTER(idint);
  flight->id = idpointer;
}

void setFlightAirline(Flight flight, char *airline) {
  flight->airline = g_strdup(airline);
}

void setFlightPlanelModel(Flight flight, char *planelmodel) {
  flight->planemodel = g_strdup(planelmodel);
}

void setFlightTotalSeats(Flight flight, int totalseats) {
  flight->totalseats = totalseats;
}

void setFlightOrigin(Flight flight, char *origin) {
  flight->origin = g_strdup(origin);
}

void setFlightScheduleDepartureDate(Flight flight,
                                    char *schedule_departure_date) {
  flight->schedule_departure_date = g_strdup(schedule_departure_date);
}

void setFlightScheduleArrivalDate(Flight flight, char *schedule_arrival_date) {
  flight->schedule_arrival_date = g_strdup(schedule_arrival_date);
}

void setFlightRealDepartureDate(Flight flight, char *real_departure_date) {
  flight->real_departure_date = g_strdup(real_departure_date);
}

void setFlightRealArrivalDate(Flight flight, char *real_arrival_date) {
  flight->real_arrival_date = g_strdup(real_arrival_date);
}

void setFlightPilot(Flight flight, char *pilot) {
  flight->pilot = g_strdup(pilot);
}

void setFlightCopilot(Flight flight, char *copilot) {
  flight->copilot = g_strdup(copilot);
}

void setFlightNote(Flight flight, char *notes) {
  flight->notes = g_strdup(notes);
}

void freeFlight(Flight flight) {
  g_free(flight->name);
  g_free(flight->arline);
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

int getFlightId(Flight flight) {
  int id = GPOINTER_TO_INT(flight->id);
  return id;
}

char *getFlightAirline(Flight flight) {
  char *airline = strdup(flight->airline);
  return airline;
}

char *getFlightPlaneModel(Flight flight) {
  char *plane_model = strdup(flight->plane_model);
  return plane_model;
}

int getFlightTotalSeats(Flight flight) {
  int totalseats = flight->totalseats;
  return totalseats;
}

char *getFlightOrigin(Flight flight) {
  char *origin = strdup(flight->origin);
  return origin;
}

char *getFlightScheduleDepartureDate(Flight flight) {
  char *schedule_departure_date = strdup(flight->schedule_departure_date);
  return schedule_departure_date;
}

char *getFlightScheduleArrivalDate(Flight flight) {
  char *schedule_arrival_date = strdup(flight->schedule_arrival_date);
  return schedule_arrival_date;
}

char *getFlightRealDepartureDate(Flight flight) {
  char *real_departure_date = strdup(flight->real_departure_date);
  return real_departure_date;
}

char *getFlightRealArrivalDate(Flight flight) {
  char *real_arrival_date = strdup(flight->real_arrival_date);
  return real_arrival_date;
}

char *getFlightPilot(Flight flight) {
  char *pilot = strdup(flight->pilot);
  return pilot;
}

char *getFlightCopilot(Flight flight) {
  char *copilot = strdup(flight->copilot);
  return copilot;
}

char *getFlightNotes(Flight flight) {
  char *notes = strdup(flight->notes);
  return notes;
}
