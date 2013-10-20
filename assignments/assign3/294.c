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

/* Compute 0.5*f. If f is NaN, then return f. */
float_bits float_half(float_bits f) {
    // If f is NaN, return F.
    if ((f << 1) >= 0xFF000000)
        return f;
    float_bits filtered = f & 0xFF000000; // Gets relevant part of exponent
    // If the exponent isn't all zeros, divide normally
    if (filtered << 1) {
        // Subtract 1 from exponent
        return (f - 0x00800000);
    }
    else // Otherwise, divide as a denormalized number. 
    {
        // Pay attention to bit #1 for rounding properly to even 
        // Shift mantissa + LSB of exponent right (LSB for 0xFF800000 case).
        return (((f+((f & 0x00000002)>>1)) >> 1) & 0x00FFFFFF) | filtered; // OR with filtered for sign bit.
    }
}

/* Tests float_half() for all combinations of 32 bits. */
int main() {
    float half = 0.5;
    unsigned i = 0;
    do {
        //if (i%0x10000000 == 0)
        //    printf("At i=%X...\n", i);
        if (isnan(bits_to_float(i))){
            assert(float_half(i) == i);}
        else
            assert(bits_to_float(float_half(i)) == half*bits_to_float(i));
        
        i++;
    } while (i!=0);
    printf("Passed.\n");
}