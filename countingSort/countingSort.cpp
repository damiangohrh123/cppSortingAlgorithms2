#include <bits/stdc++.h>

std::vector<int> countingSort(std::vector<int>& vec) {
    // Find maximum value
    int maxVal = vec[0];
    for (int i=1; i<vec.size(); i++) {
        if (vec[i] > maxVal) {
            maxVal = vec[i];
        }
    }

    // Create vector with the maximum value as its size (Frequency Vector)
    std::vector<int> frequencyVec(maxVal + 1);
    
    // Count occurance of each number in vec
    for (int i=0; i<vec.size(); i++) {
        frequencyVec[vec[i]]++; 
    }

    // Create new vector to store sorted values
    std::vector<int> sortedVec;

    // Store sorted values into sortedVec
    for (int i=0; i<frequencyVec.size(); i++) {
        for (int j=0; j<frequencyVec[i]; j++) {
            sortedVec.push_back(i);
        }
    }
    
    return sortedVec;
}

// Function to print an array
void printArray(std::vector<int>& vec) {
    for (int i=0; i<vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
    std::vector<int> myVec = {2, 8, 5, 3, 9, 4, 1};
    std::cout << "Before Sorting: ";
    printArray(myVec);

    std::vector<int> sortedVec = countingSort(myVec);
    std::cout << "After Sorting: ";
    printArray(sortedVec);

    return 0;
}