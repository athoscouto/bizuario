#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#define pi pair<int, int>
#define pei pair<edge, int>
using namespace std;


const int N = 5e2+3, INF = 2e9;
queue<int> q;
int p[N], f[N];
vector<pi> gr[N];
map<int, int>  rn[N];
bool bfs(int s, int t) {
    memset(p, 0, sizeof p);
    p[s] = s, f[s] = INF;
    q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i=0; i<gr[u].size(); ++i) {
            int v = gr[u][i].second;
            int w = rn[u][v];
            if (p[v] || !w) continue;
            f[v] = min(f[u], w);
            p[v] = u;
            q.push(v);
        }
    }
    return p[t];
}

int edmonds_karp(int s, int t) {
    int flow = 0;
    for(int u=1; u<N; ++u)
        for(int i=0; i<gr[u].size(); ++i) {
            int v = gr[u][i].second;
            int w = gr[u][i].first;
            rn[u][v] = w;
            rn[v][u] = w;
        }
    while(bfs(s, t)) {
        int v = t, u = p[v], c = f[v];
        while(u != v) {
            rn[u][v] -= c;
            rn[v][u] += c;
            u = p[u], v = u;
        }
        flow += c;
    }
    return flow;
}
