#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, r, num = 0;
    int i = 0;
    cin >> n;
    while (n != 0)
    {
        r = n & 1;
        num = r * pow(10, i) + num; //This will bring the reverse of the number
        n = n >> 1;
        i++;
    }
    cout << num << endl;
    return 0;
}