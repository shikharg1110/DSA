#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    } 
};

void print(Node *&head)
{
    if(head == NULL) {
        cout<<"Linked List is Empty"<<endl;
        return;
    }
    cout<<"\nLinked List: ";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

void InsertAtHead(Node *&head, Node *&tail, int d)
{
    if(head == NULL) {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
    }
}

void InsertAtTail(Node *&head, Node *&tail, int d) {
    if(tail == NULL) {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
        Node *temp = new Node(d);
        tail->next = temp;
        tail = temp;
    }
}

void InsertAtMiddle(int position, int d, Node *&tail, Node *&head) {
    if(position == 1) {
        InsertAtHead(head, tail, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt<position-1)
    {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        InsertAtTail(head, tail, d);
        return;
    }
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void sort012(Node *&head) {
    if(head == NULL)
        return;
    Node *zero = NULL;
    Node *zeroStart = NULL;
    Node *one = NULL;
    Node *oneStart = NULL;
    Node *two = NULL;
    Node *twoStart = NULL;
    Node *curr = head;
    while(curr != NULL) {
        if(curr->data == 0) {
            Node *temp = new Node(0);
            if(zero == NULL) {
                zero = temp;
                zeroStart = zero;
            }
            else
            zero->next = temp;
        }
        else if(curr->data == 1) {
            Node *temp = new Node(1);
            if(one == NULL){
                one = temp;
                oneStart = one;
            }
            else
            one->next = temp;
        }
        else if(curr->data == 2) {
            Node *temp = new Node(2);
            if(two == NULL){
                two = temp;
                twoStart = two;
            }
            else
            two->next = temp;
        }
        curr = curr->next;
    }
    head = zeroStart;
    while(zeroStart->next!=NULL)
        zeroStart = zeroStart->next;
    zeroStart->next = oneStart;
    while(oneStart->next != NULL)
        oneStart = oneStart->next;
    oneStart->next = twoStart;

    print(head);
    

}

int main()
{

    int d = 0, opt = 1;
    Node *head = NULL;
    Node *tail = NULL;
    while(opt !=0) {
        cout<<"Enter the value in Linked List: ";
        cin>>d;
        InsertAtTail(head, tail, d);
        cout<<"Press 0 for stop entering value,   Press any value to enter value: ";
        cin>>opt;
        if(opt == 0)
        break;
    }
    print(head);
    sort012(head);
    return 0;
}