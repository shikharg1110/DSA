#include<iostream>
using namespace std;

bool linearSearch(int arr[][4], int search, int row, int col) {
    for(int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
        {
            if(search == arr[i][j])
            return 1;
        }
    }
    return 0;
}

int sumRow(int arr[][4], int row, int col) {
    int sum[row] = {0};
    int k = 0, max = INT_MIN, rmax;
    for(int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
        {
            sum[k] += arr[i][j];
            if(sum[k] > max)
            {
                max = sum[k];
                rmax = i;
            }
        }
        k++;
    }
    cout<<"Row wise sum: "<<endl;
    for (int i = 0; i < k; i++)
    {
        cout<<sum[i]<<" ";
    }  
    cout<<endl;
    cout<<"Max sum value: "<<max<<"\nMax sum row: "<<rmax<<endl;
    return 0;
}
int sumCol(int arr[][4], int row, int col) {
    int sum[col] = {0};
    int k = 0, min = INT_MAX, cmin, i, j;
    for(i = 0; i < col; i++) {
        for (j = 0; j < row; j++)
        {
            sum[k] += arr[j][i];
        }
        if(sum[k] < min)
        {
            min = sum[k];
            cmin = i;
        }
        k++;
    }
    cout<<"Col wise sum: "<<endl;
    for (int i = 0; i < k; i++)
    {
        cout<<sum[i]<<" ";
    }
    cout<<endl;
    cout<<"Min sum value: "<<min<<"\nMin sum col: "<<cmin<<endl;
    return 0;
}

int main()
{
    int arr[3][4];

    // Taking row-wise Input: 
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin>>arr[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<arr[i][j]<< " ";
        }
        cout<<endl;
    }

    // Sum of row-wise array:
    sumRow(arr, 3, 4);
    // Sum of row-wise array:
    sumCol(arr, 3, 4);

    /*
    // lINEAR SEARCH IN 2D ARRAY
    int search;
    cout<<"Enter the element to be search: ";
    cin>>search;

    if(linearSearch(arr, search, 3, 4)) {
        cout<<"present"<<endl;
    }
    else 
        cout<<"not present"<<endl;

    */

    // Taking column-wise as Input
    /*
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>arr[j][i];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<arr[i][j]<< " ";
        }
        cout<<endl;
    }
    */
    
    return 0;
}