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

void reverse(Node *&head, Node *&tail, Node *&temp1, Node *&temp2, Node *&back, int k) {

    // this is the type of fuction where we just reverse till the kth element 

    Node *curr = temp1;
    Node *prev = NULL;
    Node *forward = NULL;
    while(k != 0) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        k--;
    }
    if(head == temp1)
    head = temp2;
    else 
    back->next = temp2;
    if(tail == temp2)
    tail = temp1;
    temp1->next = forward;
    temp2 = forward;
    back = temp1;

    temp1 = forward;
}

void rev(Node *&head, Node *&tail, int k) {
    int cnt = 1;
    Node *temp1 = head;
    Node *temp2 = head;
    Node *back = NULL;
    while(temp2 != NULL) {
        if(cnt == k){
            cnt = 1;
            reverse(head, tail, temp1, temp2, back, k);
            if(temp2 == NULL)
            return;
        }
        cnt++;
        temp2 = temp2->next;
    }
}

Node *reverse_Recur(Node *&head, int k) {
    // Step 1: BASE CALL
    if(head == NULL) 
        return NULL;
    
    // Step 2: Reverse first k nodes
    Node *forward = NULL;
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;

    while(curr != NULL && count < k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // Step 3: Recurrsion deklega aage ka
    if(forward != NULL)
        head->next = reverse_Recur(forward, k);
    
    // Step 4: Return head of reversed list
    return prev;
}

int main()
{

    int d = 0, opt = 1, k = 0;
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



    cout<<"Enter the value of k: ";
    cin>>k;
    // rev(head, tail, k);
    head = reverse_Recur(head, k);
    print(head);
    
    return 0;
}