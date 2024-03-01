#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node {
    public: 
        int data;
        node *left;
        node *right;
    
    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root) {
    cout << "Enter the data: " << endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node *root) {
    queue<node *>q;
    q.push(root);
    q.push(NULL);

    while( !q.empty() ){
        node *temp = q.front();
        q.pop();

        if(temp == NULL) // prev level compeletely tranversed
        {
            cout << endl;

            if(!q.empty()) // queue still has some child nodes
                q.push(NULL);
        }    

        else {

            cout << temp->data << " ";
            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }

    }
}

void reverseLevelOrderTraversal(node *root) {
    stack<node *>s;
    queue<node *>q;
    q.push(root);
    
    while(!q.empty()) {
        root = q.front();
        q.pop();
        s.push(root);

        if(root->right)
            q.push(root->right);
        if(root->left)
            q.push(root->left);
    }

    // Now pop all item from stack and print them
    while(!s.empty()) {
        root = s.top();
        cout<<root->data<<" ";
        s.pop();
    }   
}

void inorder_Iteration(node *root) {
    stack<node *> s;
    node *curr = root;
    while( curr != NULL || !s.empty()) {
        // Reach the left most Node of curr node
        while( curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        // Curr will be at leftmost NULL node
        
        curr = s.top();
        s.pop();

        cout<<curr->data<<" ";
        curr = curr->right;
        // Now it is right subtree turn
    }
}

void preorder_Iteration(node *root) {
    if(root == NULL)
        return;

    stack<node *> s;
    node *curr = root;

    while(curr != NULL ||!s.empty()) {
        // print left child and push right child
        while(curr != NULL) {
            cout<<curr->data<<" ";

            if(curr->right)
                s.push(curr->right);
            
            curr = curr->left;
        }
        // curr reached null

        if(!s.empty() ) {
            curr = s.top();
            s.pop();
        }
    }
}

void postorder_Iteration(node *root) {
    if(root == NULL)
        return;
    
    stack<node *> s1, s2;

    s1.push(root);
    node* node;

    while(!s1.empty()) {
        node = s1.top();
        s1.pop();
        s2.push(node);

        // push left and right children of removed item to s1
        if(node->left)
            s1.push(node->left);
        if(node->right)
            s1.push(node->right);
    }

    // print all element of second stack
    while(!s2.empty()) {
        node = s2.top();
        s2.pop();
        cout<<node->data<<" ";
    }
}

void inorder_Recursion(node *root) {
    // base case
    if(root == NULL )
        return;

    inorder_Recursion(root->left);
    cout<<root->data<<" ";
    inorder_Recursion(root->right);
}

void preorder_Recursion(node *root) {
    // base case
    if(root == NULL )
        return;

    cout<<root->data<<" ";
    preorder_Recursion(root->left);
    preorder_Recursion(root->right);
}

void postorder_Recursion(node *root) {
    // base case
    if(root == NULL )
        return;

    postorder_Recursion(root->left);
    postorder_Recursion(root->right);
    cout<<root->data<<" ";
}

void buildFromLevelOrder(node *&root) {
    queue<node *> q;
    cout<<"Enter data for root: " << endl;
    int data; cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()) {
        node *temp = q.front();
        q.pop();

        cout<<"Enter left node for: "<<temp->data<<endl;
        int leftData; cin>>leftData;

        if(leftData != -1) {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for: "<<temp->data<<endl;
        int rightData; cin>>rightData;

        if(rightData != -1) {
            temp->right = new node(rightData);
            q.push(temp->right);
        }

    }
}

int main()
{
    node *root = NULL;

    // creating a tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // root = buildTree(root);

    // cout << "Printing the level order traversal output: " << endl;
    // levelOrderTraversal(root);
    // cout<<endl;
    // cout << "Printing the reverse level order traversal output: " << endl;
    // reverseLevelOrderTraversal(root);
    // cout<<endl;
    // cout << "Printing the inorder Using Recursion: " << endl;
    // inorder_Recursion(root);
    // cout<<endl;
    // cout << "Printing the preorder Using Recursion: " << endl;
    // preorder_Recursion(root);
    // cout<<endl;
    // cout << "Printing the postorder Using Recursion: " << endl;
    // postorder_Recursion(root);
    // cout<<endl;

    // cout << "Printing the inorder Using Iteration: " << endl;
    // inorder_Iteration(root);
    cout<<endl;

    // cout << "Printing the preorder Using Iteration: " << endl;
    // preorder_Iteration(root);
    // cout<<endl;

    // cout << "Printing the postorder Using Iteration: " << endl;
    // postorder_Iteration(root);
    // cout<<endl;

    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    return 0;
}