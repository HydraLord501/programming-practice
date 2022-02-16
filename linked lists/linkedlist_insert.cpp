#include <iostream>
// O(1)
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

// ADD NODE AT FRONT
void push(Node** head, int new_key) {
    Node* new_node = new Node(); // allocate new node
    new_node->data = new_key; // add value to new node
    new_node->next = *head; // link new node to head

    *head = new_node; // new node becomes head
}

// ADD NODE AT FRONT OF CERTAIN NODE
void insertAfter(Node* prev_node, int data) {
    if (prev_node == NULL)
    {
        cout << "The given previous node cannot be NULL";
        return;
    }

    Node* new_node = new Node();
    new_node->data = data;

    new_node->next = prev_node->next;

    prev_node->next = new_node;
}

// ADD NODE AT END
void append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if(*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
    return;
}

// PRINT LINKED LIST
void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}

int main()
{
    /* Start with the empty list */
    Node* head = NULL;

    append(&head, 12);
    push(&head, 24);
    push(&head, 9);
    append(&head, 32);
    insertAfter(head->next, 18);

    cout<<"Created Linked list is: ";
    printList(head);

    return 0;
}