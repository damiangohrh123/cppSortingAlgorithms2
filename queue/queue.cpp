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

Queue::~Queue() {}

void Queue::enqueue(int val) {
    // Create a new node
    Node* newNode = new Node(val);

    // If queue is empty
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
        return;
    }

    // If queue already has elements
    tail->next = newNode;
    tail = newNode;
}

void Queue::dequeue() {
    if (isEmpty()) {
        return;
    }

    head = head->next;
}

int Queue::peek() {
    if (isEmpty()) {
        return -1;
    }

    return (head->data);
}

bool Queue::isEmpty() {
    return (head == nullptr);
}

int Queue::size() {
    Node* current = head;
    int count = 0;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void Queue::display() {
    if (isEmpty()) {
        std::cout << "Queue is empty" << "\n";
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data;

        if (current != tail) {
            std::cout << " -> ";
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