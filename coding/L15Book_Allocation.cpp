#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>arr, int n, int m, int mid) {
    int studentCount = 1, pageSum = 0;
    for(int i = 0; i < n; i++) {
        if(pageSum + arr[i] <= mid)
            pageSum += arr[i];
        else {
            studentCount++;
            if(studentCount > m || arr[i] > mid)
                return false;
            pageSum = arr[i];
        }
    }
    return true;
}

int allocate (vector <int> arr, int n, int m) {
    int s = 0, sum = 0, ans = -1;
    for(int i = 0; i < n; i++) 
        sum +=arr[i];
    int e  = sum, mid = s + (e-s)/2;
    while(s<e) {
        if(isPossible(arr, n, m, mid))
        {
            ans=mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
        mid = s + (e-s)/2;
    }
    return ans;
}


int main()
{
    int n, m, ans, value;
    cin>>n>>m;
    vector<int>arr;
    for (int i = 0; i < n; i++)
    {
        cin>>value;
        arr.push_back(value);
    }
    ans = allocate(arr, n, m);
    cout<<ans;
    return 0;
    
    return 0;
}