/*  Take an array and swap the two number 
    eg. arr= [1,2,3,4,5,6];
    After swapping,
        arr= [2,1,4,3,6,5];
*/


#include<iostream>
using namespace std;
void input(int a[], int n);
void output(int a[], int n);
void alt(int a[], int n);
int main()
{
    int size;
    cin>>size;
    int arr[20];
    input(arr, size);
    alt(arr, size);
    output(arr, size);
    return 0;
}
void input(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cin>>a[i];
}
void output(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void alt(int a[], int n)
{
    for (int i = 1; i < n; i+=2)
    {
        swap(a[i-1],a[i]);
    }
}