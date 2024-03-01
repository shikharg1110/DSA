#include <iostream>
#include <map>
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
    cout << endl;
}

void InsertAtHead(Node *&head, int d)
{
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

void InsertAtMiddle(int position, int d, Node *&tail, Node *&head)
{
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

    if (temp->next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position, Node *&head)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        delete curr;
    }
}

// Only for sorted list
void removeDuplicates(Node *head)
{
    if (head == NULL)
        return;
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == temp->data)
        {
            Node *del = temp->next;
            temp->next = temp->next->next;
            del->next = NULL;
            delete del;
        }
        else
            temp = temp->next;
    }
}

// applicable to both sorted and unsorted list
void removeUnsortedDuplicates(Node *head)
{
    if (head == NULL)
        return;
    Node *temp2 = head;
    while (temp2 != NULL)
    {
        Node *prev = temp2;
        Node *temp = temp2->next;

        while (temp != NULL)
        {
            if (temp2->data == temp->data)
            {
                Node *del = temp;
                prev->next = temp->next;
                temp = temp->next;
                del->next = NULL;
                delete del;
            }
            else
            {
                temp = temp->next;
                prev = prev->next;
            }
        }
        temp2 = temp2->next;
    }
}

// removing duplicate element from an unsorted list using map
void removeUsingMap(Node *head) {
    if(head == NULL)
        return;
    map<int, bool> visited;
    Node *temp = head->next;
    Node *prev = head;
    visited[head->data] = true;
    while(temp != NULL) {
        if(visited[temp->data] == true) {
            prev->next = temp->next;
            Node *del = temp;
            temp = temp->next;
            del->next = NULL;
            delete del;
            continue;
        }
        visited[temp->data] = true;
        prev = prev->next;
        temp = temp->next;
    }
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    InsertAtTail(tail, 4);
    InsertAtTail(tail, 1);
    InsertAtTail(tail, 2);
    InsertAtTail(tail, 5);
    InsertAtTail(tail, 3);
    InsertAtTail(tail, 3);
    InsertAtTail(tail, 4);
    InsertAtTail(tail, 7);
    InsertAtTail(tail, 4);
    InsertAtTail(tail, 8);
    InsertAtTail(tail, 8);
    InsertAtTail(tail, 8);
    InsertAtTail(tail, 7);
    InsertAtTail(tail, 6);
    InsertAtTail(tail, 6);
    InsertAtTail(tail, 6);
    InsertAtTail(tail, 6);
    InsertAtTail(tail, 6);
    InsertAtTail(tail, 6);
    InsertAtTail(tail, 8);
    InsertAtTail(tail, 4);
    InsertAtTail(tail, 7);
    InsertAtTail(tail, 6);
    InsertAtTail(tail, 6);
    InsertAtTail(tail, 7);
    InsertAtTail(tail, 4);
    InsertAtTail(tail, 8);
    InsertAtTail(tail, 4);
    InsertAtTail(tail, 5);
    InsertAtTail(tail, 6);
    InsertAtTail(tail, 9);
    print(head);
    cout << "After deleting the duplicates value" << endl;
    removeUsingMap(head);
    print(head);

    return 0;
}