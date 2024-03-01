#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int N = 1000000;
vector<bool> sieve(1000001, true);

void createSieve() {
    for (int i = 2; i*i <= N; i++)
    {
        if(sieve[i] == true) {
            for (int j = i*i; j <= N; j=j+i)
                sieve[j] = false;
            
        }
    }
}

vector<int> generatePrimes(int N) {
    vector<int> ds;
    for (int i = 2; i <= N; i++)
    {
        if(sieve[i] == true)
            ds.push_back(i);
    }
    return ds;
}

int main()
{
    createSieve();
    int t;
    cin>>t;
    while(t--) {
        int l, r;
        cin>>l>>r;

        // Step 1: Generate all prime till sqrt(r)
        vector<int> primes = generatePrimes(sqrt(r));

        // Step 2: Create a dummy array of size r - l + 1 and make everyone as 1
        int dummy[r-l+1];
        for (int i = 0; i < r-l+1; i++)
        {
            dummy[i] = 1;
        }

        // Step 3: for all prime number marks all its multiple as false
        for (auto &&i : primes)
        {
            int firstMultiple = (l/i) * i;
            if(firstMultiple < l)
                firstMultiple += i;

            for (int j = max(firstMultiple, i*i); j <= r; j+=i)
            {
                dummy[j-l] = 0;
            }
            
        }
        
        // Step 4: get all prime
        for (int i = l; i <=r; i++)
        {
            if (dummy[i-l] == 1)
            {
                cout<<i<<" ";
            }
            
        }
        
        
    }
    return 0;
}