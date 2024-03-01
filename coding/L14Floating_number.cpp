#include<iostream>
using namespace std;

long long int binary(int n) {
        int s = 0, e = n;
        long long int mid = s + (e - s)/2, ans = -1;
        while(s<=e) {
            long long int square = mid*mid;
            if(square == n)
            return mid;
            else if(square < n){
                ans = mid;
                s = mid + 1;
            }
            else
            e = mid - 1;
            mid = s + (e-s)/2;
        }
        return ans;
    }

double more(int n, int precision, int temp) {
    double factor = 1, ans = temp;
    for (int i = 0; i < precision; i++)
    {
        factor  = factor / 10;
        for (double j = ans; j*j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    int temp = binary(n);
    cout<<"Ans is= "<< more(n, 3, temp);
    return 0;
}