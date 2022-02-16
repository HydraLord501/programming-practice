#include <iostream>
// O(1)
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

void deleteNode(Node** head, int key) {
    Node* temp = *head, *prev;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    return;

    prev->next = temp->next;

    free(temp);    
}

void printList(Node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

int main()
{
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    Node* fourth = NULL;
    Node* fifth = NULL;
    Node* sixth = NULL;

    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();
    fifth = new Node();
    sixth = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = sixth;

    sixth->data = 9;
    sixth->next = NULL;
 
 
    // original list
    printList(head);
    cout << endl;
 
    deleteNode(&head, 20); 
    printList(head); 
    cout << endl;
 
    deleteNode(&head, 4);
    printList(head);
    cout << endl;
 
    deleteNode(&head, 14);
    printList(head);
    cout << endl;

    deleteNode(&head, 9);
    printList(head);
    cout << endl;
 
    return 0;
}