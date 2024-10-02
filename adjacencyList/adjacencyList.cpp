#include <bits/stdc++.h>

struct Node {
    int data;
    int weight;
    Node* next;

    Node(int val, int _weight) : data(val), weight(_weight), next(nullptr) {}
};

class AdjacencyList {
private:
    int vertices;
    std::vector<Node*> list;

public:
    AdjacencyList(int v);
    ~AdjacencyList();

    // Adds an edge to the list
    void addEdge(int i, int j, int weight);

    // Removes an edge from the list
    void removeEdge(int i, int j);

    // Check if an edge exists between two vertices
    bool checkEdge(int i, int j);

    // Print the list
    void display();

    // Return the adjacency list with a vertex index as input
    Node* returnList(int vertex);

    // Return number of vertices of graph
    int returnVertices();
};

// Initialize the list with nullptrs
AdjacencyList::AdjacencyList(int v) : vertices(v), list(v, nullptr) {}
AdjacencyList::~AdjacencyList() {}

void AdjacencyList::addEdge(int i, int j, int weight) {
    // Make sure i and j is within bounds
    if (i < 0 || j < 0 || i >= vertices || j >= vertices) return;

    // Add edge from i to j
    Node* newNode1 = new Node(j, weight);
    newNode1->next = list[i];
    list[i] = newNode1;

    // Add edge from j to i
    Node* newNode2 = new Node(i, weight);
    newNode2->next = list[j];
    list[j] = newNode2;
}

void AdjacencyList::removeEdge(int i, int j) {
    // Make sure i and j are within bounds
    if (i < 0 || j < 0 || i >= vertices || j >= vertices) return;

    // Remove edge from i to j
    if (list[i]) {
        Node* current = list[i];
        Node* prev = nullptr;

        // Traverse the list for i to find j
        while (current) {
            if (current->data == j) {
                // Found the node to remove
                if (prev) {
                    prev->next = current->next; // Bypass the current node
                } else {
                    list[i] = current->next; // Move head if first node
                }
                delete current; // Free the memory
                break; // Edge is removed, exit the loop
            }
            prev = current;
            current = current->next;
        }
    }

    // Remove edge from j to i
    if (list[j]) {
        Node* current = list[j];
        Node* prev = nullptr;

        // Traverse the list for j to find i
        while (current) {
            if (current->data == i) {
                // Found the node to remove
                if (prev) {
                    prev->next = current->next; // Bypass the current node
                } else {
                    list[j] = current->next; // Move head if first node
                }
                delete current; // Free the memory
                break; // Edge is removed, exit the loop
            }
            prev = current;
            current = current->next;
        }
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
        std::cout << i << "->";

        while (current) {
            std::cout << current->data << "->";
            current = current->next;
        }
        std::cout << "nullptr\n";
    }
}

Node* AdjacencyList::returnList(int vertex) {
    return list[vertex];
}

int AdjacencyList::returnVertices() {
    return vertices;
}

class PrimMST {
private:
    int vertices;
    std::vector<int> parent;   // To store the parent of each vertex
    std::vector<int> key;      // To store the minimum weight to add each vertex
    std::vector<bool> visited; // To track vertices already included in the MST

public:
    PrimMST(int v); // Constructor to initialize the arrays and graph size

    // Create tyhe MST
    void findMST(AdjacencyList& graph);

    // Display the MST
    void displayMST();
};

// Initialize parent vector
// Initialize the key vector to have "infinity" values. "Key" is the weight of edge.
// Initialize visited vector
PrimMST::PrimMST(int v) : vertices(v), parent(v, -1), key(v, std::numeric_limits<int>::max()), visited(v, false) {}

void PrimMST::findMST(AdjacencyList& graph) {
    // Set the key for the starting vertex (0)
    key[0] = 0;

    // Min-heap to store pairs (key value, vertex)
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
    minHeap.push(std::make_pair(key[0], 0)); // Push 1st vertex into min heap
    
    while (!minHeap.empty()) {
        // Get the vertex from the min-heap
        int vertex = minHeap.top().second;
        minHeap.pop(); // Remove it from the heap

        // Mark the vertex as visited
        visited[vertex] = true;

        // Explore the neighbours and update the keys' weights
        Node* current = graph.returnList(vertex);
        while (current) {
            int neighbor = current->data;
            int weight = current->weight;

            // If vertex has not been visited, and weight is lesser than current key, update the key to the weight
            if (!visited[neighbor] && weight < key[neighbor]){
                key[neighbor] = weight; // Update the key
                parent[neighbor] = vertex; // Update parent
                minHeap.push(std::make_pair(key[neighbor], neighbor)); // Push updated key to min-heap
            }
            current = current->next;
        }
    }
}

void PrimMST::displayMST() {
    std::cout << "Edge    Weight\n";
    for (int i=1; i<parent.size(); i++) {
        std::cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
    }
}

int main() {
    AdjacencyList graph(6);
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 6);
    graph.addEdge(1, 2, 6);
    graph.addEdge(1, 3, 3);
    graph.addEdge(1, 4, 4);
    graph.addEdge(2, 3, 1);
    graph.addEdge(3, 4, 2);
    graph.addEdge(3, 5, 3);
    graph.addEdge(4, 5, 7);
    graph.display();
    PrimMST mst(graph.returnVertices());
    mst.findMST(graph);
    mst.displayMST();
    return 0;
}

