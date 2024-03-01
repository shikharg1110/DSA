#include<iostream>
using namespace std;
int main()
{
    char *ch = new char;
    int *arr = new int[5];
    cin>>ch;
    cout<<*ch;
    for (int i = 0; i < 5; i++)
    {
        cin>>*(arr + i);
    }
    for (int i = 0; i < 5; i++)
    {
        cout<<*(arr + i);
    }
    delete []arr;
    delete ch;
    return 0;
}