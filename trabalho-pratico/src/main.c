#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/input-handler.h"

int main(int argc, char **argv) {
  // ./programa-principal dataset/data_clean dataset/input.txt

  if (argc != 3) {
    printf("Invalid number of arguments\n");
    return 1;
  } else {
    input_handler(argv);
  }

  return 0;
}