#include <bits/stdc++.h>

void insertionSort(std::vector<int>& vec) {
    for (int i=0; i<vec.size(); i++) {
        for (int j=i; j>0; j--) {
            if (vec[j] < vec[j-1]) {
                int temp = vec[j];
                vec[j] = vec[j-1];
                vec[j-1] = temp;
            }
        }
    }
}

std::vector<int> bucketSort(std::vector<int>& vec) {
    // Create bucket
    std::vector<std::vector<int>> bucket(vec.size());

    // Get max value
    int maxVal = vec[0];
    for (int i=1; i<vec.size(); i++) {
        if (vec[i] > maxVal) {
            maxVal = vec[i];
        }
    }

    // Place values into bucket
    for (int i=0; i<vec.size(); i++) {
        int bucketIndex = (vec[i] * bucket.size() / (maxVal + 1));
        bucket[bucketIndex].push_back(vec[i]);
    }

    std::vector<int> sortedVec;

    // Loop through buckets, sort values using insertionSort, and add sorted values to sortedVec
    for (int i=0; i<bucket.size(); i++) {
        if (bucket[i].size() > 1) {
            insertionSort(bucket[i]);
        }

        for (int j=0; j<bucket[i].size(); j++) {
            sortedVec.push_back(bucket[i][j]);
        }
    }

    return sortedVec;
}

void printArray(std::vector<int>& vec) {
    for (int i=0; i<vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
    std::vector<int> myVec = {2, 8, 5, 3, 9, 4};
    std::cout << "Before Sorting: ";
    printArray(myVec);

    std::vector<int> myVecSorted = bucketSort(myVec);
    std::cout << "After Sorting: ";
    printArray(myVecSorted);
    return 0;
}