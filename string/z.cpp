// Z Algorithm
// Complexity: O(n) to build the Z array.

// For a string str[0..n-1], Z array is of same length as string. An element Z[i]
// of Z array stores length of the longest substring starting from str[i] which is
// also a prefix of str[0..n-1]. The first entry of Z array is meaning less as
// complete string is always prefix of itself.

// To user Z Algorithm  in pattern mathcing, concatenate pattern and text, and create 
// a string “P$T” where P is pattern, $ is a special character should not be present 
// in pattern and text, and T is text. Build the Z array for concatenated string. 
// In Z array, if Z value at any point is equal to pattern length, then pattern is 
// present at that point.

// More on: http://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+1;
int n, z;
string s;

void build_z() {
    int l=0, r=0;
    for(int i=0; i<n; ++i) {
        if (i > r) {
            l = r = i, z[i] = 0;
            while(r < n && s[r] == s[r-l]) ++r, ++z[i];
            --r;
        } else {
            if (z[i-l] < r - i + 1) z[i] = z[i-l];
            else {
                l = i;
                while(r+1 < n && s[r+1] == s[r-l+1]) ++r;
                z[i] = r - l + 1;
            }
        }
    }
}
