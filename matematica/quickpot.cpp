#include <iostream>
using namespace std;
#define SIZE 4
int quickpot(int a, int b){
    if(b==0)
        return 1;
    int hold = quickpot(a,b/2);
    return hold * hold * (b%1==1?a:1);
}
int quickpot(int a, int b, int mod){
    if(b==0)
        return 1 % mod;
    int hold = quickpot(a%mod,b/2) % mod;
    return (( (hold*hold) % mod )*( b&1 ? a % mod:1 )) % mod;
} 
void quickpotmatriz(int mat[SIZE][SIZE], int t, int res[SIZE][SIZE]){
    int hold[SIZE][SIZE];
    for(int i = 0; i< SIZE; i++) for(int j = 0; j < SIZE; j++)
        if (i == j) res[i][j] = 1;
        else res[i][j] = 0;
    int m = 1000000007;
    while(t) {
        if (t&1) {
            for(int i = 0; i< SIZE; i++) for(int j = 0; j < SIZE; j++) {
                hold[i][j] = 0;
                for(int k = 0; k < SIZE; ++k)
                    hold[i][j] += res[i][k]*mat[k][j] % m;
                }
            for(int i = 0; i< SIZE; i++) for(int j = 0; j < SIZE; j++)
                res[i][j] = hold[i][j] % m;
            --t;
        } else {
            for(int i = 0; i< SIZE; i++) for(int j = 0; j < SIZE; j++) {
                hold[i][j] = 0;
                for(int k = 0; k < SIZE; ++k)
                    hold[i][j] += mat[i][k]*mat[k][j] % m;
                }
            for(int i = 0; i< SIZE; i++) for(int j = 0; j < SIZE; j++)
                mat[i][j] = hold[i][j] % m;
            t /= 2;
        }
    }
}
int main()
{
    int x[SIZE][SIZE];
    int y[SIZE][SIZE];
    int n;
    for(int i = 0; i < SIZE; i++)for(int j = 0; j < SIZE;j++) cin >> x[i][j];
    cin >> n;
    quickpotmatriz(x,n,y);
    for(int i = 0; i < SIZE; i++) {for(int j = 0; j < SIZE;j++) cout << y[i][j]; cout << endl;}

}

