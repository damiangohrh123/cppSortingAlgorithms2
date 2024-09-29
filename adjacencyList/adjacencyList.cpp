#include <bits/stdc++.h>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class AdjacencyList {
private:
    int vertices = 5;
    std::vector<Node*> list;

public:
    AdjacencyList();
    ~AdjacencyList();

    // Adds an edge to the list
    void addEdge(int i, int j);

    // Removes an edge from the list
    void removeEdge(int i, int j);

    // Check if an edge exists between two vertices
    bool checkEdge(int i, int j);

    // Print the list
    void display();
};

// Initialize the list with nullptrs
AdjacencyList::AdjacencyList() : list(vertices, nullptr) {}
AdjacencyList::~AdjacencyList() {}

void AdjacencyList::addEdge(int i, int j) {
    // Make sure i and j is within bounds
    if (i < 0 || j < 0 || i >= vertices || j >= vertices) return;

    Node* newNode = new Node(j);
    newNode->next = list[i];
    list[i] = newNode;
}

void AdjacencyList::removeEdge(int i, int j) {
    // Make sure i and j is within bounds
    if (i < 0 || j < 0 || i >= vertices || j >= vertices) return;

    // If list is currently empty
    if (!list[i]) return;

    Node* current = list[i];
    Node* prev = nullptr;

    // If list only has 1 node
    if (current->data == j) {
        list[i] = current->next;
        delete current;
        return;
    }

    // Traverse the list and when node is found, delete it
    while (current) {
        if (current->data == j) {
            prev->next = current->next;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

bool AdjacencyList::checkEdge(int i, int j) {
    // Make sure i and j is within bounds
    if (i < 0 || j < 0 || i >= vertices || j >= vertices) return false;

    // If list is currently empty
    if (!list[i]) return false;

    Node* current = list[i];

    while (current) {
        if (current->data == j) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void AdjacencyList::display() {
    for (int i=0; i<vertices; i++) {
        Node* current = list[i];

        while (current) {
            std::cout << current->data << "->";
            current = current->next;
        }
        std::cout << "nullptr" << "\n";
    }
}

int main() {
    AdjacencyList* list = new AdjacencyList;
    list->addEdge(0, 3);
    list->addEdge(2, 4);
    list->addEdge(1, 2);
    list->addEdge(1, 3);
    list->addEdge(1, 4);
    list->addEdge(4, 1);
    list->removeEdge(4, 1);
    list->display();
    return 0;
}

