// In the given array numbers may be multiple 
// The number we have found the first and last occurence is given
// Return the first and last occurence, if no. is not present then return -1
/*
    size = 6, number = 3
    0 5 5 6 6 6
    Output - > -1 -1

    size = 8, number = 2
    0 0 1 1 2 2 2 2
    Output - > 4 7

    size = 1, number = 2
    2
    Output - > 0 0
*/

// The code given below is the brute force as in the first while loop takes O(log n) time complexity
// But the second while loop takes O(n) time complexity
// So the best way is to find left occurrence using log n complexity and same for last occurrence

/*First occurrence
while(s<=e) {
        m=s+(e-s)/2;
        if(arr[m] == k)
        {
            ans=m;
            e=m-1;
        }    
        else if(arr[m] < k)
        s=m+1;
        else
        e=m-1;
    }
    Now ans contain left most occurrence
*/

/*Last occurrence
while(s<=e) {
        m=s+(e-s)/2;
        if(arr[m] == k)
        {
            ans=m;
            s=m+1;
        }    
        else if(arr[m] < k)
        s=m+1;
        else
        e=m-1;
    }
    Now ans contain right most occurrence
*/
#include<iostream>
using namespace std;
int main()
{
    int size, k, s, m, e, flag=-1, f=0, l=0;
    cout<<"Enter the size of array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the element in the array: ";
    for (int i = 0; i < size; i++)
        cin>>arr[i];
    cout<<"Enter the element to be found: ";
    cin>>k;
    s=0, e=size-1;
    while(s<=e) {
        m=s+(e-s)/2;
        if(arr[m] == k)
        {
            flag=m;
            cout<<flag<<endl;
            break;
        }    
        else if(arr[m] < k)
        s=m+1;
        else
        e=m-1;
    }
    if(flag==-1)
    {
        cout<<flag<<" "<<flag<<endl;
        return 0;
    }
    while(l==0 || f==0) {

        // For the first occurence
        if(arr[m] ==k)
            m--;
        else
            l=1;

        // For the last occurence
        if(arr[flag]==k)
            flag++;
        else
            f=1;
    }
    cout<<m+1<<" "<<flag-1<<endl;
    
    return 0;
}