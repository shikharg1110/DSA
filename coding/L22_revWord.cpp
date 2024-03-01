// In this program, we are going to reverse each and every word in the given sentence.
// For example, s = "Hello everyone, My name is Shikhar. I am 21 years old."
// Output, Result = "olleH enoyreve, yM eman si rahkihS. I ma 12 sraey dlo."

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string revWord(string s);
int main()
{
    string s="", word="", rev="";
    getline(cin, s);
    s = s+" ";
    int i = 0;
    for(i = 0; i <= s.length(); i++) {
        if(s[i] != ' ') {
            word = word + s[i];
        }
        else {
            rev = rev + revWord(word)+" ";
            word = "";
        }
    }
    cout<<rev<<endl;
    return 0;
}

string revWord(string s) {
    reverse(s.begin(), s.end());
    return s;
}