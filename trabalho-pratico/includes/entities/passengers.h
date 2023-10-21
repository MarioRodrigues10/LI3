#ifndef PASSENGERS_H
#define PASSENGERS_H


typedef struct passengers *PASSENGERS;

// Creat new passengers
PASSENGERS creat_passengers();

// Set the flight id 
void set_passengers_flight_id(PASSENGERS passengers,char *id);

// Set the user id 
void set_passengers_user_id(PASSENGERS passengers, char *id);


#endif