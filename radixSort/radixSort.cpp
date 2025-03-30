#include <bits/stdc++.h>
std::vector<int> countingSort(std::vector<int>& n, int digits) {
    std::vector<int> freqArr(10, 0);
    std::vector<int> output(n.size());

    // Count occurences based on digit
    for (int i=0; i<n.size(); i++) {
        // Get digit and update freqArr
        int digit = (n[i] / digits ) % 10;
        freqArr[digit]++;
    }

    // Create a cumulative sum vector
    for (int i=1; i<freqArr.size(); i++) {
        freqArr[i] += freqArr[i-1];
    }

    // Build the output array by placing the elements in the correct position
    for (int i = n.size() - 1; i >= 0; i--) {
        // Extract the current digit again
        int digit = (n[i] / digits) % 10; 

        // Place the element at the correct position
        output[freqArr[digit] - 1] = n[i]; // -1 because of zero-indexing

        // Decrease the count for this digit
        freqArr[digit]--;
    }

    return output;
}

std::vector<int> radixSort(std::vector<int>& n) {
    // Get the largest value
    int maxVal = n[0];
    for (int i=1; i<n.size(); i++) {
        if (n[i] > maxVal) maxVal = n[i];
    }

    // Get the largest digit
    int maxDigits = 0;
    while (maxVal > 0) {
        maxVal /= 10;
        maxDigits++;
    }

    int digits = 1;

    // Iterate through each digit place
    for (int i=0; i<maxDigits; i++) {
        n = countingSort(n, digits);
        digits *= 10; 
    }

    return n;

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
    std::vector<int> myVec = {221, 8, 54, 33, 991, 4, 1};
    std::cout << "Before Sorting: ";
    printArray(myVec);

    std::vector<int> sortedVec = radixSort(myVec);
    std::cout << "After Sorting: ";
    printArray(sortedVec);

    return 0;
}