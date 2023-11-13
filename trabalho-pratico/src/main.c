#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base/batch.h"

int main(int argc, char **argv) {
  // ./programa-principal dataset/data_clean dataset/input.txt
  if (argc == 3) {
    batch(argv);
  }
}