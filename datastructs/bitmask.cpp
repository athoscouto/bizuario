#include <bits/stdc++.h>

using namespace std;

// Long long has 63 bits
long long bits;

int main() {
    int i, n;

    // Turn on the i-th bit
    bits |= 1<<i;
    // Turn off the i-th bit
    bits &= ~(1<<i);
    // Toggle the i-th bit
    bits ^= 1<<i;

    // Check if the i-th bit is on
    bool t = bits & 1<<i;

    // Get least significant bit
    int lsb = bits & -bits;

    // Turn on all the first n bits
    bits = (1<<n) - 1;

    // Remainder modulo 2^n
    int rmd = bits & ((1<<n) - 1);

    // Determine if bits is a power of 2:
    t = (lsb == bits);

    // Turn off the last significant bit
    bits ^= lsb;

    // Turn on the last zero
    bits |= (bits+1) & -(bits+1); // The last 0 of bits is the lsb of bits+1

    return 0;
}
