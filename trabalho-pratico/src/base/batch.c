#include <stdio.h>
#include <stdlib.h>

#include "../includes/utils/utils.h"

int batch(char **argv) {
  // Create catalogs

  // pass catalog as an argument
  if (setup_catalogs(argv[1]) == -1) {
    printf("Error creating catalogs\n");
    return 1;
  }

  return 0;
}