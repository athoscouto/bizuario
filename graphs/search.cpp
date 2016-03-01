#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

#define pi pair<int, int>
#define ti pair<int, pi>
#define mkp make_pair
using namespace std;

const int N = 1e6;
vector<int> adj[N];
int p[N], d[N];
queue<int> q;

// O(V+E)
void bfs(int n) {
    q.push(n);
    p[n] = n, d[n] = 0;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(int i=0; i<adj[v].size(); ++i) {
            if (!p[adj[v][i]]) {
                q.push(adj[v][i]);
                d[adj[v][i]] = d[v] + 1;
                p[adj[v][i]] = v;
            }
        }
    }
}

int st[N], ft[N], t=0;
// O(V+E)
void dfs(int n) {
    st[n] = t++;
    for(int i=0; i<adj[n].size(); ++i)
        if (!p[adj[n][i]]) {
            p[adj[n][i]] = n;
            dfs(adj[n][i]);
        }
    ft[n] = t++;
}

vector<pi> wadj[N];
// O(VE)
bool bellman_ford(int n) {
    p[n] = n;
    for(int k=1; k<N; ++k) {
        for(int i=0; i<N; ++i) for(int j=0; j<wadj[i].size(); ++i) {
            int u = i, v = wadj[i][j].first, w = wadj[i][j].second;
            if (!p[u]) continue;
            if (!p[v] || d[v] > d[u] + w) d[v] = d[u] + w, p[v] = u;
        }
    }
    for(int i=0; i<N; ++i) for(int j=0; j<wadj[i].size(); ++i) {
        int u = i, v = wadj[i][j].first, w = wadj[i][j].second;
        if (d[v] > d[u] + w) return false;
    }
    return true;
}


priority_queue<pi, vector<pi>, greater<pi> > pq;
// O((V+E)logV)
void dijsktra(int n) {
    d[n] = 0, p[n] = n;
    pq.push(mkp(0, n));
    while(!pq.empty()) {
        int u = pq.top().second, dist = pq.top().first; pq.pop();
        if (dist > d[u]) continue;
        for(int i=0; i<wadj[u].size(); ++i) {
            int v = wadj[u][i].second, w = wadj[u][i].first;
            if (!p[v] || d[v] > d[u] + w) {
                p[v] = u, d[v] = d[u]+w;
                pq.push(mkp(d[v], v));
            }
        }
    }
}


int adjm[N][N];
// O(V^3)
void floyd_warshall() {
    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) for(int k=0; k<N; ++k)
        adjm[i][j] = min(adjm[i][j], adjm[i][k] + adjm[k][j]);
}
