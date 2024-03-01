#include<iostream>
using namespace std;
int main()
{
    int n, i = 0, j = 0, k = 0;
    cin>>n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    i=0, k=n-1;
    while(i<k) {
        while(arr[i]==0 && i<k)
        i++;
        while(arr[k]!=0 && i<k)
        k--;
        if(i<k)
        {
            swap(arr[i], arr[k]);
            i++, k--;
        }
    }
    for ( i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    i=0, k=n-1;
    while(j<k) {
        while(arr[i]==0 && i<k)
        i++;
        j=i+1;
        while(arr[j]==1 && j<k)
        j++;
        while(arr[k]==2 && j<k)
        k--;
        if(j<k)
        {
            swap(arr[j], arr[k]);
            j++, k--;
        }
    }
    for ( i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    
    return 0;
}