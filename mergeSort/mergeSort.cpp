#include <bits/stdc++.h>

void mergeSort(int arr[], int n)
{

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
    mergeSort(arr1, arr1Length);
    printArray(arr1, arr1Length, "Merge Sort: ");


    return 0;
}