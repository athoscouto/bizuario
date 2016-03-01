#include <cstdio>
#include <queue>
#include <map>
using namespace std;

struct edge {
    int w, c, v;
    edge* rv;
};
const int N = 1e3;
vector<edge*> g[N];
int p[N], wgt[N];

int bfs(int sr, int sk) { // O(n + m)
    memset(p, 0, sizeof p);
    queue<int> q;
    q.push(sr), p[sr] = sr;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i=0; i<g[u].size(); ++i) {
            int v = g[u][i]->v, w = g[u][i]->w;
            if (w and !p[v]) p[v] = u, wgt[v] = w, q.push(v);
        }
        if (p[sk]) break;
    }
    if (!p[sk]) return 0;
    int ap = 2e9, v = sk, u;
    while(p[v] != v) ap = min(ap, wgt[v]), v = p[v];
    v = sk;
    while(p[v] != v) u=p[v], g[u][v] -= ap, g[v][u] += ap, v = u;

    return ap;
}

int max_flow(int sr, int sk) {
    int mf = 0, df;
    while(1) {
        df = bfs(sr, sk);
        mf += df;
        if (!df) break;
    }
    return mf;
}
