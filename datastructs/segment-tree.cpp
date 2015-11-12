#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
const int INF = 2e8;

// st = Segment Tree; v = Vector to be queried
int st[4*N], v[N];
int l(int p) {return p<<1;} // find left sibling
int r(int p) {return (p<<1)+1;} // find right sibling

int c(int x, int y) { // Comparison function
    return (v[x] <= v[y]) ? x : y; // Here the comparison is "bigger than" only for example
}

void build(int p, int L, int R) {
    if (L == R) st[p] = L;
    else {
        build(l(p), L, (L+R)/2);
        build(r(p), (L+R)/2+1, R);
        int ls = st[l(p)], rs = st[r(p)];
        st[p] = c(ls, rs);
    }
}
void build() {build(1, 0, N-1);}

int query(int p, int L, int R, int i, int j) {
    if (i>R || j<L) return INF; // segment outside query range
    if (L >= i && R <= j) return st[p]; // segment inside query range
    // If segment is partly inside query range, break segment in two
    // parts and recursively call query trying to find their st values.
    int p1 = query(l(p), L, (L+R)/2, i, j);
    int p2 = query(r(p), (L+R)/2+1, R, i, j);
    if (p1 == INF) return p2;
    if (p2 == INF) return p1;
    return c(p1, p2);
}

int query(int i, int j) {return query(1, 0, N-1, i, j);}

void update(int p, int L, int R, int i)
{
  if (i<L || i>R) return;
  if (L == R) st[p] = L; // Sum: st[p]=v[L];
  else
  {
    update(l(i), L, (L+R)/2, i);
    update(r(i), (L+R)/2+1, R, i);
    st[p] = (v[st[l(i)]] <= v[st[r(i)]]) ? st[l(i)] : st[r(i)]; // Sum: st[p] = st[l(i)] + st[r(i)];
  }
}
