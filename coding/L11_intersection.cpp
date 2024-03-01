// Intersection of two sorted array
// The answer should be printed as it occur on the array
// Print -1 if no element is common between them

/*
n = 6, m = 4
1 2 2 2 3 4
2 2 3 3
n = 3, m = 2
1 2 3
4 5
Output --> 2 2 3
        -1
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0, m = 0, i = 0, j = 0;
    cin>>n>>m;
    int arr1[n], arr2[m];
    for ( i = 0; i < n; i++)
        cin>>arr1[i];
    for ( i = 0; i < m; i++)
        cin>>arr2[i];
    vector<int>ans;
    while(i < n && j < m)    //This type of solving is known as two pointer approach in one loop
    {
        if(arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i]<arr2[j])
        i++;
        else
        {
            j++;
        }
    }
    for ( i = 0; i <= ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}