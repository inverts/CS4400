/*
 *
 * Do rotating left shift. Assume 0 <= n < w
 */
unsigned rotate_left(unsigned x, int n) {
    unsigned a = x;
    a = a << n; //Do the left shift, removing the left side bits
    // Shift the lost left bits appropriately to the right.
    x = x >> (((sizeof(int) << 3) - n) & (~(sizeof(int) << 3))); //Should solve n=0 problem
    return a | x; // Combine the bits.
    
}