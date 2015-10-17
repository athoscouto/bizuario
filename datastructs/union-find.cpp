#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+1;
int uf[N];
int rank[N];

void uf_init() {
    for(int i=0; i<N; ++i) {uf[i] = i; rank[i]=0;}
}
int findSet(int i) {
    if (i == uf[i]) return i;
    else {rank[i] = 1; return uf[i] = findSet(uf[i]);}
}
bool isSameSet(int i, int j) {return findSet(i) == findSet(j);}
void unionSet(int i, int j) {
    int x = findSet(i), y = findSet(j);
    if (x != y) {
        if (rank[x] >= rank[y]) uf[y] = x;
        else uf[x] = y;
        if (rank[x] == rank[y]) rank[x]++;
    }
}
