/*
 * Longest Increasing Subsequence
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
int A[N];

int lis() {
  vector<int> l(N, 1);
  int m = 1;
  for (int i = 1; i < N; ++i)
    for (int j = 0; j < i; ++j)
      if (A[i] > A[j])
        l[i] = max(l[i], 1+l[j]), m = max(m, l[i]);
  return m;
}
