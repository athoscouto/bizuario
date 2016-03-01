#include<vector>
using namespace std;

const int N = 1e6;
int vstd[N], S[N], s=0, n;
vector<int> adj[N], tadj[N];

void dfs(int u, int p) {
    vstd[u] = 1;
    vector<int> g = (p == 1) ? adj[u] : tadj[u];
    for(int i=0; i<g.size(); ++i)
        if(!vstd[g[i]]) dfs(g[i], p);
    S[s++] = u;
}

void kosaraju() {
    for(int i=0; i<N; ++i) for(int j=0; j<adj[i].size(); ++j)
        tadj[adj[i][j]].push_back(i);
    memset(vstd, 0, sizeof vstd);
    for(int i=0; i<N; ++i) if(!vstd[i]) dfs(i, 1);
    n = 0, memset(vstd, 0, sizeof vstd);
    for(int i=N-1; i>=0; --i) if(!vstd[S[i]]) {
        n++;
        dfs(S[i], 2);
    }
}
