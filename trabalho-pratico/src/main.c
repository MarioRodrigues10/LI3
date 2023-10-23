#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/entities/flights.h"
#include "../includes/entities/passengers.h"
#include "../includes/entities/reservations.h"
#include "../includes/entities/users.h"
#include "../includes/io/parser.h"

int main() {
  parse_file("datasets/dataset/data/users.csv");
  parse_file("datasets/dataset/data/flights.csv");
  parse_file("datasets/dataset/data/passengers.csv");
  parse_file("datasets/dataset/data/reservations.csv");

  return 0;
}
