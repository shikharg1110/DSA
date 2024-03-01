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
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
    // cout << "temp: " << endl;
    // cout << "Head data:   " << head->data << " " << head->next << "   Value of head:  " << head << "   Address of head:    " << &head << endl;
    // cout << "Temp data:   " << temp->data << " " << temp->next << "   Value of temp:  " << temp << "   Address of temp:    " << &temp << endl;
}

void InsertAtTail(Node *&tail, int d) {
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
    // cout << "temp: " << endl;
    // cout << "Tail data:   " << tail->data << " " << tail->next << "   Value of tail:  " << tail << "   Address of tail:    " << &tail << endl;
    // cout << "Temp data:   " << temp->data << " " << temp->next << "   Value of temp:  " << temp << "   Address of temp:    " << &temp << endl;
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
    cout<<endl<<"After position k = 7 : "<<endl;
    InsertAtMiddle(7, 22, tail, head);
    print(head);
    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl<<endl<<endl;

    deleteNode(5, head);
    print(head);













    // InsertAtHead(head, 2);
    // InsertAtHead(head, 3);
    // InsertAtHead(head, 4);
    // InsertAtHead(head, 5);
    // InsertAtHead(head, 6);
    // InsertAtHead(head, 7);
    // InsertAtHead(head, 8);




    // cout << "Head value:   " << head->data << " " << head->next << "   Value of head:  " << head << "   Address of head:    " << &head << endl;
    // cout << "Node 1 value: " << node1->data << " " << node1->next << "   Value of Node 1: " << node1 << "   Address of Node 1: " << &node1 << endl;




    // cout<<"Value of Node 1: "<<node1<<endl;
    // cout<<"Value of head: "<<head<<endl;

    // Node *node1 = new Node(10);
    // Node *node2 = new Node(20);
    // Node *node3 = new Node(30);
    // node2->next = node1;
    // node3->next = node2;
    // cout<<"Node 1 address: "<<node1<<endl;
    // cout<<"Node 2 address: "<<node2<<endl;
    // cout<<"Node 3 address: "<<node3<<endl;
    // cout<<"Node 1: "<<node1->data<<endl;
    // cout<<node1->next<<endl;
    // cout<<"Node 2: "<<node2->data<<endl;
    // cout<<node2->next<<endl;
    // cout<<"Node 3: "<<node3->data<<endl;
    // cout<<node3->next<<endl;

    // Node node1;
    // Node node2;
    // cout<<"Address of node1: "<<&node1<<endl;
    // cout<<"Address of node2: "<<&node2<<endl;
    // node1.data = 10;
    // node1.next = &node2;
    // node2.data = 20;
    // node2.next = NULL;
    // cout<<"1: ";
    // cout<<node1.data<<"   ";
    // cout<<node1.next<<endl;
    // cout<<"2: ";
    // cout<<node2.data<<"   ";
    // cout<<node2.next<<endl;
    // cout<<endl;
    // cout<<endl;

    return 0;
}