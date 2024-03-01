#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int N = 1000; // 10^6
    vector<bool> prime(10000, true);
    for (int i = 2; i*i <= N; i++)
    {
        if(prime[i] == true) {
            for (int j = i*i; j <= N; j=j+i)
            {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i < N; i++)
    {
        if(prime[i] == true)
        cout<<i<<" ";
    }
    
    
    
    return 0;
}