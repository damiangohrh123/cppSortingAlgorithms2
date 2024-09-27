#include <bits/stdc++.h>

class Heap {
private:
    std::vector<int> heap;

public:
    enum Type {MIN, MAX};
    Type heapType;

    Heap(Type type);
    ~Heap();

    // Adds a new element to the heap while maintaining heap property
    void insertVal(int val);

    // Removes the root element (smallest in min-heap, largest in max-heap)
    void deleteVal();

    // Returns the root element (smallest in min-heap, largest in max-heap)
    int peek();

    // Rearranges elements to maintain heap property.
    void heapify(int pos);

    // Constructs the heap from an unsorted array or vector
    void buildHeap(std::vector<int>& arr);

    // Returns the current number of elements in the heap
    int size();

    // Checks if heap is empty
    bool isEmpty();

    // Display the elements in the heap
    void displayHeap();
};

Heap::Heap(Type type) : heap(), heapType(type) {}
Heap::~Heap() {}

void Heap::insertVal(int val) {
    heap.push_back(val);
    int pos = size() - 1;

    // If pos is 0, it means only 1 element is in the heap, so nothing need to be done
    if (pos == 0) return;

    if (heapType == MAX) {
        // Make sure parent node is larger than child node
        while (pos > 0 && heap[pos] > heap[(pos - 1) / 2]) {
            std::swap(heap[pos], heap[(pos - 1) / 2]); // Swap child and parent if child is larger
            pos = (pos -1) / 2; // Move index to be the parent
        }
    } else {
        // Make sure parent node is smaller than child node
        while (pos > 0 && heap[pos] < heap[(pos - 1) / 2]) {
            std::swap(heap[pos], heap[(pos - 1) / 2]); // Swap child and parent if child is smaller
            pos = (pos - 1) / 2; // Move index to be the parent
        }
    }
}

void Heap::deleteVal() {
    // If heap is empty, reuturn
    if (size() == 0) return;
    
    // If heap has a single element
    if (size() == 1) {
        heap.pop_back();
        return;
    }

    // Copy the last element onto the root, then delete last element
    heap[0] = heap[size() - 1];
    heap.pop_back();
    
    // Heapify down
    heapify(0);
}

int Heap::peek() {
    if (isEmpty()) return 0;
    return heap[0];
}

void Heap::heapify(int pos) {
    if (heapType == MAX) { // For max heap
        while (true) {
            int leftChild = 2 * pos + 1;
            int rightChild = 2 * pos + 2;
            int largest = pos; // Set pos as largest first

            // Check if left child exists first, and if its larger than pos
            if (leftChild < size() && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }

            // Check if right child exists first, and if its larger than largest
            if (rightChild < size() && heap[rightChild] > heap[largest]) {
                largest = rightChild;
            }

            // If parent is still the largest, end the heapify process
            if (largest == pos) break;

            // Swap pos with largest
            std::swap(heap[pos], heap[largest]);
            pos = largest;
        }
    } else { // For min heap
        while (true) {
            int leftChild = 2 * pos + 1;
            int rightChild = 2 * pos + 2;
            int smallest = pos; // Set pos as smallest first

            // Check if left child exists first, and if its smaller than pos
            if (leftChild < size() && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }

            // Check if right child exists first, and if its smaller than smallest
            if (rightChild < size() && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }

            // If parent is still the smallest, end the heapify process
            if (smallest == pos) break;

            // Swap pos with the smallest
            std::swap(heap[pos], heap[smallest]);
            pos = smallest;
        }
    }
}

void Heap::buildHeap(std::vector<int>& arr) {
    heap = arr;

    // Find the index of the last non-leaf node
    int startPos = (size() / 2) - 1;

    // Call heapify on all non-leaf nodes in reverse order
    for (int i = startPos; i >= 0; i--) {
        heapify(i);
    }
}

int Heap::size() {
    return heap.size();
}

bool Heap::isEmpty() {
    return heap.empty();
}

void Heap::displayHeap() {
    for (int i=0; i<size(); i++) {
        std::cout << heap[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    Heap maxHeap(Heap::MAX);
    maxHeap.insertVal(4);
    maxHeap.insertVal(5);
    maxHeap.insertVal(3);
    maxHeap.insertVal(2);
    maxHeap.insertVal(1);
    maxHeap.insertVal(12);
    maxHeap.insertVal(8);
    maxHeap.deleteVal();
    maxHeap.displayHeap();

    std::vector<int> arr1 = {1, 5, 6, 7, 12, 3, 4, 10, 9, 11};
    Heap minHeap(Heap::MIN);
    minHeap.buildHeap(arr1);
    minHeap.deleteVal();
    minHeap.displayHeap();
    return 0;
}