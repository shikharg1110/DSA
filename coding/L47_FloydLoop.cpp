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

    // DETECTION OF LOOP
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

        if(slow == fast) {
            cout<<"Slow and fast meet at "<<slow->data<<endl;
            return true;
        }
    }
    return false;
}

Node *flyodCycleNode(Node *head) {
    if(head == NULL)
        return NULL;
    Node *slow = head;
    Node *fast = head;
    while(slow != NULL && fast != NULL) {
        slow = slow->next;
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;

        if(slow == fast) {
            return slow;
        }
    }
    return NULL;
}

Node *getStartingNode(Node *head) {
    if(head == NULL)
        return NULL;
    Node *intersection = flyodCycleNode(head);
    Node *slow = head;
    while(slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

void removeLoop(Node *head) {
    if(head == NULL)
        return;
    Node *startOfLoop = getStartingNode(head);
    Node *temp = startOfLoop;
    while(temp->next != startOfLoop) {
        temp = temp->next;
    }
    temp->next = NULL;
} 

int main()
{
    Node *tail = NULL;
    insertNode(tail, 5, 3);
    insertNode(tail, 3, 4);
    insertNode(tail, 4, 5);
    insertNode(tail, 5, 6);
    insertNode(tail, 6, 7);
    print(tail);
    if(flyodCycleDetection(tail) == 1)
        cout<<"Loop is present"<<endl;
    else
        cout<<"Loop is not present"<<endl;
    cout<<"benginning of the loop: "<<getStartingNode(tail)->data<<endl;
    removeLoop(tail);
    cout<<(flyodCycleDetection(tail) == 1? "Loop is present" : "Loop is not present")<<endl;
    return 0;
}