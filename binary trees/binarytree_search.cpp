#include <iostream>
// O(n)
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

     Node(int val)
    {
        data = val;

        left = NULL;
        right = NULL;
    }
};

bool ifNodeExists(struct Node* node, int data) {
    if (node == NULL)
        return false;

    if (node->data == data)
        return true;

    bool res1 = ifNodeExists(node->left, data);

    if(res1) return true;

    bool res2 = ifNodeExists(node->right, data);

    return res2;
}

int main() {
    struct Node* root = new Node(10);
    root->left = new Node(43);
    root->left->left = new Node(81);
    root->left->left->left = new Node(76);
    root->left->right = new Node(21);
    root->left->right->left = new Node(83);
    root->left->right->right = new Node(18);
    root->right = new Node(38);
    root->right->left = new Node(24);
    root->right->right = new Node(72);
 
    int key = 4;
 
    if (ifNodeExists(root, key))
        cout << "YES";
    else
        cout << "NO";
 
    return 0;
}