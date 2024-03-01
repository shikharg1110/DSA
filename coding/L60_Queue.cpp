#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int>q;
    q.push(11);
    cout<<"front: "<<q.front()<<endl;
    cout<<"back: "<<q.back()<<endl;
    q.push(15);
    q.push(13);

    return 0;
}