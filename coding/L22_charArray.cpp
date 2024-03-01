#include<iostream>
using namespace std;
int main()
{
    char ch[10];

    // Don't enter using the below code in char array
    /*  
            for (auto &&i : ch)
            {
                cin>>i;
            }
    */
    cin>>ch;
    // char ch[10] = {'B', 'A', 'B', 'B', 'A', 'R', 'A', 'B'};

    // Don't enter using the below code in char array
    /*
            for (auto &&i : ch)
            {
                cout<<i<<" ";
            }
    */
    cout<<ch<<endl;

    // Length of char array
    int k = 0;
    while(ch[k] != '\0') {
        // cout<<ch[k]<<" ";
        k++;
    }
    cout<<"Length of the char array: "<<k<<endl;

    // Reverse of char array
    for(int i = 0; i<k/2; i++) {
        swap(ch[i], ch[k-i-1]);
    }
    cout<<ch<<endl;
    
    return 0;
}