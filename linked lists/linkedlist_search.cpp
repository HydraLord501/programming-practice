#include <iostream>
// O(1)
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

bool search(Node* head, int searching) {
    if (head == NULL)
        return false;

    if (head->data == searching)
        return true;

    return search(head->next, searching);
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
    
 
    search(head, 1)? cout << "Yes" : cout << "No";
    search(head, 12)? cout << "Yes" : cout << "No";
    search(head, -2)? cout << "Yes" : cout << "No";
    search(head, 5)? cout << "Yes" : cout << "No";
    return 0;
}