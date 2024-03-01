#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter the size of array: \n";
    cin >> n;
    int arr[n];
    cout << "enter the element of array: \n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    cout << "The sorted arry: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}