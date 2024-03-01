#include<iostream>
using namespace std;
/*For normal coder*/
/*
int power(int a, int b) {
    if(b == 0)
    return 1;
    else
    return a*power(a,b-1);
}
int main()
{
    int a = 0, b = 0;
    cin>>a>>b;
    cout<<power(a,b)<<endl;
    return 0;
}
*/
/*For genius coder using binary approach method*/
int power(int a, int b) {
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    if(b%2 == 0) // b= Even a^b = a^(b/2) *a^(b/2);
        return power(a, b/2)*power(a,b/2);
    else //         b= odd a^b = a * a^(b/2) *a^(b/2);
        return a * power(a, b/2)*power(a,b/2);
}
int main()
{
    int a = 0, b = 0;
    cin>>a>>b;
    cout<<power(a,b)<<endl;
    return 0;
}
