#include <bits/stdc++.h>
#define LIMIT 200
using namespace std;
bitset<LIMIT> bs;
vector<int> primes;

void makeprimes(){
    bs.set();
    bs[0] = bs[1] = 0;
    for(int i = 2; i < LIMIT; i++) if( bs[i] ){
        for(int j= i * i; j <= LIMIT ;j+=i) bs[j] = 0;
        primes.push_back(i);
    }
}

bool isPrime(int i){ return bs[i];}

int main(){
    makeprimes();
    int size = primes.size();
    for(int i = 0; i < size; i++){
        cout << primes[i] << endl;
    }
}
