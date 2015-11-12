#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1e7;
int lps[2*N+1];
char s[2*N+1], c[N];
void build(int n) {
    for(int i=0; i<n; ++i) {
        s[2*i] = '#';
        s[2*i+1] = c[i];
    }
    s[2*n] = '#';
}

int manacher() {
    int k=0, r=0, m=0, len=strlen(s), l, h;
    for(int i=1; i<len; ++i) {
        lps[i] = (r > i) ? min(r - i, lps[2*k - i]) : 0;
        while(((l=i+1+lps[i]) < len) && ((h=i-1-lps[i]) > -1)  && s[l] == s[h]) lps[i]++;
        m = max(m, lps[i]);
        if(i + lps[i] > r) {
            k = i;
            r = i + lps[i];
        }
    }
    return m;
}
