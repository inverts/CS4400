 /* Return 1 when any odd bit of x equals 1; 0 otherwise.
    Assume w=32. 
    Odd is defined by the power of 2 at the current place.
    */
    int any_odd_one(unsigned x) {
        unsigned mask = 0xAAAAAAAA;
        return (x & mask) != 0;
    }
    