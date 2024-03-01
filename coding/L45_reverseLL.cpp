#include <iostream>
using namespace std;

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

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&tail, int d) {
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void InsertAtMiddle(int position, int d, Node *&tail, Node *&head) {
    if(position == 1) {
        InsertAtHead(head, d);
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
        InsertAtTail(tail, d);
        return;
    }
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position, Node *&head) {
    if(position == 1) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    else {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        delete curr;
    }
}

Node* reverse(Node *&head) {
    Node *curr = head;
    Node *prev = NULL;
    Node *forward = NULL;
    while(curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

void solve(Node *&head, Node *curr, Node *prev) {
    if(curr == NULL) {
        head = prev;
        return; 
    }
    Node *forward = curr->next;
    solve(head,forward,curr);
    curr->next = prev;
}

Node *reverse3(Node  *head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    Node *chotaHead = reverse3(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotaHead;
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    InsertAtTail(tail, 2);
    InsertAtTail(tail, 3);
    InsertAtTail(tail, 4);
    InsertAtTail(tail, 5);
    InsertAtTail(tail, 6);
    print(head);

    // Iterative Way
    // head = reverse(head);
    // print(head);

    // Recursive 1st way
    // Node *curr = head;
    // Node *prev = NULL;
    // head = reverse3(head);
    // print(head);

    // Recursive 2nd way
    Node *prev = NULL;
    Node *curr = head;
    solve(head, curr, prev);
    print(head);

    return 0;
}