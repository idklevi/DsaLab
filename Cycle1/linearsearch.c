/*
 * C program to perform Linear Search on n numbers.
 * The search is implemented as a function and called from main.
 * (Cycle 1, Question 1)
 */

#include <stdio.h>

// Function declaration
int linearSearch(int arr[], int size, int key);

int main() {
    int n, i, key, result;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; // Declare array of size n

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &key);

    // Call the linear search function
    result = linearSearch(arr, n, key);

    // Check the result
    if (result == -1) {
        printf("Element %d not found in the array.\n", key);
    } else {
        printf("Element %d found at index %d (position %d).\n", key, result, result + 1);
    }

    return 0;
}

/**
 * @brief Performs a linear search on an array.
 * @param arr The array to search in.
 * @param size The size of the array.
 * @param key The element to search for.
 * @return The index of the element if found, otherwise -1.
 */
int linearSearch(int arr[], int size, int key) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Element found, return its index
        }
    }
    // Element not found after checking the whole array
    return -1;
}
