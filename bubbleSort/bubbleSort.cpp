#include <bits/stdc++.h>

void bubbleSort(std::vector<int> &vec)
{
    for (int i=vec.size()-1; i>0; i--) {
        bool swapped = false;
        for (int j=0; j<i; j++) {
            if (vec[j] > vec[j+1]) {
                std::swap(vec[j], vec[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break; // If no swaps were made, exit early.
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

    bubbleSort(myVec);
    std::cout << "After Sorting: ";
    printArray(myVec);
    
    return 0;
}