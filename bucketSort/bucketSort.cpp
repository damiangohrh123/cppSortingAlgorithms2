#include <bits/stdc++.h>

std::vector<int> bucketSort(std::vector<int> &arr)
{
    // Create buckets. Each bucket is a linked list. Sqrt to make bucket smaller.
    std::vector<std::list<int>> bucket(sqrt(arr.size()));

    // Get max value
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }

    // Hash function
    for (int i = 0; i < arr.size(); i++)
    {
        int bucketIndex = (arr[i] * bucket.size()) / (maxVal + 1);

        // Push value into bucket. It will automatically be placed at the end of the linked list.
        bucket[bucketIndex].push_back(arr[i]);
    }

    std::vector<int> sortedArr;

    // Loop through bucket
    for (int i = 0; i < bucket.size(); i++)
    {
        // Loop through each linked list in reverse
        for (auto it = bucket[i].rbegin(); it != bucket[i].rend(); ++it)
        {
            sortedArr.push_back(*it);
        }
    }

    arr = sortedArr;
    return arr;
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
    std::vector<int> arr2 = {613, 218, 350, 157, 108, 457};

    printArray(arr1, arr1.size(), "Unsorted Array: ");
    arr1 = bucketSort(arr1);
    printArray(arr1, arr1.size(), "Bucket Sort: ");

    printArray(arr2, arr2.size(), "Unsorted Array: ");
    arr2 = bucketSort(arr2);
    printArray(arr2, arr2.size(), "Bucket Sort: ");

    return 0;
}