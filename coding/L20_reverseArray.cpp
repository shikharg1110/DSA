/* // Reversing the array

#include<iostream>
using namespace std;
int main()
{
    int a[100];
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    cout<<"\nEnter the elements in array: ";
    for (int i = 0; i < size; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < size/2; i++)
    {
        swap(a[i], a[size-i-1]);
    }
    cout<<"\nThe elements in array: ";
    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<" ";
    }
    
    
    return 0;
}

*/

// REVERSING THE ARRAY AFTER THE M'th POSITION

#include<iostream>
using namespace std;
int main()
{
    int a[100];
    int size, pos, k = 0;
    cout<<"Enter the size of array: ";
    cin>>size;
    cout<<"\nEnter the elements in array: ";
    for (int i = 0; i < size; i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the position after which you want to reverse the array: ";
    cin>>pos;
    for (int i = pos+1; i < size; i++)
    {
        swap(a[i], a[size-k-1]);
        k++;
        if(k == (size - pos)/2)
        break;
    }
    cout<<"\nThe elements in array: ";
    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<" ";
    }
    
    return 0;
}