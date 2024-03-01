#include<iostream>
using namespace std;
void input(int a[], int size);
void max(int a[], int size);
void min(int a[], int size);
int main()
{
    int size;
    cin>>size;
    int num[100];
    input(num, size);
    min(num, size);
    max(num, size);
    return 0;
}
void input(int a[], int size)
{
    for (int i = 0; i < size; i++)
        cin>>a[i];
}
void max(int a[], int size)
{
    int max=INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if(a[i]>max)
        max=a[i];
    }
    cout<<"Max= "<<max<<endl;
}
void min(int a[], int size)
{
    int min=INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if(a[i]<min)
        min=a[i];
    }
    cout<<"Min= "<<min<<endl;
}