// Input ---- 1 -> 2 -> 1 -> 3 -> X
// Input ---- 1 -> 3 -> X
// Output---- 1 -> 2 -> 2 -> 6 -> X

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

// void InsertAtTail(Node *&head, Node *&tail, int d) {
//     if(tail == NULL) {
//         Node *temp = new Node(d);
//         head = temp;
//         tail = temp;
//     }
//     else {
//         Node *temp = new Node(d);
//         tail->next = temp;
//         tail = temp;
//     }
// }

    void insertAtTail(Node* &head, Node* &tail, int digit) {
        Node *temp = new Node(digit);
        if(head == NULL) {
            head= temp;
            tail = temp;
            return;
        }
        else {
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
        insertAtTail(head, tail, d);
        return;
    }
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}




    Node *reverse(Node *head) {
        Node *curr = head;
        Node *prev = NULL;
        Node *forward = NULL;
        
        while(curr != NULL) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
    
    Node* add(Node* first, Node* second) {
        int carry = 0;
        
        Node *ansHead = NULL;
        Node *ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0) {
            
            int val1 = 0;
            if(first != NULL)
                val1 = first->data;
            
            int val2 = 0;
            if(second != NULL)
                val2 = second->data;
            
            int sum = carry + val1 + val2;
            
            int digit = sum % 10;
            
            // Create node and add in ans LL
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum / 10;
            
            if(first != NULL)
                first = first->next;
                
            if(second != NULL)
                second = second->next;
        }
        return ansHead;
    }
    
    //Function to add two numbers represented by linked list.
    Node* addTwoLists(Node* first, Node* second)
    {
        // STEP 1: reverse input ll 
        first = reverse(first);
        second = reverse(second);
        
        // STEP 2: add 2 ll
        Node *ans = add(first, second);
        
        // STEP 3: reverse ans
        ans = reverse(ans);
        
        return ans;
        
        
    }

int main()
{

    int d = 0, k = 0;
    Node *head1 = NULL;
    Node *tail1 = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;
    while(d !=-1) {
        cout<<"Enter the value in Linked List 1: , -1 for exit: ";
        cin>>d;
        if(d == -1) {
            d = 0;
            break;
        }
        insertAtTail(head1, tail1, d);
    }
    while(d !=-1) {
        cout<<"Enter the value in Linked List 2: , -1 for exit: ";
        cin>>d;
        if(d == -1)
        break;
        insertAtTail(head2, tail2, d);
    }
    print(head1);
    print(head2);
    Node *head = addTwoLists(head1, head2);
    print(head);
    return 0;
}