#ifndef FLIGHTS_H
#define FLIGHTS_H


typedef struct flights *FLIGHTS;

// Creat a new flights
FLIGHTS creat_flight();

// Set flight id
void set_flight_id(FLIGHTS flight ,char *id);

// Set flight airline
void set_flight_airline(FLIGHTS flight, char *airline);

// Set flight planel model
void set_flight_planel_model(FLIGHTS flight ,char *planel_model);

// Set flight total seats
void set_flight_total_seats(FLIGHTS flight ,int total_seats);

// Set flight origin
void set_flight_origin(FLIGHTS flight ,char *origin);

// Set flight schudele departure date (aaaa/MM/dd hh:mm:ss) 
void set_flight_schedule_departure_date(FLIGHTS flight, char *schedule_departure_date);

// Set flight schudele arrival date (aaaa/MM/dd hh:mm:ss) 
void set_flight_schedule_arrival_date(FLIGHTS flight, char *schedule_arrival_date);

// Set flight real departure date (aaaa/MM/dd hh:mm:ss) 
void set_flight_real_departure_date(FLIGHTS flight, char *real_departure_date);

// Set flight real arrival date (aaaa/MM/dd hh:mm:ss) 
void set_flight_real_arrival_date(FLIGHTS flight, char *real_arrival_date);

// Set flight pilot
void set_flight_pilot(FLIGHTS flight, char *pilot);

// Set flight copilot
void set_flight_copilot(FLIGHTS flight, char *copilot);

// Set flight note
void set_flight_note(FLIGHTS flight, char *notes);

// Frees the memory allocated to store flights 
void free_flights(FLIGHTS flights);


#endif
