#include <bits/stdc++.h>

std::vector<int> merge (std::vector<int> left, std::vector<int> right)
{
    // Merged Array
    std::vector<int> mergedArr;

    // Indexes to loop thorugh each array
    int l = 0, r = 0;

    while (l < left.size() && r < right.size())
    {
        if (left[l] < right[r])
        {
            mergedArr.push_back(left[l]);
            l++;
        }
        else 
        {
            mergedArr.push_back(right[r]);
            r++;
        }
    }

    // If left array is exhausted
    while (r < right.size())
    {
        mergedArr.push_back(right[r]);
        r++;
    }

    // If right array is exhausted
    while (l < left.size() && r >= right.size())
    {
        mergedArr.push_back(left[l]);
        l++;
    }

    return mergedArr;
}

std::vector<int> mergeSort(std::vector<int>& arr, int low, int high)
{
    // Base case
    if (low >= high)
    {
        return {arr[low]};
    }

    int mid = low + (high - low) / 2;

    // Split array in halves
    std::vector<int> left = mergeSort(arr, low, mid);
    std::vector<int> right = mergeSort(arr, mid + 1, high);
    return merge(left, right);
}

// Function to print an array
void printArray(std::vector<int> arr, int size, std::string message)
{
    std::cout << message << "\n";

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << "\n";
}

int main()
{
    std::vector<int> arr1 = {5, 1, 4, 8, 7, 2};

    printArray(arr1, arr1.size(), "Unsorted Array: ");
    arr1 = mergeSort(arr1, 0, arr1.size() - 1);
    printArray(arr1, arr1.size(), "Merge Sort: ");

    return 0;
}