#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h> //Let us hope that this always provides correct answers...
#include "264.c"
#include "test_tools.c"

int main() {
    //int TMin = (~0) << ((sizeof(int) << 3) -1);
    int TMin = INT_MIN;
    printf("Testing problem 2.64...\n");
    assert(any_odd_one(1) == 0); //...00 0000 0001
    assert(any_odd_one(0) == 0); //...00 0000 0001
    assert(any_odd_one(32) == 1); //...00 0010 0000
    assert(any_odd_one(0xB) == 1); //...00 0000 1011
    assert(any_odd_one(0xA) == 1); //...00 0000 1010
    assert(any_odd_one(0xFF) == 1); //...00 1111 1111
    assert(any_odd_one(0xAA) == 1); //...00 1010 1010
    assert(any_odd_one(0x55) == 0); //...00 0101 0101
    assert(any_odd_one(TMin) == 1); //1000 00...
    assert(any_odd_one(~TMin) == 1); //0111 11...
    print_good("2.64 Passes.\n");
    
    
}