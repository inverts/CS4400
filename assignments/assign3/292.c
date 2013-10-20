#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>

/* Access bit-level representation floating-point number */
typedef unsigned float_bits;

/* Convert a float_bits into float. */
float bits_to_float (float_bits u)
{
    float f;
    memcpy (&f, &u, 4);
    return f;
}

/* Convert a float into float_bits. */
unsigned float_to_bits (float f)
{
    float_bits u;
    memcpy (&u, &f, 4);
    return u;
}

/* Compute |f|. If i is NaN, then return f. */
float_bits float_absval(float_bits f) {
    float_bits absf = f & 0x7FFFFFFF; // Filter out sign bit.
    return (absf>0x7F800000) ? f : absf; // If NaN, return f, else, return filtered f.
}


/* Tests float_absval */
int main() {
    unsigned i = 0;
    float my_f;
    do {
        // As specified in the book, if the result is NaN, return the input unaltered.
        if (isnan(bits_to_float(i))) {
            assert(float_absval(i) == i);
        } else {
            float result = bits_to_float(float_absval(i));
            float hypothesis = fabs(bits_to_float(i));
            assert(result == hypothesis);
        }
        i++;
    } while (i!=0);
    printf("Passed.\n");
}