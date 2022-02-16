#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;

    //creating constructor
    Node(int value){
        data = value;
    }
};

Node* newNode(int data)
{
    Node* new_node = new Node(0);
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void Postorder(struct Node* root)
{
    if(root!=NULL) {
        Postorder(root->left);
        Postorder(root->right);
        cout<<root->data<<" ";
    }
}

void Inorder(Node* root)
{
    if(root != NULL){
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }
}

void Preorder(Node* root)
{
    if(root!=NULL){

        cout<<root->data<<" ";
        Preorder(root->left);
        Preorder(root->right);

    }
}

int main()
{
    struct Node* root = newNode(0);
    root->left = newNode(1);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
 
    cout << "\nPreorder traversal \n";
    Preorder(root);
 
    cout << "\nInorder traversal \n";
    Inorder(root);
 
    cout << "\nPostorder traversal n";
    Postorder(root);
 
    return 0;
}