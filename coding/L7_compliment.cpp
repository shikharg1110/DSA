// 
// LEETCODE:- 1009
//
// Here the question is find the compliment of decimal number
// eg. 5 -> 101   ----compliment----> 010    ----decimal-----> 2
// Output: 2

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n, r=0, s=0, i=0;
    cin>>n;
    while(n != 0) {
        r = n & 1;
        if(r == 1)
        s = s + 0*pow(10, i);
        else
        s = s + 1*pow(10, i);
        n = n>>1;
        i++;
    }
    cout<<s;
    return 0;
}