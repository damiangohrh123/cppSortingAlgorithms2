#include <bits/stdc++.h>

void insertionSort(int arr[], int n)
{
    for (int i = 1; i <= n-1; i++)
    {
        int j = i-1;
        int temp = arr[i];

        while (j >= 0 && temp < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
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

    int arr2[] = {9, 3, 8, 6, 1};
    int arr2Length = sizeof(arr2) / sizeof(arr2[0]);

    printArray(arr1, arr1Length, "Unsorted Array: ");
    insertionSort(arr1, arr1Length);
    printArray(arr1, arr1Length, "Insertion Sort: ");

    printArray(arr2, arr2Length, "Unsorted Array: ");
    insertionSort(arr2, arr2Length);
    printArray(arr2, arr2Length, "Insertion Sort: ");

    return 0;
}