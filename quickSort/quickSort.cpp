#include <bits/stdc++.h>

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int leftIndex = low;

        for (int i = low; i < high; i++)
        {
            if (arr[i] < pivot)
            {
                std::swap(arr[leftIndex], arr[i]);
                leftIndex++;
            }
        }
        std::swap(arr[leftIndex], arr[high]);

        quickSort(arr, low, leftIndex - 1);
        quickSort(arr, leftIndex + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size, std::string message)
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
    int arr1[] = {5, 1, 4, 8, 7, 2};
    int arr1Length = sizeof(arr1) / sizeof(arr1[0]);

    printArray(arr1, arr1Length, "Unsorted Array: ");
    quickSort(arr1, 0, arr1Length - 1);
    printArray(arr1, arr1Length, "QuickSort: ");

    return 0;
}