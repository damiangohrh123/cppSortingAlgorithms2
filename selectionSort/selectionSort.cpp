#include <bits/stdc++.h>

void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int minIndex = i;

        for (int j = i+1; j <= n-1; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        std::swap(arr[i], arr[minIndex]);
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
    insertionSort(arr1, arr1Length);
    printArray(arr1, arr1Length, "Selection Sort: ");


    return 0;
}