#include <bits/stdc++.h>

/**
 * A queue implementation using a linked list
 */

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {} 
};

class Queue {
private:
    Node* head = nullptr;
    Node* tail = nullptr;

public:
    Queue();
    ~Queue();

    // Add an element to the back of the queue
    void enqueue(int val);

    // Remove an element from the front of the queue
    void dequeue();

    // View the front element without removing it
    int peek();

    // Check if the queue has any elements
    bool isEmpty();

    // Return the number of elements in the queue
    int size();

    // Displays the queue
    void display();
};

Queue::Queue() {}
Queue::~Queue() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void Queue::enqueue(int val) {
    Node* newNode = new Node(val);

    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void Queue::dequeue() {
    if (!head) {
        return;
    }
    Node* oldNode = head;
    head = head->next;
    delete(oldNode);
}

int Queue::peek() {
    if (!head) {
        return 0;
    }
    return head->data;
}

bool Queue::isEmpty() {
    return (!head);
}

int Queue::size() {
    int count = 0;
    Node* current = head;
    while (current) {
        current = current->next;
        count++;
    }
    return count;
}

void Queue::display() {
    Node* current = head;
    while (current) {
        std::cout << current->data;
        if (current->next) {
            std::cout << "->";
        }
        current = current->next;
    }
    std::cout << "\n";
}

int main() {
    Queue *queue = new Queue();
    queue->enqueue(6);
    queue->enqueue(5);
    queue->enqueue(7);
    queue->enqueue(2);
    queue->enqueue(3);
    queue->enqueue(4);
    queue->enqueue(1);
    queue->dequeue();
    queue->peek();
    queue->isEmpty();
    queue->display();
    return 0;
}