#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base/batch.h"
#include "entities/flights.h"
#include "entities/passengers.h"
#include "entities/reservations.h"
#include "entities/users.h"
#include "io/parser.h"

int main(int argc, char **argv) {
  // ./programa-principal Dataset/dataset/data_clean/ Dataset/dataset/input.txt
  if (argc == 3) {
    batch(argv);
  }
}
