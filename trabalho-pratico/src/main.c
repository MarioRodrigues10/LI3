#include "utils/input_handler.h"

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