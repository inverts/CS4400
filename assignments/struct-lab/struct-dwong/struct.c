#include "struct.h"
#include "funcs.h"
#include <stdio.h>

/* your six struct manipulation functions go here */

/*
 * Mimics the C memcpy function.
 */
void * memcpy_1(void * dest, const void * src, unsigned num_bytes) {
  int i;
  unsigned char * dest_cpy = (unsigned char *) dest;
  unsigned char * src_cpy = (unsigned char *) src;
  for (i=0; i < num_bytes; i++) {
    dest_cpy[i] = src_cpy[i];
  }
  return (void *) dest;
}

/*
 * Switches/toggles the endianess of an unsigned long long.
 */
unsigned long long switch_endian(unsigned long long orig_ll) {
  int i;
  unsigned long long new_ll = 0;
  //Basically doing an insertion sort for a reverse order.
  for (i=0; i<8; i++) {
    new_ll = (new_ll << 8) | ((orig_ll >> (i*8)) & 0xff);
    //printf("new_ll: %llx \n", new_ll);
  }
  return new_ll; 
}

/*
 * Switches/toggles the endianess of a signed long long.
 */
signed long long switch_endian_signed(signed long long orig_ll) {
  int i;
  signed long long new_ll = 0;
  //Basically doing an insertion sort for a reverse order.
  for (i=0; i<8; i++) {
    new_ll = (((unsigned long long)new_ll) << 8) | ((orig_ll >> (i*8)) & 0xff);
    //printf("new_ll: %llx \n", new_ll);
  }
  return new_ll; 
}

/*
 * return a struct containing the same values as the argument struct
 * except that each field has its byte order reversed
 *
0 * RESTRICTION: this function must not use arrays or pointers at all;
 * accomplish the byte swapping using shift operators
 */
struct s1 endian_swap_s1_shift (struct s1 input) {
  static const struct s1 empty_s1;
  struct s1 output = empty_s1;
  output.f0 = input.f0;
  output.f1 = switch_endian(input.f1); 
  output.f2 = input.f2;
  output.f3 = switch_endian(input.f3);
  output.f4 = ((input.f4 >> 8) & 0x00ff) | (((unsigned int)(input.f4)) << 8 ); //Avoid negative left shifts.
  /* One way of doing it, but requires using arrays (in the memcpy_1 function)
  unsigned long long u_new_ll;
  memcpy_1(&u_new_ll, &input.f5, sizeof(u_new_ll)); //Convert to unsigned
  u_new_ll = switch_endian(u_new_ll); 
  long long new_ll;
  memcpy_1(&new_ll, &u_new_ll, sizeof(new_ll)); //Convert back to signed
  output.f5 = new_ll;
  */
  output.f5 = switch_endian_signed(input.f5);
  return output;
}


unsigned long long switch_endian_using_ptrs_ll(unsigned long long orig_ll) {
  int i;
  unsigned long long new_ll = 0;
  for(i=0; i<8; i++) {
    *(((unsigned char *)&new_ll) + (7-i)) = *(((unsigned char *)&orig_ll) + i);
  }
  return new_ll; 
}

signed long long switch_endian_using_ptrs_sll(signed long long orig_ll) {
  int i;
  signed long long new_ll = 0;
  for(i=0; i<8; i++) {
    *(((unsigned char *)&new_ll) + (7-i)) = *(((unsigned char *)&orig_ll) + i);
  }
  return new_ll; 
}

short switch_endian_using_ptrs_s(short orig_s) {
  short new_s = 0;
  *(((unsigned char *)&new_s) + (1)) = *(((unsigned char *)&orig_s) + 0);
  *(((unsigned char *)&new_s) + (0)) = *(((unsigned char *)&orig_s) + 1);
  return new_s; 
}

/*
 * return a struct containing the same values as the argument struct
 * except that each field has its byte order reversed
 *bcccc
 * RESTRICTION: this function must not use shift operators;
 * accomplish the byte swapping using pointers and/or arrays
 */
struct s1 endian_swap_s1_ptr (struct s1 input) {
  static const struct s1 empty_s1;
  struct s1 output = empty_s1;
  output.f0 = input.f0;
  output.f1 = switch_endian_using_ptrs_ll(input.f1);
  output.f2 = input.f2;
  output.f3 = switch_endian_using_ptrs_ll(input.f3);
  output.f4 = switch_endian_using_ptrs_s(input.f4);
  output.f5 = switch_endian_using_ptrs_sll(input.f5);
  return output;
}

/*
 * convert a standard (padded) struct into a packed struct containing
 * the same fields
 *
 * the first argument points to a struct s2_packed, the second
 * argument points to a struct s2
 *
 * therefore, your job is to copy data referenced by the second
 * argument into space referenced by the first argument
 *
 * RESTRICTION: all data movement must be through pointer/array
 * operations, no actual struct code is permitted
 */
void pack_s2 (char * s2_in, char * s2_out) {
  int struct_size = 4 + 4 + 4 + 4 + 8 + 4;
  int i;
  for (i=0; i<struct_size; i++) {
    s2_in[i] = s2_out[i]; 
  }
  //There is nothing to be packed here, lucky me!

}

/*
 * convert a packed struct into a stanard (padded) struct containing
 * the same fields
 *
 * the first argument points to a struct s2, the second
 * argument points to a struct s2_packed
 *
 * therefore, your job is to copy data referenced by the second
 * argument into space referenced by the first argument
 *
 * RESTRICTION: all data movement must be through pointer/array
 * operations, no actual struct code is permitted
 */
void unpack_S2 (char * s2_out, char * s2_in) {
  int struct_size = 4 + 4 + 4 + 4 + 8 + 4;
  int i;
  for (i=0; i<struct_size; i++) {
    s2_out[i] = s2_in[i]; 
  }
  //There is nothing to be unpacked here, lucky me!

}

/*
 * convert a struct with full-width fields into a struct containing
 * bitfields
 *
 * the first argument points to a struct s3_bitfield, the second
 * argument points to a struct s3
 *
 * therefore, your job is to copy data referenced by the second
 * argument into space referenced by the first argument
 *
 * RETURN VALUE: if the value in any full-width field cannot be
 * represented in its corresponding bitfield, return -1; otherwise
 * return 0
 *
 * RESTRICTION: all data movement must be through pointer/array/shift
 * operations, no actual struct code is permitted
 */
int pack_s3 (char * s3_out, char * s3_in) {
  unsigned long long * f0 = (unsigned long long *) s3_in;
  if ( ((*f0) >> 29) != 0 )
    return -1;
  *( (unsigned long long *) s3_out ) = ( (*f0) );// << (64-29) ?? Not sure why not.
  
  signed char * f1 = ((signed char *) s3_in) + 8;
  if ( (*f1 >> 6) != (*f1 >> 7) )
    return -1;

  long long * f2 = (long long *) (s3_in + 12);
  if ( (*f2 >> 35) != (*f2 >> 36) )
    return -1;

  unsigned long long f3 = 0;
  signed char * f3_char = ((signed char *) (s3_in + 20));
  if ( (*f3_char >> 2) != (*f3_char >> 3) )
    return -1;
  memcpy_1(&f3, f3_char, 1);
  f3 = (f3<<(64-3))>>(64-3);

  unsigned long long f4 = 0;
  unsigned int * f4_int = ((unsigned int *) (s3_in + 24));
  memcpy_1(&f4, f4_int, 4);
  if ( (f4 >> 7) != 0 )
    return -1;
  // Insert f1, f2, f3, and f4
  *( (unsigned long long *) (4 + s3_out) ) = ( (*f1) | (((unsigned long long)(*f2)) << 7) | (f3 << 43) | (f4 << 46) );

  unsigned short f5_short = *((unsigned short *) (s3_in + 28));
  // No need to check if it can fit, the bit width is 16 already
  *( (unsigned short *) (12 + s3_out) ) = f5_short;

  return 0;
}

/*
 * convert a struct with bitfields into a struct containing
 * full-width fields
 *
 * the first argument points to a struct s3, the second
 * argument points to a struct s3_bitfield
 *
 * therefore, your job is to copy data referenced by the second
 * argument into space referenced by the first argument
gdgg *
 * RESTRICTION: all data movement must be through pointer/array/shift
 * operations, no actual struct code is permitted
 */
void unpack_s3 (char * s3_out, char * s3_in) {

  unsigned long long f0 = ( *((unsigned long long *)s3_in) << (64-29) ) >> (64-29);
  signed char f1 = (signed char)(((signed int)(*((unsigned int *)(s3_in + 4)) << (32-7))) >> (32-7));
  signed long long f2 = ((signed long long)(*((unsigned long long *)(s3_in + 4)) << 21)) >> (7+21);
  signed char f3 = (signed char)(((signed int)(*((unsigned int *)(s3_in + 8)) << 18)) >> (18+11));
  unsigned int f4 = (*((unsigned int *)(s3_in + 8)) << 11) >> (11+14);

  *((unsigned long long *) s3_out) = f0; 
  *((unsigned char *) (s3_out+8)) = f1; 
  *((unsigned long long *) (s3_out+12)) = f2; 
  *((unsigned char *) (s3_out+20)) = f3; 
  *((unsigned int *) (s3_out+24)) = f4; 
  *((unsigned short *) (s3_out+28)) = *((unsigned short *)(s3_in + 12)); 
}


/* DO NOT put a main() function in this file */

