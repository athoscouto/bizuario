#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int n, ra[N], tra[N], sa[N], tsa[N], c[N];
char t[N];

void countSort(int k) {
    int i, t, sum, maxi = max(300, n);
    memset(c, 0, sizeof(c));
    for(i=0; i<n; ++i) c[(i+k<n) ? ra[i+k] : 0]++;
    for(i=sum=0; i<maxi; ++i) t = c[i], c[i] = sum, sum +=t;
    for(i=0; i<n; ++i) tsa[c[(sa[i]+k<n) ? ra[sa[i]+k] : 0]++] = sa[i];
    for(i=0; i<n; ++i) sa[i] = tsa[i];
}

void buildSA() {
    int i, k, r, c;
    for(i=0; i<n; ++i) ra[i] = t[i];
    for(i=0; i<n; ++i) sa[i] = i;
    for(k=1; k<n; k<<=1) {
        countSort(k), countSort(0);
        tra[sa[0]] = r = 0;
        for(i=1; i<n; ++i) tra[sa[i]] = (ra[sa[i]] == ra[sa[i-1]] && ((sa[i]+k<n) ? ra[sa[i]+k] : 0) == ((sa[i-1]+k<n) ? ra[sa[i-1]+k] : 0)) ? r : ++r;
        for(i=0; i<n; ++i) ra[i] = tra[i];
        if (ra[sa[n-1]] == n-1) break;
    }
}


char p[N];
int m, l, h;
bool cmp(int i, int ign) {return strncmp(t+sa[i], p, m);}
void stringMatching() {
    l = lower_bound(sa, sa+n, 0, cmp) - sa;
    if (strncmp(t + sa[l], p, m) != 0) {l=h=-1; return;}
    h = upper_bound(sa, sa+n, 0, cmp) - sa;
    if (strncmp(t + sa[h], p, m) != 0) h--;
}

int main() {
    n = (int)strlen(fgets(t, N, stdin));
    t[n-1] = '$';
    buildSA();
    printf("n=%d\n\n", n);
    for (int i = 0; i < n; i++) printf("%2d\t%s\n", sa[i], t + sa[i]);

    while (m = (int)strlen(fgets(p, N, stdin)), m) {
        stringMatching();
        if (l != -1 && h != -1) {
            printf("%s found, SA [%d..%d] of %s\n", p, l, h, t);
            printf("They are:\n");
            for (int i = l; i <= h; i++)
                printf(" %s\n", t + sa[i]);
        } else printf("%s is not found in %s\n", p, t);
    }
}
