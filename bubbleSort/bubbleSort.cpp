#include <bits/stdc++.h>

// Bubble sort using 2 for loops
void bubbleSortForLoop(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {   
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                // Using std swap
                //std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Bubble sort using an outer while loop and a nested for loop
void bubbleSortWhileLoop(int arr[], int n)
{
    bool isSwapped = true;
    while (isSwapped)
    {
        isSwapped = false;
        for (int i = 0; i < n-1; i++)
        {
            if (arr[i] > arr[i+1])
            {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                isSwapped = true;
            }
        }
        n--;
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
    bubbleSortForLoop(arr1, arr1Length);
    printArray(arr1, arr1Length, "Bubble Sort using 2 For loops: ");

    printArray(arr2, arr2Length, "Unsorted Array: ");
    bubbleSortWhileLoop(arr2, arr2Length);
    printArray(arr2, arr2Length, "Bubble Sort using while loop and for loop: ");

    return 0;
}