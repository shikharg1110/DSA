#include<iostream>
using namespace std;
bool palindrome(string &s, int i) {
    if(i == s.length()/2)
        return true;
    else if(s[i] == s[ s.length()-i-1 ])
        return palindrome(s, i+1);
    else
        return false;
}
int main()
{
    string s = "toohottohoot";
    
    cout<<palindrome(s, 0)<<endl;
    return 0;
}
