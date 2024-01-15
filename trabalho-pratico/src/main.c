
#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

#include "utils/input-handler.h"

int main(int argc, char **argv) {
  // ./programa-principal dataset/data_clean dataset/input.txt

  if (argc == 3) {
    printf("== (Batch Mode) ==\n");
    batch(argv);
  } else if (argc == 1) {
    printf("== (Interactive Mode) ==\n");
    interactive();
  } else {
    printf("Invalid number of arguments\n");
    return 1;
  }

  return 0;
}