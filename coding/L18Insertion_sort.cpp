#include <iostream>
using namespace std;
int main()
{
    int n = 0, temp = 0, i = 0, j = 0;
    cout << "enter the size of array: \n";
    cin >> n;
    int arr[n];
    cout << "enter the element of array: \n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Insertion sort
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > temp)
                arr[j+1] = arr[j];
            else 
                break; 
        } 
        // After running of the upper loop at last condition value get incresed and hence we write arr[j+1] = temp; 
        arr[j+1] = temp;
    }
    cout << "The sorted arry: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}