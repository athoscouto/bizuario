#include <vector>
using namespace std;

const int N = 1e6+1;
int l[N], n[N], p[N], art[N], c=1, rt, rc;
vector<int> adj[N], brdg[N];

void find(int u) {
    l[u] = n[u] = c++;
    for(int i=0; i<adj[u].size(); ++i) {
        int v = adj[u][i];
        if(!p[v]) {
            p[v] = u;
            find(v);
            if(l[v] >= n[u]) art[u] = 1;
            if(l[v] > n[u]) brdg[u].push_back(v);
        }
        if(v != p[u]) l[u] = min(l[u], l[v]);
    }
}

void tarjan() {
    for(int i=1; i<=N; ++i) if(!p[i]) {
        rt = i, rc = 0, p[i]=i;
        find(i);
        art[i] = (rc > 1);
    }
}
