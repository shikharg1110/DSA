#include<iostream>
#include<map>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node (int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout<<value<<" is freed"<<endl;
    }

};

void insertNode(Node *&tail, int element, int d) {
    // Empty list
    if(tail == NULL) {
        Node *temp =  new Node(d);
        tail = temp;
        temp->next = temp;
    }
    // Non-empty list
    else {
        Node *curr = tail;
        while(curr->data != element) 
            curr = curr->next;
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *tail) {
    Node *temp = tail;
    if(tail == NULL) {
        cout<<"List is empty"<<endl;
        return;
    }
    do {
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail != temp);
    cout<<endl;
}

void deleteNode(Node *& tail, int value) {
    // Empty list
    if(tail == NULL) {
        cout<<"List is empty, check again"<<endl;
        return; 
    }

    // Non-empty list
    else {
        Node *prev = tail;
        Node *curr = prev->next;


        while(curr->data != value) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        if(tail == curr) {
            tail = curr->next;
        }
        if(curr == prev)
            tail = NULL;

        curr->next = NULL;
        delete curr;
    }

}

bool detectLoop(Node *head) {
    if(head == NULL)
        return false;
    map<Node*, bool>visited;
    Node *temp = head;
    while(temp != NULL) {
        if(visited[temp] == true) {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

bool flyodCycleDetection(Node *head) {
    if(head == NULL)
        return false;
    Node *slow = head;
    Node *fast = head;
    while(slow != NULL && fast != NULL) {
        slow = slow->next;
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;

        if(slow == fast)
        return true;
    }
    return false;

}

int main()
{
    Node *tail = NULL;
    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 3, 4);
    print(tail);
    // insertNode(tail, 4, 5);
    // print(tail);
    // insertNode(tail, 5, 6);
    // print(tail);
    // insertNode(tail, 6, 7);
    // print(tail);
    deleteNode(tail, 4);
    print(tail);
    cout<<flyodCycleDetection(tail)<<endl;
    return 0;
}