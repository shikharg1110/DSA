#include<iostream>
using namespace std;
int setBits(int n);
int main()
{
    int a, b, ans=0;
    cin>>a>>b;
    cout<<setBits(a)+setBits(b)<<endl;
    return 0;
}
int setBits(int n)
{
    int c=0;
    while(n!=0)
    {
        if(n&1==1)
        c++;
        n=n>>1;
    }
    return c;
}