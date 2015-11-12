/*
 * RMQ
 */

// Naive: <O(N^2), O(1)>
int M[MAXN][MAXN], int A[MAXN], N;
void process() {
  int i, j;
  for (i = 0; i < N; ++i) M[i][j] = i;
  for (i = 0; i < N; ++i) for (j = i+1; j < N; ++j)
    if (A[M[i][j-1]] < A[j]) M[i][j] = M[i][j-1];
    else M[i][j] = j;
}

int query(int i, int j) {
  return M[i][j];
}

// Sparse Table (ST): <O(NlogN), O(1)>
int M[MAXN][LOGMAXN], int A[MAXN], N;
void process() {
  int i, j;
  for (i = 0; i < N; ++i) M[i][0] = i;
  for (j = 1; (1<<j) <= N; ++j) for (i = 0; i + (1<<j) -1 < N; ++i) {
    if (A[M[i][j-1]] < A[M[i + (1 << (j-1))][j-1]])
      M[i][j] = M[i][j-1];
    else
      M[i][j] = M[i + (1 << (j-1))][j-1];
  }
}

int query(int i, int j) {
  int k = (int)(log2(j-i+1));
  return A[M[i][k]] <= A[M[j-(1<<k)+1][k]] ? M[i][k] : M[j-(1<<k)+1][k];
}

// Segment Tree: <O(N), O(logN)>
const int INF = 2e9;
int M[4*MAXN], A[MAXN], N;
void build(int p, int b, int e) {
  if (b == e) M[p] = b;
  else {
    build(2*p, b, (b+e)/2);
    build(2*p+1, (b+e)/2, e);
    M[p] = A[M[2*p]] <= A[M[2*p+1]] ? M[2*p] : M[2*p+1];
}
// build(1, 0, N-1);

int query(int p, int b, int e, int i, int j) {
  if (i > e || j < b) return INF;
  if (b >= i && e <= j) return M[p];

  int p1 = query(2*p, b, (b+e)/2);
  int p2 = query(2*p+1, (b+e)/2, e);
  if (p1 == INF) return p2;
  if (p2 == INF) return p1;
  return A[p1] <= A[p2] ? p1 : p2;
}
// query(1, 0, N-1, i, j)
