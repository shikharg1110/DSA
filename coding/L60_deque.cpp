#include<iostream>
#include<queue>
using namespace std;
int main()
{
    deque<int> d;
    d.push_back(1);
    d.push_front(2);
    d.pop_back();
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
    return 0;
}