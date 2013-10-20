#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h> //Let us hope that this always provides correct answers...
#include "273.c"
#include "test_tools.c"

int main() {
    printf("Testing problem 2.73...\n");
    int TMin = INT_MIN; // (~0) << ((sizeof(int) << 3) -1);
    assert(saturating_add(1, 2) == 3); // 1+2=3
    assert(saturating_add(0, 0) == 0); // 1+2=3
    assert(saturating_add(~0, ~0) == -2); // -1 + -1 = -2
    assert(saturating_add(~TMin, 1) == ~TMin); // TMax + 1 = TMax
    assert(saturating_add(TMin, -1) == TMin); // TMin - 1 = TMin
    assert(saturating_add(TMin, TMin) == TMin); // TMin + TMin = TMin
    assert(saturating_add(~TMin, ~TMin) == ~TMin); // TMax + TMax = TMax
    assert(saturating_add(~TMin-1, 1) == ~TMin); // TMax - 1 + 1 = TMax
    assert(saturating_add((~TMin)/2 + 1, (~TMin)/2 + 1) == ~TMin); // TMax/2 + TMax/2 + 1 = TMax
    print_good("2.73 Passes.\n");
    
}