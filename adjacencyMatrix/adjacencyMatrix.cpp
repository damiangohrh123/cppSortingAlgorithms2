#include <bits/stdc++.h>

class AdjacencyMatrix {
private:
    int vertices = 5;
    std::vector<std::vector<int>> matrix;

public:
    AdjacencyMatrix();
    ~AdjacencyMatrix();

    // Update the matrix when an edge is added betwen two vertices
    void addEdge(int i, int j);

    // Update the matrix when an edge is removed
    void removeEdge(int i, int j);

    // Check if an edge exists between two vertices
    bool checkEdge(int i, int j);

    // Print the matrix
    void display();
};

AdjacencyMatrix::AdjacencyMatrix() {
    // Initialize the matrix with 0s
    matrix.resize(vertices, std::vector<int>(vertices, 0));
}

AdjacencyMatrix::~AdjacencyMatrix() {}

void AdjacencyMatrix::addEdge(int i, int j) {
    // Make sure i and j is within bounds
    if (i < 0 || j < 0 || i >= vertices || j >= vertices) return;

    matrix[i][j] = 1;
}

void AdjacencyMatrix::removeEdge(int i, int j) {
    // Make sure i and j is within bounds
    if (i < 0 || j < 0 || i >= vertices || j >= vertices) return;

    matrix[i][j] = 0;
}

bool AdjacencyMatrix::checkEdge(int i, int j) {
    // Make sure i and j is within bounds
    if (i < 0 || j < 0 || i >= vertices || j >= vertices) return false;

    return matrix[i][j];
}

void AdjacencyMatrix::display() {
    for (int i=0; i<vertices; i++) {
        for (int j=0; j<vertices; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    AdjacencyMatrix matrix;
    matrix.addEdge(0, 1);
    matrix.addEdge(0, 1);
    matrix.addEdge(2, 3);
    matrix.addEdge(4, 3);
    matrix.addEdge(3, 2);
    matrix.addEdge(2, 1);
    matrix.addEdge(4, 4);
    matrix.removeEdge(4, 4);
    matrix.display();
    std::cout << "Does 4, 4 exists: " << matrix.checkEdge(4, 4) << "\n";
    std::cout << "Does 0, 1 exists: " << matrix.checkEdge(0, 1) << "\n";
    return 0;
}