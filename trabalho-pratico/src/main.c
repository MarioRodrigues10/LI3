#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "utils/input_handler.h"

int main(int argc, char **argv) {
  // ./programa-principal dataset/data_clean dataset/input.txt

  struct rusage r_usage;
  getrusage(RUSAGE_SELF, &r_usage);

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

  getrusage(RUSAGE_SELF, &r_usage);
  printf("Memory usage: %ld KB\n", r_usage.ru_maxrss);
  return 0;
}