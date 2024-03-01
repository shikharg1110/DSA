/*
let's the array = [1,2,2,1,1,3]
The occurence of each number in the array is different
for example, 1 --> 3
             2 --> 2
             3 --> 1
Outpur -----> true
let's the array = [1,2]
The occurence of each number in the array is not different
for example, 1 --> 1
             2 --> 1
Output -----> false
*/

#include<iostream>
using namespace std;
void sort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}
int main()
{
    int a[20], b[20];
    int size, i, j, c=1, k=1, d=0;
    cin>>size;
    for (int i = 0; i < size; i++)
        cin>>a[i];
    sort(a, size);
    for (i = 0; k < size;)
    {
        if(a[i]==a[k])
        {
            c++, k++;
            if(k==size)
            b[d]=c;
            continue;
        }
        b[d]=c;
        d++;
        i=k;
        k++;
        c=1;
    }
    if(a[size-2]!=a[size-1])
    b[d]=1;
    c=0;
    for(i=0; i<k ;i++)
    {
        if(b[0]==b[i])  //Check for the same occurence
        c++;            //Increase the value if it has same occurence
    }
        if(c>0)
        cout<<"False"<<endl;
        else
        cout<<"True"<<endl;
    return 0;
}