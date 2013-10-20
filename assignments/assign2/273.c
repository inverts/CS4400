#include <limits.h> //Let us hope that this always provides correct answers...

/*  Addition that saturates to TMin or TMax */
int saturating_add(int x, int y) {
    int TMin = INT_MIN; //(~0) << ((sizeof(int) << 3) -1);
    int TMax = ~TMin;
    if (y>0 && x>0 && (TMax - y < x)) {
            return TMax;
    } else if (y<0 && x<0 && (TMin - y > x)) {
            return TMin;
    } else {
        return x + y;
    }
}
