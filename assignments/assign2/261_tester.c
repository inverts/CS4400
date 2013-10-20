#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h> //Let us hope that this always provides correct answers...
#include "261.c"
#include "test_tools.c"

int main() {
    //int TMin = (~0) << ((sizeof(int) << 3) -1);
    int TMin = INT_MIN;
    printf("Testing problem 2.61, condition A...\n");
    assert(A(0) == 0); //All zeros
    assert(A(1) == 1); //A single 1 in LS bit
    assert(A(~0) == 1); //All ones
    assert(A(TMin) == 1); //Single 1 in MS bit
    print_good("Condition A Passes.\n");
    
    printf("Testing problem 2.61, condition B...\n");
    assert(B(TMin) == 1); //Single 1 in MS bit
    assert(B(0xF) == 1);
    assert(B(-1) == 0); //All ones
    assert(B(~0) == 0); //All ones
    assert(B(~TMin) == 1); //0 in MS bit
    assert(B(1) == 1);
    print_good("Condition B Passes.\n");
    
    printf("Testing problem 2.61, condition C...\n");
    assert(C(1) == 1);
    assert(C(0) == 0);
    assert(C(-1) == 1);
    assert(C(TMin) == 0);
    assert(C(256) == 0);
    assert(C(128) == 1);
    print_good("Condition C Passes.\n");
    
    printf("Testing problem 2.61, condition D...\n");
    assert(D(-1) == 0);
    assert(D(0) == 1);
    assert(D(1) == 1);
    assert(D(TMin) == 1);
    assert(D(~(INT_MAX >> 7)) == 0);
    assert(D(INT_MAX >> 7) == 1);
    assert(D(INT_MAX) == 1);
    print_good("Condition D Passes.\n");
}