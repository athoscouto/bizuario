const int N = 1e7+1;
// Knuth-Morris-Pratt Algorithm
// Complexity: O(m) to fill the table, O(n) to run the search.
char txt[N], ptrn[N]; // Text, pattern
int b[N], n, m; // Back table, length of txt, length of ptrn
vector<int> ans; // Vector that stores the starting index of the matches

void build() {
    int i=0, j=-1; b[0]=-1;
    while(i < m) {
        while(j >= 0 && ptrn[i] != ptrn[j]) j = b[j];
        ++i, ++j;
        b[i] = j;
    }
}

void search() {
    int i=0, j=0;
    while (i<n) {
        while(j >=0 && txt[i] != ptrn[j]) j = b[j];
        ++i, ++j;
        if (j == m) ans.push_back(i - j), j = b[j];
    }
}
