#include <iostream>
using namespace std;
int main()
{
    int a[10], b[10], c[20];
    int n, m, i = 0, j = 0, k = 0;
    cout << "Enter the size of Array A: ";
    cin >> n;
    cout << "Enter the size of Array B: ";
    cin >> m;

    cout << "\nEnter the elements in array A: ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "\nEnter the elements in array B: ";
    for (i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = b[j++];
        }
    }

    while (j < m)
    {
        c[k++] = b[j++];
    }
    while (i < n)
    {
        c[k++] = a[i++];
    }

    cout << "\nThe elements in array: ";
    for (i = 0; i < k; i++)
    {
        cout << c[i] << " ";
    }

    return 0;
}