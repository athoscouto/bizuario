#include <cstdio>
using namespace std;

const int N = 1e6+1, INF = 2e9;
int st[2*N], v[N], lp[2*N], n;
int l(int p) {return 2*p+1;}
int r(int p) {return 2*p+2;}

// merge and updateCurNode are dependent of the problem
// They are implemented to solve max element in range
int merge(int x, int y) {return (x >= y) ? x : y;}
void updateCurNode(int diff, int p, int L, int R) {
    st[p] += diff;
    if(L != R) lp[l(p)] += diff, lp[r(p)] += diff;
}

void build(int p, int L, int R) {
    if (L == R) st[p] = v[L];
    else {
        build(l(p), L, (L+R)/2);
        build(r(p), (L+R)/2+1, R);
        st[p] = merge(st[l(p)], st[r(p)]);
    }
}
void build() {build(0, 0, n-1);}

int query(int i, int j, int p, int L, int R) {
    if (i>R || j<L) return -INF;
    if (L >= i && R <= j) return st[p];
    int q1 = query(i, j, l(p), L, (L+R)/2);
    int q2 = query(i, j, r(p), (L+R)/2+1, R);
    if (q1 == -INF) return q2;
    if (q2 == -INF) return q1;
    return merge(q1, q2);
}
int query(int i, int j) {return query(i, j, 0, 0, n-1);}

void update(int diff, int trgt, int p, int L, int R) {
    if (trgt == L && trgt == R) {st[p] += diff; return;}
    if (trgt>R || trgt<L) return;
    update(diff, trgt, l(p), L, (L+R)/2);
    update(diff, trgt, r(p), (L+R)/2+1, R);
    st[p] = merge(st[l(p)], st[r(p)]);
}
void update(int diff, int trgt) {update(diff, trgt, 0, 0, n-1);}

void batchUpdate(int diff, int i, int j, int p, int L, int R) {
    if (L != R) lp[l(p)] += lp[p], lp[r(p)] += lp[p];
    st[p] += lp[p], lp[p] = 0;
    if (i<=L && R<=j) {updateCurNode(diff, p, L, R); return;}
    if (i<=R && j>=L) {
        batchUpdate(diff, i, j, l(p), L, (L+R)/2);
        batchUpdate(diff, i, j, r(p), (L+R)/2+1, R);
        st[p] = merge(st[l(p)], st[r(p)]);
    }
}
void batchUpdate(int diff, int i, int j) {batchUpdate(diff, i, j, 0, 0, n-1);}

int main() {
    n = 8;
    for(int i=0; i<n; ++i) v[i] = (i*i)%10;
    build();
    for(int i=0; i<n; ++i) printf("%d%c", v[i], (i<n-1) ? ' ' : '\n');
    for(int i=0; i<2*n-1; ++i) printf("%d%c", st[i], (i<2*n-1) ? ' ' : '\n');
    printf("\n");
    while(1) {
        int i, j, diff;
        scanf("%d %d %d", &diff, &i, &j);
        batchUpdate(diff, i, j);
        for(int i=0; i<2*n; ++i) printf("%d%c", st[i], (i<2*n-1) ? ' ' : '\n');
        for(int i=0; i<2*n; ++i) printf("%d%c", lp[i], (i<2*n-1) ? ' ' : '\n');
        printf("\n");
    }
}
