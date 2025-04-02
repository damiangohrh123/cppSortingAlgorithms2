#include <bits/stdc++.h>

std::vector<int> merge (std::vector<int> left, std::vector<int> right) {
    std::vector<int> sorted;
    int l = 0;
    int r = 0;

    // Sort and merge back
    while (l < left.size() && r < right.size()) {
        if (left[l] < right[r]) {
            sorted.push_back(left[l]);
            l++;
        } else {
            sorted.push_back(right[r]);
            r++;
        }
    }

    // Push back any leftovers
    sorted.insert(sorted.end(), left.begin() + l, left.end());
    sorted.insert(sorted.end(), right.begin() + r, right.end());

    return sorted;
}

std::vector<int> mergeSort(std::vector<int>& n, int low, int high) {

    // Base case
    if (low >= high) return {n[low]};

    // Split the vector recursively until it has a single element
    int mid = low + (high-low) / 2;
    std::vector<int> left = mergeSort(n, low, mid);
    std::vector<int> right = mergeSort(n, mid+1, high);

    // Merge the vectors back togrhter while sorting
    return merge(left, right);
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

    std::vector<int> sortedVec = mergeSort(myVec, 0, myVec.size() - 1);
    std::cout << "After Sorting: ";
    printArray(sortedVec);

    return 0;
}