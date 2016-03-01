const int N = 1e7;
int lps[2*N+1];
char s[2*N+1], c[N];
void build(int n) {
    for(int i=0; i<n; ++i) {
        s[2*i] = '#';
        s[2*i+1] = c[i];
    }
    s[2*n] = '#';
}

int manacher() {
    int k=0, r=0, m=0, len=strlen(s), l, h;
    for(int i=1; i<len; ++i) {
        lps[i] = (r > i) ? min(r - i, lps[2*k - i]) : 0;
        while(((l=i+1+lps[i]) < len) && ((h=i-1-lps[i]) > -1)  && s[l] == s[h]) lps[i]++;
        m = max(m, lps[i]);
        if(i + lps[i] > r) {
            k = i;
            r = i + lps[i];
        }
    }
    return m;
}
// Rabin-Karp rolling hash
const int b = 29, mod = 1e9+7, N = 1e6+1;
int n, m; // m: size of ptrn, n: size of txt. m <= n
long long p[N], hash[N]; // p[i] = b^i; hash[i] = hash of string txt[i..i+m-1] (length m)
char txt[N], ptrn[N];

void build() {
    p[0] = 1, hash[0] = txt[m-1];
    for(int i=1; i<m; ++i) p[i] = b*p[i-1], hash[0] += p[i]*txt[m-1-i];
    for(int i=1; i<n-m; ++i) hash[i] = ((hash[i-1] - txt[i-1]*p[m-1])*b + txt[i+m] + mod) % mod;
}
