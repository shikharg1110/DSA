// In this program, reverse the position of the word in the sentence.

// For example, s = "Hello everyone, My name is Shikhar. I am 21 years old."
// Output, Result = "old years 21 am I. Shikhar is name My, everyone Hello."

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string revWord(string s);
int main()
{
    string s = "", rev = "";
    getline(cin, s);
    s= " " + s;
    int pos = 0, i = 0, len = 0;
    for (int i = s.length(); i >= 0; i--)
    {
        len++;
        if(s[i] == ' ') {
            rev = rev + s.substr(i, len);
            len = 0;
        }
    }
        cout<<rev;
    
    return 0;
}