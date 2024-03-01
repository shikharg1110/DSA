#include<iostream>
using namespace std;

/* For normal coder */
/*
int main()
{
    string digit[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int n;
    cin>>n;
    int s=0;
    while(n!=0) {
        int r = n % 10;
        s = s * 10 + r;
        n = n / 10;
    }
    n = s;
    while(n!=0) {
        int r = n%10;
        cout<<digit[r]<<" ";
        n = n/10;
    }
    return 0;
}
*/

/*For Recusive Coder*/
void sayDigit(int n, string arr[]) {
    if(n == 0)
        return ;
    else
    sayDigit(n/10, arr);
    cout<<arr[n%10]<<" ";
}
int main() {
    int n;
    cin>>n;
    string digit[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    sayDigit(n, digit);

}