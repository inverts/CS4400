#include <stdio.h>
#include <assert.h>

struct s3 {
  unsigned long long f0;
  signed char f1;
  long long f2;
  signed char f3;
  unsigned int f4;
  unsigned short f5;
};

struct s3_bitfield {
  unsigned long long f0 : 29;
  signed char f1 : 7;
  long long f2 : 36;
  signed char f3 : 3;
  unsigned int f4 : 7;
  unsigned short f5 : 16;
};

int main() {

  /*struct s3_bitfield s3_packed_3 = {
  .f0 = 0,
  .f1 = 0x16,
  .f2 = 0x271828185LL,
  .f3 = -3,
  .f4 = 0x11,
  .f5 = 0x2685 };*/
struct s3_bitfield s3_packed_4 = {
  .f0 = 0,
  .f1 = 0,
  .f2 = 0,
  .f3 = 0,
  .f4 = 0,
  .f5 = 0 };
struct s3 s3_unpacked_4 = {
  .f0 = 0,
  .f1 = 0,
  .f2 = 0,
  .f3 = 0,
  .f4 = 0,
  .f5 = 0 };

 unsigned long long zero = 0;
 //unsigned long long holder = s3_packed_4.f0;
 //printf("f0: %llx\n", holder);
  printf("f0: %llx\n", s3_packed_4.f0);
  printf("f1: %hhx\n", s3_packed_4.f1);
  printf("f2: %llx\n", s3_packed_4.f2);
  printf("f3: %hhx\n", s3_packed_4.f3);
  printf("f4: %x\n", s3_packed_4.f4);
  printf("f5: %hx\n\n", s3_packed_4.f5);

  printf("f0: %llx\n", s3_unpacked_4.f0);
  printf("f1: %hhx\n", s3_unpacked_4.f1);
  printf("f2: %llx\n", s3_unpacked_4.f2);
  printf("f3: %hhx\n", s3_unpacked_4.f3);
  printf("f4: %x\n", s3_unpacked_4.f4);
  printf("f5: %hx\n", s3_unpacked_4.f5);

  assert(s3_packed_4.f0 == zero);

  assert(s3_packed_4.f0 == s3_unpacked_4.f0);
  printf("\nAssert passed.\n");
}
