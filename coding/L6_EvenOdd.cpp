#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n&1 == 1)
        cout<<"Odd"<<endl;
    else
    cout<<"Even"<<endl;
    return 0;
}

// n & 1 = 0 if even 
// n & 1 = 1 if odd