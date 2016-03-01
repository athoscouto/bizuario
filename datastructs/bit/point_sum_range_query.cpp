#include <cstdio>
using namespace std;

const int N = 1e6+1;
int f[N+1], a[N+1], n;

void build() {
    for(int i=1; i<=n; ++i) f[i] = a[i] + f[i-1];
    for(int i=n; i>0; --i) f[i] -= f[i - (i&-i)];
}

void update(int i, int v) {while(i<=n) f[i] += v, i += i&-i;}

int query(int i) {
    int s = 0;
    while(i) s += f[i], i-= i&-i;
    return s;
}

/* TEST
int main() {
    n=10;
    for(int i=1; i<=n; ++i) a[i] = i;
    build();
    while(1) {
        int t, l, r, v, i;
        scanf("%d", &t);
        if(t) scanf("%d%d", &i, &v), update(i, v);
        else scanf("%d%d", &l, &r), printf("query: %d\n", query(r) - query(l-1));
        for(int i=1; i<=n; ++i) printf("%d%c", query(i) - query(i-1), i == n ? '\n' : ' ');
    }
}
*/
