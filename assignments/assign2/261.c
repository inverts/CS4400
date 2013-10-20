#include <stdlib.h>

//1 if: Any bit of x equals 1.
int A(int x) {
    return x != 0;
}

//1 if: Any bit of x equals 0.
int B(int x) {
    return x != ~0;
}

//1 if: Any bit in the least significant byte of x equals 1.
int C(x) {
    // Logical AND with all 1s should not reveal all zeroes unless x does not have 1 in LSB. 
    //Debugging: printf("X: %d -- 0xF: %d -- X&0XF: %d \n", x, 0xF, x&0xF);
   return (x & 0xFF) != 0; 
}

//1 if: Any bit in the most significant byte of x equals 0.
int D(x) {
    int filter = ~(INT_MAX >> 7); //((~0) << ((sizeof(int) << 3)-4)); 
    return ((filter & x) & filter) != filter;
}