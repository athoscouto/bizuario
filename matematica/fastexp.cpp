#include <bits/stdc++.h>
using namespace std;

ll fastexp(ll p, ll q, ll mod) {
  ll r = 1;
  while (q) {
    if (q&1) r *= p, q--;
    p *= p;
    q >>= 1;
  }
  return r;
}
