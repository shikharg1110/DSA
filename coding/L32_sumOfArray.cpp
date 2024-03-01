#include<iostream>
using namespace std;
int Sum(int *arr, int size) {
    if(size == 0)
        return 0;
    else if(size == 1)
        return arr[0];
    else
        return Sum(arr + 1, size - 1) + arr[0];
}
int main()
{
    int n;
    cin>>n;
    int arr[10];
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    cout<<Sum(arr, n)<<endl;
    return 0;
}