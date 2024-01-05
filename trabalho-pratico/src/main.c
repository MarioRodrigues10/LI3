#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

#include "utils/input-handler.h"

int main(int argc, char **argv) {
  // ./programa-principal dataset/data_clean dataset/input.txt
  struct rusage r_usage;
  if (argc != 3) {
    printf("Invalid number of arguments\n");
    return 1;
  } else {
    input_handler(argv);
  }
  getrusage(RUSAGE_SELF, &r_usage);
  printf("Memory usage: %ld KB\n", r_usage.ru_maxrss);
  return 0;
}
