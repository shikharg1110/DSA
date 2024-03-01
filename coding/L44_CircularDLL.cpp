#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *prev;
    Node *next;

    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node() {
        cout<<"deleted this "<<this->data<<endl;
    }
};

void inserNode(Node *&tail, int element, int d) {
    if(tail == NULL) {
        Node *temp = new Node(d);
        temp->next = temp;
        temp->prev = temp;
        tail = temp;
    }

    else  {
        Node *curr = tail;
        while(curr->data != element)
            curr = curr->next;

        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next->prev = temp;
        temp->prev = curr;
        curr->next = temp;
    }
}

void print(Node *&tail) {
    Node *temp = tail;
    if(tail == NULL) {
        cout<<"List is empty"<<endl;
        return;
    }
    else {
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        } while(temp != tail) ;
        cout<<endl;
    }
}

void deleteNode(Node *&tail, int value) {
    Node *curr = tail;
    while(curr->data != value) {
        curr = curr->next;
        if(curr == tail) {
            cout<<value<<" is not found"<<endl;
            return;
        }
    }
    if(curr == tail) {
        tail = curr->next;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    curr->prev = NULL;
    curr->next = NULL;
    delete curr;
    
}

int main()
{
    Node *tail = NULL;
    inserNode(tail, 2, 1);
    print(tail);
    inserNode(tail, 1, 2);
    print(tail);
    inserNode(tail, 2, 3);
    print(tail);
    inserNode(tail, 3, 4);
    print(tail);
    inserNode(tail, 4, 5);
    print(tail);
    inserNode(tail, 5, 55);
    print(tail);
    deleteNode(tail, 0);
    print(tail);
    return 0;
}