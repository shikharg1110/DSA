#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n, s = 0, i = 0;
    cin>>n;
    while(n!=0)   // Used to get same number
    {
        int r = n % 10;
        s = r * pow(10, i) + s;
        n = n / 10;
        i++;
    }
    cout<<s;
    return 0;
}


    // while(n!=0)      // Used for reverse the number
    // {
    //     int r = n % 10;
    //     s = s * 10 + r;
    //     n = n / 10;
    //     i++;
    // }