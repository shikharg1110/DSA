#include<iostream>
using namespace std;
int main()
{
    int row;
    cin>>row;
    int colSize[10];
    int **arr = new int*[row];
    for (int i = 0; i < row; i++)
    {
        int col = 0;
        cout<<"Enter the number of col: ";
        cin>>col;
        colSize[i] = col;
        arr[i] = new int[col];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colSize[i]; j++)
        {
            cin>>arr[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colSize[i]; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}