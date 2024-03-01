#include <iostream>
#include <array>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    /* ==== ARRAY STL ====*/
    // int basic[] = {1, 2 ,3};
    // array<int, 3> a = {1, 2, 3};
    // int size = a.size();
    // cout<<"Size of the array: "<<size<<endl;
    // cout<<"\nElement at 2nd index: "<<a[2]<<endl<<endl;
    // for (int i = 0; i < size; i++)
    // {
    //     cout<<"Element at "<<i<<" index: "<<a[i]<<endl;
    // }
    // cout<<"\nElement at 1rd index: "<<a.at(1)<<endl;
    // cout<<"\nEmpty or not: "<<a.empty()<<endl;
    // cout<<"First element: "<<a.front()<<endl;
    // cout<<"Last element: "<<a.back()<<endl;


    /* ==== VECTOR ==== */
    // vector<int> v;
    // /* At the beginning the vector has 0 size and 0 capacity*/
    // cout<<"Capacity at beginning: "<<v.capacity()<<endl;
    // cout<<"Size at beginning: "<<v.size()<<endl;
    // v.push_back(1);
    // cout<<"\nCapacity after entering 1 element: "<<v.capacity()<<endl;
    // cout<<"Size after entering 1 element: "<<v.size()<<endl;
    // v.push_back(2);
    // cout<<"\nCapacity after entering 2 element: "<<v.capacity()<<endl;
    // cout<<"Size after entering 2 element: "<<v.size()<<endl;
    // v.push_back(3);
    // cout<<"\nCapacity after entering 3 element: "<<v.capacity()<<endl;
    // cout<<"Size after entering 3 element: "<<v.size()<<endl;
    // v.push_back(4);
    // cout<<"\nCapacity after entering 4 element: "<<v.capacity()<<endl;
    // cout<<"Size after entering 4 element: "<<v.size()<<endl;
    // v.push_back(5);
    // cout<<"\nCapacity after entering 5 element: "<<v.capacity()<<endl;
    // cout<<"Size after entering 5 element: "<<v.size()<<endl;

    // cout<<"\nElement at 1rd index: "<<v.at(1)<<endl;

    // cout<<"\nFirst element: "<<v.front()<<endl;
    // cout<<"Last element: "<<v.back()<<endl;

    // cout<<"\nBefore pop"<<endl;
    // for (auto &&i : v)
    // {
    //     cout<<i<<" ";
    // }cout<<endl;
    // cout<<"\nCapacity before pop: "<<v.capacity()<<endl;
    // cout<<"Size before pop: "<<v.size()<<endl;
    // v.pop_back();
    // cout<<"\nAfter pop"<<endl;
    // for (auto &&i : v)
    // {
    //     cout<<i<<" ";
    // }cout<<endl;
    // cout<<"\nCapacity after pop: "<<v.capacity()<<endl;
    // cout<<"Size after pop: "<<v.size()<<endl;
    
    // v.clear();
    // cout<<"\nCapacity after clear: "<<v.capacity()<<endl;
    // cout<<"Size after clear: "<<v.size()<<endl;

    // vector<int> a(5,1); // inititalise all the 5 elements of a with 1
    // cout<<"\nPrint a"<<endl;
    // for (auto &&i : a)
    // {
    //     cout<<i<<" ";
    // }cout<<endl;

    // vector<int> last(a); // Copy all the element of a
    // cout<<"\nPrint last"<<endl;
    // for (auto &&i : last)
    // {
    //     cout<<i<<" ";
    // }cout<<endl;


    /* ==== Dequeue ==== */
    deque<int> d;
    d.push_back(1);
    d.push_front(2);
    for (auto &&i : d)
    {
        cout<<i<<" ";
    }cout<<endl;
    d.pop_back();
    for (auto &&i : d)
    {
        cout<<i<<" ";
    }cout<<endl;
    

    
}