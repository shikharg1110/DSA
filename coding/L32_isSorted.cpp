#include<iostream>
using namespace std;

void isSorted(int arr[], int n) {
    if(n < 0) {
        cout<<"Sorted"<<endl;
        return;
    }
    else if(arr[n] >= arr[n-1])
        return isSorted(arr, n-1);
    else
        cout<<"Not Sorted"<<endl;
}
int main()
{
    int n;
    cin>>n;
    int arr[10];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    isSorted(arr, n-1);
    
    return 0;
}