// Implementation of k queue in some size of array

#include <iostream>
using namespace std;

class kQueue {
    public:
        int n;
        int k;
        int *front;
        int *rear;
        int *arr;
        int *next;
        int freespot;

        kQueue(int n, int k) {
            this->n = n;
            this->k = k;
            front = new int[k];
            rear = new int[k];
            for(int i = 0; i< k; i++) {
                front[i] = -1;
                rear[i] = -1;
            }

            next = new int[n];
            for (int i = 0; i < n; i++) {
                next[i] = i+1;
            }
            next[n-1] = -1; // -1 means no next element
            
            arr = new int[n];
            freespot = 0;
        }

        void enqueue(int data, int qn) {
            // overflow
            if(freespot == -1) {
                cout << "Overflow" << " ";
                cout << "NO empty space is present" << endl;
                return;
            }

            // find first free index
            int index = freespot;

            // update free spot
            freespot = next[index];

            // check whether the first element 
            if(front[qn - 1] == -1) {
                front[qn-1] = index;
            } 
            else {
                // link new element to prev element
                next[rear[qn-1]] = index;
            }  

            // update next
            next[index] = -1;   

            // update rear
            rear[qn-1] = index;

            // push data and element
            arr[index] = data;
        }

        int dequeue(int qn) {
            // underflow
            if(front[qn-1] == -1) {
                cout << "Underflow" << " ";
                cout << "Queue " << qn << " is empty" << endl;
                return -1;
            }  
            // find index to pop
            int index = front[qn-1];

            // front ko aage badhao
            front[qn-1] = next[index];

            // freespot ko manage karo
            next[index] = freespot;

            // update freespot
            freespot = index;

            return arr[index];
        }

};

int main() {
    kQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15, 1);

    q.enqueue(20, 2);
    q.enqueue(25, 1);

    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;


    cout<<q.dequeue(2 )<<endl;
    return 0;
}