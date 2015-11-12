/*
 * Coin Change
 */
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;
const int N = 1e7;

vector<int> coins;
int cache[N];

int coin(int v) {
  if (v < 0) return INF;
  if (v == 0) return 0;
  if (cache[v] >= 0) return cache[v];

  int mi = INF;
  for (int i = 0; i < (int)coins.size(); ++i)
    mi = min(mi, coin(v - coins[i]));
  return cache[v] = 1+mi;
}

int main() {
  memset(cache, -1, sizeof(cache));

  coins.push_back(1);
  coins.push_back(5);

  printf("%d\n", coin(10));
  return 0;
}
