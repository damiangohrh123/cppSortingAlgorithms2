#include <bits/stdc++.h>

std::vector<int> radixSort(std::vector<int> &arr)
{
    // Get largest value
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }

    // Get number of digits in the largest value
    int digits = 0;
    while (maxVal > 0)
    {
        maxVal /= 10;
        digits++;
    }

    // Loop through each digit and perform counting sort
    for (int i = 0; i < digits; i++)
    {
        // Create frequency array with 10 elements, filled with 0
        std::vector<int> freqArr(10, 0);

        // Count occurences based on digit
        for (int j = 0; j < arr.size(); j++)
        {
            // Get digit
            int digit = arr[j] / static_cast<int>(std::pow(10, i)) % 10;
            freqArr[digit]++;
        }

        // Create new sorted array with orginal array size
        std::vector<int> output(arr.size());

        // Cumulative count
        for (int j = 1; j < freqArr.size(); j++)
        {
            freqArr[j] += freqArr[j - 1];
        }

        // Build the output array
        for (int j = arr.size() - 1; j >= 0; j--) // Traverse backwards for stable sorting
        {
            // Get digit
            int digit = arr[j] / static_cast<int>(std::pow(10, i)) % 10;

            output[freqArr[digit] - 1] = arr[j]; // -1 because of zero-indexing
            freqArr[digit]--;
        }

        // Copy the output array to arr
        arr = output;
    }

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
    arr1 = radixSort(arr1);
    printArray(arr1, arr1.size(), "Radix Sort: ");

    printArray(arr2, arr2.size(), "Unsorted Array: ");
    arr2 = radixSort(arr2);
    printArray(arr2, arr2.size(), "Radix Sort: ");

    return 0;
}