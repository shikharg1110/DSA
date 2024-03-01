#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d) {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node() {
        int value = this->data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout<<value<<" is deleted"<<endl;
    }
};

void print(Node *head, Node *&tail) {
    Node *temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    cout<<"HEAD: "<<head->data<<" TAIL: "<<tail->data<<endl<<endl;
}

int getLength(Node *head) {
    Node *temp = head;
    int len = 0;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node *&head,Node *&tail, int d) {
    // Empty LL
    Node *temp = new Node(d);
    if(head == NULL) {
        head = temp;
        tail = temp;
    }
    else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&head,Node *&tail, int d) {
    Node *temp = new Node(d);
    if(tail == NULL) {
        tail = temp;
        head = temp;
    }
    else {
        tail->next  = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(int position, int d, Node *&head, Node *&tail) {
    if(position == 1) {
        insertAtHead(head, tail, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while(cnt <position -1) {
        temp = temp->next;
        cnt++;
    } 

    if(temp->next == NULL) {
        insertAtTail(head, tail, d);
        return;
    }

    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next; 
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;

}

void deleteNode(int position, Node *&head, Node *&tail) {
    if(position == 1) {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else {
        Node *curr = head;
        Node *previous = NULL;
        int cnt = 1;
        while(cnt < position) {
            previous = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        previous->next = curr->next;
        if(curr->next == NULL)
            tail = previous;
        else
            curr->next->prev = previous;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    // Node *node1 = new Node(10);
    Node *head = NULL;
    Node *tail = NULL;
    // print(head);
    // cout<<"Length of the linked list: "<<getLength(head);

    // insertAtHead(head, 11);
    // insertAtHead(head, 12);
    // insertAtHead(head, 13);
    // insertAtHead(head, 14);
    insertAtTail(head, tail, 11);
    insertAtTail(head, tail, 12);
    insertAtTail(head, tail, 13);
    insertAtTail(head, tail, 14);
    print(head, tail);
    // cout<<"Length of the linked list: "<<getLength(head)<<endl;
    
    deleteNode(4, head, tail);
    print(head, tail);
    
    return 0;
}