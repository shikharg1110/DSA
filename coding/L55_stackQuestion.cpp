#include<iostream>
#include<stack>
using namespace std;
int main()
{
    string str = "shikhar";
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }

    string ans = "";
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    cout<<"Answer: "<<ans<<endl;
    
    return 0;
}