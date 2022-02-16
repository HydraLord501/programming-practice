#include <iostream>
// O(N)
using namespace std;

class Node
{
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

Node* Insert(Node* node, int value) {
    if(node == NULL) {
        return newNode(value);
    }
    if(value <= node->data) {
        node->left = Insert(node->left, value);
    } else {
        node->right = Insert(node->right, value);
    }

    return node;
}

void Inorder(Node* root)
{
    if(root != NULL){
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    root = Insert(root, 50);
    root = Insert(root, 30);
    root = Insert(root, 20);
    root = Insert(root, 40);
    root = Insert(root, 70);
    root = Insert(root, 60);
    root = Insert(root, 80);
 
    Inorder(root);
    return 0;
}