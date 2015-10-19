#include <bits/stdc++.h>
using namespace std;

// Rabin-Karp rolling hash
const int b = 29, mod = 1e9+7, N = 1e6+1;
int n, m; // m: size of ptrn, n: size of txt. m <= n
long long p[N], hash[N]; // p[i] = b^i; hash[i] = hash of string txt[i..i+m-1] (length m)
char txt[N], ptrn[N];

void build() {
    p[0] = 1, hash[0] = txt[m-1];
    for(int i=1; i<m; ++i) p[i] = b*p[i-1], hash[0] += p[i]*txt[m-1-i];
    for(int i=1; i<n-m; ++i) hash[i] = ((hash[i-1] - txt[i-1]*p[m-1])*b + txt[i+m] + mod) % mod;
}
