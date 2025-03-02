#include <bits/stdc++.h>

void selectionSort(std::vector<int> &vec) {
    for (int i=0; i<vec.size(); i++) {
        int minIndex = i;
        for (int j=i+1; j<vec.size(); j++) {
            if (vec[j] < vec[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(vec[i], vec[minIndex]);
    }
}

void printArray(std::vector<int> &vec) {
    for (int i=0; i<vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> myVec = {2, 8, 5, 3, 9, 4, 1};

    std::cout << "Before Sorting: ";
    printArray(myVec);


    selectionSort(myVec);
    

    std::cout << "After Sorting: ";
    printArray(myVec);

    return 0;
}