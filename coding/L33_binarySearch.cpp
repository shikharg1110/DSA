#include<iostream>
using namespace std;
int binary(int *arr, int s, int e, int key) {
    if(s > e)
        return -1;
    int mid = (s + e) /2;
    if(arr[mid] == key)
        return mid;
    else if(arr[mid] < key)
        return binary(arr, mid + 1, e, key);
    else
        return binary(arr, s, mid - 1, key);
}
int main()
{
    int n;
    cin>>n;
    int arr[10];
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    int key;
    cin>>key;
    int s = 0, e = n-1;
    if(binary(arr, s, e, key) != -1)
        cout<<"Found at index "<<binary(arr, s, e, key)<<endl;
    else
        cout<<"not Found"<<endl;
    return 0;
}