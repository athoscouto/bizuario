#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#define pi pair<int, int>
#define ti pair<int, pi>
#define mk make_pair
using namespace std;

const int N = 1e6+1;
int s[N], r[N];
int fs(int x) {
    if (x != s[x]) s[x] = fs(s[x]);
    return s[x];
}

void merge(int x, int y) {
    if (r[y] > r[x]) swap(x, y);
    s[y] = s[x];
    if (r[x] == r[y]) r[x]++;
}

vector<pi> gr[N], mst[N];
vector<ti> el;
int kruskal() {
    int x, y, w, W=0;
    sort(el.begin(), el.end());
    for(int i=0; i<el.size(); ++i) {
        x = el[i].second.first;
        y = el[i].second.second;
        w = el[i].first;
        if (fs(x) != fs(y)) {
            merge(x, y);
            mst[x].push_back(mk(w, y));
            mst[y].push_back(mk(w, x));
            W+=w;
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
    // init disjoint sets
    for(int i=1; i<=N; ++i) s[i] = i, r[i]=0;
    // Fill edge list
    el.clear();
    for(int i=1; i<=N; ++i) {
        vector<pi> ev = gr[i];
        for(int j=0; j<ev.size(); ++j)
            el.push_back(mk(ev[j].first, mk(i, ev[j].second)));
    }
    printf("%d\n", kruskal());
}
