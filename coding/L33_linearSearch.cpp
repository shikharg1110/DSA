#include<iostream>
using namespace std;
int linear(int *arr, int size, int key) {
    if(size == 0)
        return -1;
    else if(arr[0] == key)
        return size;
    else 
        return linear(arr + 1, size -1, key);

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
    if(linear(arr, n, key) != -1)
        cout<<"Found at index "<<n - linear(arr, n, key)<<endl;
    else
        cout<<"not Found"<<endl;
    return 0;
}