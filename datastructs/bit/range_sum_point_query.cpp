#include <cstdio>
using namespace std;

const int N = 1e6+1;
int f[N], a[N], n;

void build() {for(int i=n; i>0; --i) f[i] = a[i] - a[i - (i&-i)];}

void update(int i, int v) {while(i <= n) f[i] += v, i += i&-i;}
void update(int l, int r, int v) {update(l, v), update(r+1, -v);}

int query(int i) {
    int s = 0;
    while(i > 0) s += f[i], i -= i&-i;
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
        if(t) scanf("%d%d%d", &l, &r, &v), update(l, r, v);
        else scanf("%d", &i), printf("query: %d\n", query(i));
        for(int i=1; i<=n; ++i) printf("%d%c", query(i), i == n ? '\n' : ' ');
    }
}
*/
