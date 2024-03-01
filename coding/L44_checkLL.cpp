// Singly linked list

#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next = NULL;
};

void print(Node *&head) {
    Node *temp = head;
    if(temp == NULL) {
        cout<<"List is empty"<<endl;
        return;
    }
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAtHead(Node *&head, int d) {
    Node *temp = new Node();
    temp->data = d;
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&head, Node *&tail, int d) {
    Node *temp = new Node();
    temp->data = d;
    if(tail == NULL) {
        tail = temp;
        head = temp;
    }
    else 
        tail->next = temp;
    tail = temp;
}

void insertAtPosition(int position, int d, Node *&head, Node *&tail) {
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while(cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(head, tail, d);
        return;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int enter = 1, i = 0, d = 0;
    while( enter == 1 ) {
        cout<<"Enter the value to enter in node "<<i++<<": ";
        cin>>d;
        insertAtTail(head, tail, d);
        cout<<"Enter new node 1-yes, 0-no: ";
        cin>>enter;
        if(enter != 0 && enter != 1) {
            cout<<"Value entered is incorrect"<<endl;
            break;
        }
    }
    print(head);
    return 0;
}