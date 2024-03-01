#include<iostream>
using namespace std;
/*For normal coder*/
/*
string reverse(string s, int size) {
    if(size <= 0)
        return "";
    else
        return s[size-1] + reverse(s, size - 1);
}
int main()
{
    string s = "helloworld";
    cout<<reverse(s, s.size())<<endl;
    return 0;
}
*/
/*For genius coder using 2 pointer approach*/
void reverse(string &s, int i) {
    cout<<s<<endl;
    if( i > s.length()-i-1)
        return;
    swap(s[i], s[s.length()-i-1]);
    i++;

    reverse(s, i);
}
int main()
{
    string s = "helloworld";
    reverse(s, 0);
    cout<<s<<endl;
    return 0;
}
