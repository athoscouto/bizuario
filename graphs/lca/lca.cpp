#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e3+1;
int r[N], s[N], v[N], lca[N][N];

void link(int x, int y) {
    if (r[y]>r[x]) swap(x,y);
    s[y] = x;
    if (r[x] == r[y]) r[x]++;
}
int fs(int x) {
    if(x != s[x]) s[x] = fs(s[x]);
    return s[x];
}

// adj represent the graph and q the queries
vector<int> adj[N], q[N];
int p[N];
// O(N*q)
void LCA(int n) {
    for(int i=0; i<adj[n].size(); ++i) {
        int m = adj[n][i];
        if (p[n] == m) continue;
        p[m] = n;
        LCA(m);
        link(n, m);
    }
    v[n] = 1;
    for(int i=1; i<q[n].size(); ++i) {
        int m = q[n][i];
        if (v[m]) lca[n][m] = fs(m);
    }
}
