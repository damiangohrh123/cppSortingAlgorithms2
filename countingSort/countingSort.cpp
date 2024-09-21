#include <bits/stdc++.h>

std::vector<int> countingSort(std::vector<int>& arr)
{
    // Find maximum value
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Create frequency array with max + 1 elements, filled with 0
    std::vector<int> freqArr(max + 1, 0);

    // Count occurences
    for (int i = 0; i < arr.size(); i++)
    {
        int number = arr[i];
        freqArr[number] += 1;
    }

    // Create new sorted array with orginal array size
    std::vector<int> sortedArr;

    // Map to new sorted array
    for (int i = 0; i < freqArr.size(); i++)
    {
        for (int j = 0; j < freqArr[i]; j++)
        {
            sortedArr.push_back(i);
        }
    }

    return sortedArr;
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
    std::vector<int> arr2 = {2, 3, 5, 8, 2, 9, 5, 2};

    printArray(arr1, arr1.size(), "Unsorted Array: ");
    arr1 = countingSort(arr1);
    printArray(arr1, arr1.size(), "Counting Sort: ");

    printArray(arr2, arr2.size(), "Unsorted Array: ");
    arr2 = countingSort(arr2);
    printArray(arr2, arr2.size(), "Counting Sort: ");

    return 0;
}