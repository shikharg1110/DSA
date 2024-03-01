// 212! % 10^9 + 7 = ?

#include<iostream>
using namespace std;
int main()
{
    int num = 212;
    int mod = 1000000007;
    int res= 1;
    for(int i = 2; i <= 212; i++) {
        res = (res%mod * i%mod)%mod;
    }
    cout<<res<<endl;
    return 0;
}