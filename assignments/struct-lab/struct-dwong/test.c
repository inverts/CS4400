#include <stdio.h>

#include "struct.h"

int main() {
  unsigned long long sample;
  printf("size of unsigned long long: %d bytes\n", sizeof(sample));
  signed long long sample2;
  printf("size of signed long long: %d bytes\n", sizeof(sample2));
  sample = 0x3141592653589793;
    struct s1 sample_struct_1 = {
    .f0 = 0x42,
    .f1 = 0x789,
    .f2 = 0x5f,
    .f3 = 0x3141592653589793ULL,
    .f4 = 0x9912,
    .f5 = 0x0000000001131023 };
}
