#include <bits/stdc++.h>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head = nullptr;

public:
    LinkedList();
    ~LinkedList();

    // Inserting a node in the linked list
    void insertNode(int val);

    // Deleing a node in the linked list
    void deleteNode(int val);
    
    // Displaying linked list
    void displayList();
};

LinkedList::LinkedList() {}

LinkedList::~LinkedList() {}

void LinkedList::insertNode(int val) {
    // Create new node
    Node* newNode = new Node(val);

    // If linked list is empty, insert new node at head
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // If node to be inserted has smallest value
    if (head->data > val) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Traverse list
    Node* current = head;
    while (current->next != nullptr && val > current->next->data) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void LinkedList::deleteNode(int val) {
    if (head == nullptr) return;

    Node* current = head;
    Node* prev = nullptr;

    // If node to delete is head
    if (head->data == val) {
        head = head->next;
        delete current;
        return;
    }

    // Traverse through list
    while (current!= nullptr) {
        if (current->data == val) {
            prev->next = current->next;
            delete current; // To free up memory
            return;
        }
        prev = current;
        current = current->next;
    }
}

void LinkedList::displayList() {
    Node* current = head;

    // If list is empty
    if (head == nullptr) {
        std::cout << "List is empty" << "\n";
        return;
    }
    
    while(current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }

    std::cout << "nullptr" << "\n";
}

int main() {
    LinkedList *ll = new LinkedList();

    ll->insertNode(2);
    ll->insertNode(5);
    ll->insertNode(1);
    ll->insertNode(6);
    ll->insertNode(7);
    ll->insertNode(4);
    ll->displayList();
    ll->deleteNode(6);
    ll->displayList();
    return 0;
}