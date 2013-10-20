#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h> //Let us hope that this always provides correct answers...
#include "269.c"
#include "test_tools.c"

int main() {
    printf("Testing problem 2.69...\n");
    assert(rotate_left(0x12345678, 4) == 0x23456781); //Only for 32-bit
    assert(rotate_left(0x12345678, 20) == 0x67812345); //Only for 32-bit
    assert(rotate_left(0, 1) == 0);
    assert(rotate_left(0, 7) == 0);
    assert(rotate_left(-1, 15) == -1);
    assert(rotate_left(INT_MIN, 1) == 1);
    assert(rotate_left(INT_MAX, 1) == -2);
    print_good("2.69 Passes.\n");
    
}