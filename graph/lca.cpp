/*
 * Lowest Common Ancestor
 */

vector<int> adj[MAXN];

// Sqrt: <O(N), O(sqrt(N))>
// P[i]: pai na seção anterior
// T[i]: pai
// L[i]: altura(level)
int P[MAXN], T[MAXN], L[MAXN], N;
void dfs(int u, int p, int d, int nr) {
  int k;
  T[u] = p;
  L[u] = d;

  if (L[u] < nr) P[u] = 1;
  else {
    if (!(L[u] % nr)) P[u] = T[u];
    else P[u] = P[T[u]];
  }

  for (int i = 0; i < adj[u].size(); ++i)
    dfs(k, nr);
}
// dfs(1, -1, 0, sqrt(N));

int lca(int x, int y) {
  while (P[x] != P[y])
    if (L[x] > L[y]) x = P[x];
    else y = P[y];
  while (x != y)
    if (L[x] > L[y]) x = T[x];
    else y = T[y];
  return x;
}

// Sparse Table (ST): <O(NlogN, O(logN)>
// P[i][j]: 2^j ancestor of i
// T[i]: pai
// L[i]: altura(level)
int P[MAXN][LOGMAXN], T[MAXN], L[MAXN], N;
void process() {
  int i, j;
  for (i = 0; i < N; ++i) for (j = 0; (1<<j) < N; ++j)
    P[i][j] = -1;
  for (i = 0; i < N; ++i) P[i][0] = T[i];
  for (j = 1; (1<<j) < N; ++j) for (i = 0; i < N; ++i)
    if (P[i][j-1] != -1) P[i][j] = P[P[i][j-1]][j-1];
}

int query(int p, int q) {
  int lg, i;
  if (L[p] < L[q]) swap(p, q);

  for (lg = 1; (1 << lg) <= L[p]; ++lg); lg--;
  for (i = lg; i >= 0; --i)
    if (L[p] - (1<<i) >= L[q])
      p = P[p][i];

  if (p == q) return p;
  for (i = lg; i >= 0; --i)
    if (P[p][i] != -1 && P[p][i] != P[q][i])
      p = P[p][i], q = P[q][i];
  return T[p];
}

// Reduction to RMQ: <O(N), O(logN)>
// L[i]: altura
// E[i]: sequencia euler tour
// H[i]: primeira ocorrência na sequencia
int L[2*MAXN], E[2*MAXN], H[MAXN], idx;
vector<int> adj[MAXN];
void dfs(int u, int d) {
  H[u] = idx;
  E[idx] = u;
  L[idx++] = d;
  for (int i=0; i < adj[u].size(); ++i) {
    dfs(adj[u][i], d+1);
    E[idx] = u;
    L[idx++] = d;
  }
}

void buildLCA() {
  idx = 0;
  memset(H, -1, sizeof(H));
  dfs(0, 0);
}

int lca(int x, int y) {
  if (H[x] > H[y]) swap(x, y);
  return E[query(H[x], H[y])]; // RMQ query
}
