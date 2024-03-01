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

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
            cout << "run if" << endl;
        }
        cout << "Memory free of value " << value << endl;
    }
};

void InsertAtHead(Node *&head, int d)
{
    // New node create of temp
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void InsertAtPosition(Node *&tail, Node *&head, int position, int d)
{

    // Insert at Start
    if (position == 1)
    {
        InsertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // Insert at Last Position
    if (temp->next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

// This is used to delete the node according to the position given
//  void deleteNode(int position, Node *&head, Node *&tail) {

//     // Deleting first node
//     if(position == 1) {
//         Node *temp = head;
//         head= head->next;
//         temp->next = NULL;
//         delete temp;
//     }
//     // Deleting any middle or last node
//     else {
//         Node *curr = head;
//         Node *prev = NULL;
//         int cnt = 1;
//         while(cnt < position) {
//             prev = curr;
//             curr = curr->next;
//             cnt++;
//         }
//         if(curr->next == NULL)
//             tail = prev;
//         prev->next = curr->next;
//         curr->next = NULL;
//         delete curr;

//     }
// }

void deleteNode(int value, Node *&head, Node *&tail) {
    Node *temp = head;
    if (head->data == value) {
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL) {
        // Deleting first element when values matches
        if (curr->data == value) {
            prev->next = curr->next;
            if(prev->next == NULL) 
                tail = prev;
            curr->next = NULL;
            delete curr;
            return;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
}

int main()
{

    Node *node1 = new Node(10);
    // cout<< node1->data<<endl;
    // cout<< node1->next<<endl;

    // Head pointed to node1
    Node *head = node1; // pointer of Node datatype

    // Tail pointed to node1
    Node *tail = node1;
    // print(head);
    // InsertAtHead(head, 13);
    // InsertAtHead(head, 12);
    // InsertAtHead(head, 11);
    // cout<<"After Insert At head"<<endl;
    // print(head);

    // cout<<"After Insert at Tail" <<endl;
    InsertAtTail(tail, 11);
    InsertAtTail(tail, 12);
    InsertAtTail(tail, 13);
    InsertAtTail(tail, 14);
    InsertAtPosition(tail, head, 6, 103);
    // print(head);
    // cout<<"HEAD: "<<head->data<<endl;
    // cout<<"TAIL: "<<tail->data<<endl<<endl<<endl;

    deleteNode(103, head, tail);
    print(head);
    cout << "HEAD: " << head->data << endl;
    cout << "TAIL: " << tail->data << endl
         << endl
         << endl;
    return 0;
}