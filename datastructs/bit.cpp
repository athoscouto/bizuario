#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int bit[N+1];

void adjust(int k, int v) {for(; k<N+1; k+= (k&-k)) bit[k] += v;}
int rsq(int k) { // Range Sum Query from 1st element until k-th element
    int sum = 0;
    while(k) {sum += bit[k]; k-=(k&-k);}
    return sum;
}

int main() {
    // Let the cumulative vector starts with a 0. The first element must have index 1!
    int vec[] = {0, 1, 2, 2, 3, 3, 3, 4, 6, 7, 10};
    for(int i=1; i<N+1; ++i) bit[i] = vec[i] - vec[i-(i&-i)];

    for(int i=1; i<N+1; ++i) cout << rsq(i) << " ";
    cout << endl;
    return 0;
}
