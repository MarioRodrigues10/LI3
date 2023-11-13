#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base/batch.h"

int main(int argc, char **argv) {
  // ./programa-principal Dataset/dataset/data_clean/ Dataset/dataset/input.txt
  if (argc == 3) {
    batch(argv);
  }
}
