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

  free(user);
  free(reservation);
  free(flight);
  free(passenger);
  return 0;
}
