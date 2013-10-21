#include <stdio.h>
#include <assert.h>

#include "struct.h"
#include "funcs.h"

int compare_structs_s1(struct s1 a, struct s1 b) {
  return (a.f0 == b.f0) && (a.f1 == b.f1) && (a.f2 == b.f2) && (a.f3 == b.f3) && (a.f4 == b.f4) && (a.f5 == b.f5);
}

struct s1 s1_empty_struct = { .f0 = 0x0, .f1 = 0x0, .f2 = 0x0, .f3 = 0x0, .f4 = 0x0, .f5 = 0x0 };
struct s1 s1_ones_struct = {
    .f0 = 0xff,
    .f1 = 0xffffffffffffffffULL,
    .f2 = 0xff,
    .f3 = 0xffffffffffffffffULL,
    .f4 = 0xffff,
    .f5 = 0xffffffffffffffffULL };
struct s1 sample_struct_1 = {
  .f0 = 0x42,
  .f1 = 0x789,
  .f2 = 0x5f,
  .f3 = 0x3141592653589793ULL,
  .f4 = 0x9912,
  .f5 = 0x0000000001131023ULL };
struct s1 sample_swapped_1 = {
  .f0 = 0x42,
  .f1 = 0x8907000000000000ULL,
  .f2 = 0x5f,
  .f3 = 0x9397585326594131ULL,
  .f4 = 0x1299,
  .f5 = 0x2310130100000000ULL };

void test_endian_swap_s1_shift() {
  printf("Performing test: %s...\n", __func__);

  //Two endian swaps should produce the original.
  assert(compare_structs_s1(sample_struct_1, endian_swap_s1_shift(endian_swap_s1_shift(sample_struct_1)) ));

  //Test against a manually checked correct swap.
  assert(compare_structs_s1(endian_swap_s1_shift(sample_struct_1), sample_swapped_1));

  //Test that a struct with all 0's is the same in either endian.
  assert(compare_structs_s1(endian_swap_s1_shift(s1_empty_struct), s1_empty_struct));

  //Test that a struct with all 1's is the same in either endian.
  assert(compare_structs_s1(endian_swap_s1_shift(s1_ones_struct), s1_ones_struct));

  //Test that the shift and pointer functions perform the same thing
  assert(compare_structs_s1(endian_swap_s1_ptr(sample_struct_1), endian_swap_s1_ptr(sample_struct_1)));

  printf("Test passed.\n\n");
}

void test_endian_swap_s1_ptr() {
  printf("Performing test: %s...\n", __func__);

  //Two endian swaps should produce the original.
  assert(compare_structs_s1(sample_struct_1, endian_swap_s1_ptr(endian_swap_s1_ptr(sample_struct_1)) ));

  //Test against a manually checked correct swap.
  assert(compare_structs_s1(endian_swap_s1_ptr(sample_struct_1), sample_swapped_1));

  //Test that a struct with all 0's is the same in either endian.
  assert(compare_structs_s1(endian_swap_s1_ptr(s1_empty_struct), s1_empty_struct));

  //Test that a struct with all 1's is the same in either endian.
  assert(compare_structs_s1(endian_swap_s1_ptr(s1_ones_struct), s1_ones_struct));

  //Test that the shift and pointer functions perform the same thing
  assert(compare_structs_s1(endian_swap_s1_ptr(sample_struct_1), endian_swap_s1_ptr(sample_struct_1)));

  printf("Test passed.\n\n");
}



//------------------------------S2-TESTING---------------------------------


struct s2 s2_sample_1 = {
  .f0 = 0x0,
  .f1 = 0x0,
  .f2 = 0x0,
  .f3 = 0x0,
  .f4 = 0x0,
  .f5 = 0x0 };

struct s2 s2_sample_2 = {
  .f0 = 0x31415926,
  .f1 = 0x27182818,
  .f2 = 0x16180339,
  .f3 = 0x12020569,
  .f4 = 0x1123581321345589ULL,
  .f5 = 0x26854520 };

struct s2 s2_sample_3 = {
  .f0 = 0xffffffff,
  .f1 = 0xffffffff,
  .f2 = 0xffffffff,
  .f3 = 0xffffffff,
  .f4 = 0xffffffffffffffffULL,
  .f5 = 0xffffffff };


struct s2_packed s2_packed_1 = {
  .f0 = 0x0,
  .f1 = 0x0,
  .f2 = 0x0,
  .f3 = 0x0,
  .f4 = 0x0,
  .f5 = 0x0 };
struct s2_packed s2_packed_2 = {
  .f0 = 0x31415926,
  .f1 = 0x27182818,
  .f2 = 0x16180339,
  .f3 = 0x12020569,
  .f4 = 0x1123581321345589ULL,
  .f5 = 0x26854520 };
struct s2_packed s2_packed_3 = {
  .f0 = 0xffffffff,
  .f1 = 0xffffffff,
  .f2 = 0xffffffff,
  .f3 = 0xffffffff,
  .f4 = 0xffffffffffffffffULL,
  .f5 = 0xffffffff };

int compare_structs_s2_packed(struct s2_packed a, struct s2_packed b) {
  return (a.f0 == b.f0) && (a.f1 == b.f1) && (a.f2 == b.f2) && (a.f3 == b.f3) && (a.f4 == b.f4) && (a.f5 == b.f5);
}

int compare_structs_s2(struct s2 a, struct s2 b) {
  return (a.f0 == b.f0) && (a.f1 == b.f1) && (a.f2 == b.f2) && (a.f3 == b.f3) && (a.f4 == b.f4) && (a.f5 == b.f5);
}

void test_pack_and_unpack_s2() {
  printf("Performing test: %s...\n", __func__);

  struct s2_packed result_1;
  struct s2_packed result_2;
  struct s2_packed result_3;

  // Pack the samples into the results
  pack_s2((char *) &result_1, (char *) &s2_sample_1); 
  pack_s2((char *) &result_2, (char *) &s2_sample_2); 
  pack_s2((char *) &result_3, (char *) &s2_sample_3); 

  assert(compare_structs_s2_packed(result_1, s2_packed_1));
  assert(compare_structs_s2_packed(result_2, s2_packed_2));
  assert(compare_structs_s2_packed(result_3, s2_packed_3));

  struct s2 unpacked_1;
  struct s2 unpacked_2;
  struct s2 unpacked_3;

  // Unpack the results into new structs
  unpack_S2((char *) &unpacked_1, (char *) &result_1);
  unpack_S2((char *) &unpacked_2, (char *) &result_2);
  unpack_S2((char *) &unpacked_3, (char *) &result_3);

  assert(compare_structs_s2(unpacked_1, s2_sample_1));
  assert(compare_structs_s2(unpacked_2, s2_sample_2));
  assert(compare_structs_s2(unpacked_3, s2_sample_3));

  printf("Test passed.\n\n");
}



//------------------------------S3-TESTING---------------------------------


struct s3 s3_sample_1 = { .f0 = 0x0,  .f1 = 0x0,  .f2 = 0x0,  .f3 = 0x0,  .f4 = 0x0,  .f5 = 0x0 };
struct s3 s3_sample_2 = {
  .f0 = 0x3141592653589793ULL,
  .f1 = 0x16,
  .f2 = 0x2718281828459045LL,
  .f3 = 0x12,
  .f4 = 0x11235813,
  .f5 = 0x2685 };
struct s3 s3_sample_3 = {
  .f0 = 0x1fffffff, 
  .f1 = 0x7f, 
  .f2 = 0xfffffffffLL,
  .f3 = 0x7,
  .f4 = 0x7f,
  .f5 = 0xffff };
struct s3 s3_sample_4 = {
  .f0 = 0x3141592,
  .f1 = 0x16,
  .f2 = 0x271828185LL,
  .f3 = 0x5,
  .f4 = 0x11,
  .f5 = 0x2685 };

struct s3_bitfield s3_packed_1 = { .f0 = 0x0,  .f1 = 0x0,  .f2 = 0x0,  .f3 = 0x0,  .f4 = 0x0,  .f5 = 0x0 };
// s3_sample_2 cannot be packed without data loss.
struct s3_bitfield s3_packed_3 = {
  .f0 = 0x1fffffff, 
  .f1 = -1, 
  .f2 = -1,
  .f3 = -1,
  .f4 = 0x7f,
  .f5 = 0xffff };
struct s3_bitfield s3_packed_4 = {
  .f0 = 0x3141592,
  .f1 = 0x16,
  .f2 = 0x271828185LL,
  .f3 = -3,
  .f4 = 0x11,
  .f5 = 0x2685 };

int compare_structs_s3_packed(struct s3_bitfield a, struct s3_bitfield b) {
  return (a.f0 == b.f0) && (a.f1 == b.f1) && (a.f2 == b.f2) && (a.f3 == b.f3) && (a.f4 == b.f4) && (a.f5 == b.f5);
}

int compare_structs_s3(struct s3 a, struct s3 b) {
  return (a.f0 == b.f0) && (a.f1 == b.f1) && (a.f2 == b.f2) && (a.f3 == b.f3) && (a.f4 == b.f4) && (a.f5 == b.f5);
}

void test_pack_and_unpack_s3() {
  printf("Performing test: %s...\n", __func__);

  struct s3_bitfield result_1;
  struct s3_bitfield result_2;
  struct s3_bitfield result_3;
  struct s3_bitfield result_4;

  //Pack first set of samples.
  assert(pack_s3((char *) &result_1, (char *) &s3_sample_1) == 0); //Can be packed
  assert(pack_s3((char *) &result_2, (char *) &s3_sample_2) == -1); //Cannot be packed
  assert(pack_s3((char *) &result_3, (char *) &s3_sample_3) == 0); //Can be packed
  assert(pack_s3((char *) &result_4, (char *) &s3_sample_4) == 0); //Can be packed

  //Are the packed results correct?
  assert(compare_structs_s3_packed(result_1, s3_packed_1));
  assert(compare_structs_s3_packed(result_3, s3_packed_3));
  assert(compare_structs_s3_packed(result_4, s3_packed_4));

  struct s3 unpacked_1;
  struct s3 unpacked_3;
  struct s3 unpacked_4;

  //Now, unpack the packed set of samples.
  unpack_s3((char *) &unpacked_1, (char *) &result_1);
  unpack_s3((char *) &unpacked_3, (char *) &result_3);
  unpack_s3((char *) &unpacked_4, (char *) &result_4);

  //Are the unpacked results correct?
  assert(compare_structs_s3(unpacked_1, s3_sample_1));
  assert(compare_structs_s3(unpacked_3, s3_sample_3));
  assert(compare_structs_s3(unpacked_4, s3_sample_4));

  printf("Test passed.\n\n");
}

int main (void)
{
  test_endian_swap_s1_shift();
  test_endian_swap_s1_ptr();
  test_pack_and_unpack_s2();
  test_pack_and_unpack_s3();

  return 0;
}
