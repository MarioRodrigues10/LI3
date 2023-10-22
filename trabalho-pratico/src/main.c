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
  parseFile("datasets/dataset/data/users_errors.csv");
  parseFile("datasets/dataset/data/flights.csv");
  parseFile("datasets/dataset/data/passengers.csv");
  parseFile("datasets/dataset/data/reservations.csv");

  return 0;
}
