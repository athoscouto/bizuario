#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e6+1;
int p[N], r[N];

void init() {
    for(int i=1; i<=N; ++i) p[i] = i;
    memset(r, 0, sizeof r);
}

void link(int x, int y) {
    if (r[y] > r[x]) swap(x, y);
    p[y] = x;
    if (r[x] == r[y]) r[x]++;
}

int find(int x) {return (x == p[x]) ? p[x] : p[x] = find(p[x]);}
