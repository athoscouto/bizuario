#include <cstdio>
using namespace std;

int gcd(int a, int b) {return (b == 0) ? a : gcd(b, a%b);}

int x, y;
int euclid(int a, int b) {
    if (b==0) {x=1; y=0; return a;}
    int d, m, n;
    d = euclid(b, a%b);
    m = y; n = x - (a/b)*y;
    x = m, y = n;
    return d;
}

const int k = 2;
int a[k], n[k], m[k], M[k];
int chinese() {
    int N = 1, c, ans = 0;
    for(int i=0; i<k; ++i) N *= n[i];
    for(int i=0; i<k; ++i) {
        m[i] = N / n[i];
        euclid(m[i], n[i]);
        M[i] = (x + n[i]) % n[i];
        ans += a[i]*m[i]*M[i];
    }
    return ans % N;
}

const int N = 1e9+8;
int c[N];
void sieve() {for(int i=2; i*i<N; ++i) if(!c[i]) for(int j=i*i; j<N; j+=i) c[j]=1;}

int main() {
    a[0] = 2, a[1] = 3;
    n[0] = 5, n[1] = 13;
    printf("%d\n", chinese());
    return 0;
}
