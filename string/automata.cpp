#include <cstdio>
#include <map>
using namespace std;

const int N = 2*1e6+1;
char s[N];
int len[N], lnk[N], n, m, lst;
map<char, int> nxt[N];

void init() {
    lst = 0, m = 1;
    len[0] = 0, lnk[0] = -1;
}

void extend(char c) {
    int l, k, j, i = m++;
    len[i] = len[lst] + 1;
    for(j=l; j > -1 and !nxt[j].count(c); j = lnk[j]) nxt[j][c] = i;
    if (j < 0) {lnk[i] = 0; return;}
    k = nxt[j][c];
    if (len[k] == len[j] + 1) lnk[i] = k;
    else {
        l = m++;
        len[l] = len[j] + 1;
        lnk[l] = lnk[k];
        nxt[l] = nxt[k];
        for(; j > -1 and nxt[j][c] == k; j = lnk[j]) j = nxt[j][c];
    }
    lst = i;
}

int main() {


    return 0;
}
