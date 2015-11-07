#include <iostream>

using namespace std;

int mdc(int a, int b)
{
    if( b == 0)
        return a;
    if(a == 0)
        return b;

    return mdc( (a > b) ? b : a, (a > b) ? (a % b) : (b % a) );
}
int mdcnaum(int a,int b){
    return b?mdcnaum(b,a%b):a;
}   
int main()
{
    int m,n;
    cin >> m >> n;
    cout << mdc(m,n) << endl;
    return 0;
}
