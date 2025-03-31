#include <bits/stdc++.h>

void quickSort(std::vector<int>& n, int low, int high) {
    if (low < high)
    {
        int pivot = n[high];
        int leftIndex = low;

        for (int i = low; i < high; i++)
        {
            if (n[i] < pivot)
            {
                std::swap(n[leftIndex], n[i]);
                leftIndex++;
            }
        }
        std::swap(n[leftIndex], n[high]);

        quickSort(n, low, leftIndex - 1);
        quickSort(n, leftIndex + 1, high);
    }
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

    quickSort(myVec, 0, myVec.size());
    std::cout << "After Sorting: ";
    printArray(myVec);

    return 0;
}