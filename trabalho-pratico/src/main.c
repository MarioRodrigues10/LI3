#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/entities/flights.h"
#include "../includes/entities/passengers.h"
#include "../includes/entities/reservations.h"
#include "../includes/entities/users.h"
#include "../includes/parser.h"

int main() {
  parse_file("datasets/dataset/data/users_errors.csv", 12);
  parse_file("datasets/dataset/data/flights.csv", 12);
  parse_file("datasets/dataset/data/passengers.csv", 2);
  parse_file("datasets/dataset/data/reservations.csv", 13);

  return 0;
}
