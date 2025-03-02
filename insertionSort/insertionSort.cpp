#include <bits/stdc++.h>

void insertionSort(std::vector<int> &vec) {
    for (int i=1; i<vec.size(); i++) {
        for (int j=i; j>0; j--) {
            if (vec[j] < vec[j-1]) {
                int placeholder = vec[j];
                vec[j] = vec[j-1];
                vec[j-1] = placeholder;
            } else {
                break; // Stop comapring when element is in order
            }
        }
    }
}

void printArray(std::vector<int> &vec) {
    for (int i=0; i<vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> myVec = {2, 8, 5, 3, 9, 4};
    std::cout << "Before Sorting: ";
    printArray(myVec);

    insertionSort(myVec);
    std::cout << "After Sorting: ";
    printArray(myVec);
}