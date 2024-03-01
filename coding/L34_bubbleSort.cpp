#include<iostream>
using namespace std;
void bubble(int *a, int n) {
    if(n == 0 || n == 1)
    return;
    if(a[0] > a[1]) 
        swap(a[0], a[1]);
    return bubble(a+1, n-1);
}
void sorting(int *a, int n) {
    for(int i = n; i>=0; i--) {
        bubble(a, n);
    }
}
int main()
{
    int a[10];
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sorting(a, n);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
    return 0;
}