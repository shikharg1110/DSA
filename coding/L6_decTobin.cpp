#include <iostream>
#include <cmath>
using namespace std;
int rev(int n);
int check(int n);
int main()
{
    int n, num = 0;
    for (int j = 0; j < 10; j++)
    {
        num=0;
        cin >> n;
        int i = check(n);
        while (n != 0)
        {
            int rem = n % 2;
            num = num * 10 + rem;
            n = n / 2;
        }
        cout << rev(num) * pow(10, i) << endl;
    }
    return 0;
}

int rev(int n)
{
    int r = 0, s = 0;
    while (n != 0)
    {
        r = n % 10;
        s = s * 10 + r;
        n = n / 10;
    }
    return s;
}

int check(int n)
{
    int r = 0;
    for (int i = 1;; i++)
    {
        if (n % 2 == 0)
            r++;
        else
            break;
        n = n / 2;
    }
    return r;
}