#include <bits/stdc++.h>
#define LIMIT 10
using namespace std;
int comb(int a, int b){
    int res = 1;
    if( b > a /2)
        b = a - b;
    for(int i = 1; i <= b;i++){
        res *= a - b + i;
        res /= i;
    }
    return res;
}
vector<vector<int> > combs;
void dpcombs(){
    vector<int> first;
    first.push_back(1);
    combs.push_back(first);
    for(int i = 1; i<=LIMIT;i++){
        vector<int> temp;
        temp.push_back(1);
        for(int j = 1; j < i; j++){
            temp.push_back( combs[i-1][j] + combs[i-1][j-1] );
        }
        temp.push_back(1);
        combs.push_back(temp);
    }
}
int catalan(int a){
    return comb(2*a,a) / (a + 1);
}
vector< int> catalans;
void dpcatalan(){
    catalans.push_back(1);
    for(int i = 0; i < LIMIT; i++){
        int temp = catalans[i];
        temp *= (2*i+2)*(2*i+1)/(i+2)/(i+1);
        catalans.push_back(temp);
    }
}
int main(){
    int a,b;
    cin >> a >> b;
    cout << comb(a,b) << endl;
    dpcombs();
    cout << combs[a][b] << endl;
    cout << catalan(3) << endl;
    dpcatalan();
    cout << catalans[3] << endl;
    return 0;
}
