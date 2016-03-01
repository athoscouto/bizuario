#include <cstdio>
#include <queue>
#include <cstring>
#include <map>
using namespace std;
typedef pair<int, int> ii;

const int N = 1e3;
map<int, int> g[N]; // unordered ??
int p[N], wgt[N];
int n, m, k, w, sr, sk, u, v, t=0, c;

int bfs(int sr, int sk) { // O(n*log(m) + m)
    memset(p, 0, sizeof p);
    queue<int> q;
    q.push(sr), p[sr] = sr;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto i=g[u].begin(); i!=g[u].end(); ++i) {
            int v = i->first, w = i->second;
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


int main() {
    while(scanf("%d", &n) and n) {
        t++;
        scanf("%d%d%d", &sr, &sk, &c);
        for(int i=1; i<=n; ++i) g[i].clear();

        for(int i=1;i<=c; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            g[u][v] += w;
            g[v][u] += w;
        }
        printf("Network %d\n", t);
        printf("The bandwidth is %d.\n", max_flow(sr, sk));
    }
    return 0;
}
