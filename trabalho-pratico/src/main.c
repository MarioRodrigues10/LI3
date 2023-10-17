#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/parser.h"

int main() {
  Flight* flight = parse_flights("datasets/dataset/data/flights_errors.csv");
  Passenger* passenger =
      parse_passengers("datasets/dataset/data/passengers_errors.csv");
  Reservation* reservation =
      parse_reservations("datasets/dataset/data/reservations.csv");
  User* user = parse_users("datasets/dataset/data/users.csv");

  // This is to test purposes, will be removed after the parser is done and
  // working correctly

  // while (passenger != NULL) {
  //   printf("Flight ID: %lld\n", passenger->flight_id);
  //   printf("User ID: %s\n\n", passenger->user_id);
  //   passenger = passenger->next;
  // }

  // while (flight != NULL) {
  //   printf("ID: %lld\n", flight->id);
  //   printf("Airline: %s\n", flight->airline);
  //   printf("Plane Model: %s\n", flight->plane_model);
  //   printf("Total Seats: %d\n", flight->total_seats);
  //   printf("Origin: %s\n", flight->origin);
  //   printf("Destination: %s\n", flight->destination);
  //   printf("Schedule Departure Date: %s\n", flight->schedule_departure_date);
  //   printf("Schedule Arrival Date: %s\n", flight->schedule_arrival_date);
  //   printf("Real Departure Date: %s\n", flight->real_departure_date);
  //   printf("Real Arrival Date: %s\n", flight->real_arrival_date);
  //   printf("Pilot: %s\n", flight->pilot);
  //   printf("Copilot: %s\n", flight->copilot);
  //   printf("Notes: %s\n\n", flight->notes);
  //   flight = flight->next;
  // }

  // while (reservation != NULL) {
  //   printf("ID: %s\n", reservation->id);
  //   printf("User ID: %s\n", reservation->user_id);
  //   printf("Hotel ID: %s\n", reservation->hotel_id);
  //   printf("Hotel Name: %s\n", reservation->hotel_name);
  //   printf("Hotel Stars: %d\n", reservation->hotel_stars);
  //   printf("City Tax: %lf\n", reservation->city_tax);
  //   printf("Address: %s\n", reservation->address);
  //   printf("Begin Date: %s\n", reservation->begin_date);
  //   printf("End Date: %s\n", reservation->end_date);
  //   printf("Price Per Night: %d\n", reservation->price_per_night);
  //   printf("Includes Breakfast: %d\n", reservation->includes_breakfast);
  //   printf("Room Details: %s\n", reservation->room_details);
  //   printf("Rating: %d\n", reservation->rating);
  //   printf("Comment: %s\n\n", reservation->comment);
  //   reservation = reservation->next;
  // }

  while (user != NULL) {
    printf("ID: %s\n", user->id);
    printf("Name: %s\n", user->name);
    printf("Email: %s\n", user->email);
    printf("Phone Number: %s\n", user->phone_number);
    printf("Birth Date: %s\n", user->birth_date);
    printf("Sex: %s\n", user->sex);
    printf("Passport: %s\n", user->passport);
    printf("Country Code: %s\n", user->country_code);
    printf("Address: %s\n", user->address);
    printf("Account Creation: %s\n", user->account_creation);
    printf("Pay Method: %s\n", user->pay_method);
    printf("Account Status: %s\n\n", user->account_status);
    user = user->next;
  }

  free(user);
  free(reservation);
  free(flight);
  free(passenger);
  return 0;
}
