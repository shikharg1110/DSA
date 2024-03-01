#include <iostream>
using namespace std;
int main()
{
    int n = 0, minIndex = 0;
    cout << "enter the size of array: \n";
    cin >> n;
    int arr[n];
    cout << "enter the element of array: \n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Selection sort
    for (int i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
    cout << "The sorted arry: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}