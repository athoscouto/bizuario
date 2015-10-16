// Needleman-Wunsch's DP Algorithm
// Complexity: O(n*m)

const char sp = ' ';
const int N = 1e5+1;
char A[N], B[N];
int m, n;

int dp[N][N]; // dp[i][j] is the score of the optimal alignment between the prefixes of A and B of length i and j;

int score(char, char);

int slv() {
    int mtc, spa, spb, M;
    dp[0][0] = 0;
    for(int i=1; i < m; ++i) dp[i][0] = dp[i-1][0] + score(A[i], sp);
    for(int i=1; i < n; ++i) dp[0][i] = dp[0][i-1] + score(sp, B[i]);

    for(int i=1; i < m; ++i) for(int j=1; j < n; ++j) {
        M = dp[i-1][j-1] + score(A[i], B[j]);
        M = max(M, dp[i][j-1] + score(sp, B[j]));
        M = max(M, dp[i-1][j] + score(A[i], sp));
        dp[i][j] = M;
    }
    return dp[m][n];
}
