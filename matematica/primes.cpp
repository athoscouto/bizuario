#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int N = 1e7+1;
bool bs[N];

void sieve(){
    for(int i = 2; i < N; i++) if(!bs[i]) for(int j = i*i; j <= N; j+=i) bs[j] = 1;
}

int mdc(int a,int b) {return b ? mdc(b, a % b) : a;}

int main(){
    sieve();
    int size = primes.size();
    for(int i = 0; i < size; i++){
        cout << primes[i] << endl;
    }
}
