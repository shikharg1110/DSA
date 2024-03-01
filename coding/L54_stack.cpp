#include<iostream>
#include<stack>
using namespace std;

// using array
class Stack {
    // properties
    public: 
        int *arr;
        int top;
        int size;

    // behaviour
    // This is constructor used to prior work for stack
    Stack (int size) { 
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {
        // Check for space availabilty of 1 space
        if(size - top > 1) {
            top++;
            arr[top] = element;
        }
        else
            cout<<"Stack Overflow"<<endl;
    }

    void pop() {
        if( top >= 0) 
            top--;
        else
            cout<<"Stack Underflow"<<endl;
    }

    int peek() {
        if(top >= 0)
            return arr[top];
        else {
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
    }

    bool isEmpty() {
        if( top == -1)
            return true;
        else
            return false;
    }

};

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    
};

// using LL
class StackLL {
    // properties
    public: 
    Node *top; //head
    int size;
    int currSize;

    // behaviour
    StackLL(int size) {
        this->size = size;
        top = NULL;
        currSize = 0;
    }

    void push(int element) {
        if(currSize < size)
        InsertAtHead(top, element, size, currSize);
        else
        cout<<"Stack overflow"<<endl;
    }

    void pop() {
        if(currSize == 0)
            cout<<"Stack is empty"<<endl;
        else {
            Node *temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
            currSize--;
        }
    }

    int peek() {
        if(currSize == 0 || top == NULL) {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        else
            return top->data;
    }

    bool isEmpty() {
        if(currSize == 0 || top == NULL) 
            return true;
        else
            return false;
    }
    
    void InsertAtHead(Node *&head, int d, int size, int &currSize) {
        if(head == NULL) {
            Node *temp = new Node(d);
            head = temp;
            currSize++;
            return;
        }
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
        currSize++;
    }
    
};

int main()
{
    StackLL st(5);

    st.push(22);
    st.push(43);
    st.push(44);

    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
     




    // stack using STL
    // stack<int> s;
    // s.push(2);
    // s.push(3);

    // s.pop();

    // cout<<"Printing top element: "<<s.top()<<endl;

    return 0;
}