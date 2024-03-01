/*  
    LEETCODE:- 191
    
    Check the number input has how many 1's in their binary form
    For example: Input n = 7 (00000000000000000000000000000111)  in 32 bit
                 Output = 3

    For example: Input n = 13 (00000000000000000000000000001101)  in 32 bit
                 Output = 3

    For example: Input n = 36 (00000000000000000000000000100100)  in 32 bit
                 Output = 2
*/

#include<iostream>
using namespace std;
int main()
{
    int n, count=0;
    cin>>n;
    while(n!=0) {
        if(n&1)
        count++;
        n = n>>1;
    }
    cout<<count;
    return 0;
}