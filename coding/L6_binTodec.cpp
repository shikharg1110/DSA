#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, i = 0, ans = 0;
    cin >> n;
    while (n != 0)
    {
        int digit = n % 10;
        ans = pow(2, i) * digit + ans;
        n = n / 10;
        i++;
    }
    cout << ans << endl;
    return 0;
}