#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e6+1, logN = 30;
int anc[N][logN], p[N], h[N];
// O(N*logN)
void fill() {
    for(int i=1; i<=N; ++i) anc[i][0] = p[i];
    for(int j=1; 1<<j < N; ++j) for(int i=1; i<=N; ++i)
        anc[i][j] = anc[anc[i][j-1]][j-1];
}

// O(logN)
int query(int x, int y) {
    if (h[y] > h[x]) swap(x, y);
    for(int i=logN-1; i>=0; --i)
        if(h[anc[x][i]] >= h[y]) x = anc[x][i];
    if (x == y) return x;
    for(int i=logN-1; i>=0; --i)
        if(anc[x][i] != anc[y][i])
            x = anc[x][i], y = anc[y][i];
    return p[x];
}
