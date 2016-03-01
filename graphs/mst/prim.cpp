#include <queue>
#include <vector>
#include <utility>
#include <cstdio>
#include <algorithm>
#define pi pair<int, int>
#define mk make_pair
using namespace std;

const int N = 1e6+1;
bool vstd[N];
int p[N];
vector<pi> gr[N], mst[N];
priority_queue<pi, vector<pi>, greater<pi> >  pq;

void explore(int u) {
    vstd[u] = 1;
    for(int i=0; i<gr[u].size(); ++i) {
        int v = gr[u][i].second, w = gr[u][i].first;
        if (!vstd[v]) {
            pq.push(mk(w, v));
            p[v] = u;
        }
    }
}

int prim(int r) {
    int W = 0;
    p[r] = r;
    explore(r);
    while(!pq.empty()) {
        int u = pq.top().second, w = pq.top().first; pq.pop();
        if (!vstd[u]) {
            explore(u);
            W += w;
            mst[p[u]].push_back(mk(w, u));
            mst[u].push_back(mk(w, p[u]));
        }
    }
    return W;
}

int main() {
    int n, m, u, v, w;
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        gr[u].push_back(mk(w,v));
        gr[v].push_back(mk(w,u));
    }
    printf("%d\n", prim(1));
    return 0;
}
