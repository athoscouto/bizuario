#include <cstdio>
using namespace std;

const int N = 1e6+1;
int x[N], y[N], a[N], n;

void build() {
    for(int i=1; i<=n; ++i) x[i] = a[i] + x[i-1], y[i] = 0;
    for(int i=n; i>0; --i) x[i] -= x[i - (i&-i)];
}

void update(int *a, int i, int v) {
    while(i <= n) a[i]  += v, i += i&-i;
}

void update(int l, int r, int v) {
    update(y, l, v), update(y, r+1, -v);
    update(x, l, -(l-1)*v), update(x, r+1, r*v);
}

int query(int *a, int i){
    int s=0;
    while(i > 0) s += a[i], i -= i&-i;
    return s;
}
int query(int i) {return query(x, i) + i*query(y, i);}

/* TEST
int main() {
    n=10;
    for(int i=1; i<=n; ++i) a[i] = i;
    build();
    while(1) {
        int t, l, r, v;
        scanf("%d%d%d", &t, &l, &r);
        if(t) scanf("%d", &v), update(l, r, v);
        else printf("query: %d\n", query(r) - query(l-1));
        for(int i=1; i<=n; ++i) printf("%d%c", query(i) - query(i-1), i == n ? '\n' : ' ');
    }
}
*/
