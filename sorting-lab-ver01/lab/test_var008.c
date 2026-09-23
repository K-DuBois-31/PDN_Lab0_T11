
/*
    Objective A - Quick Sort

    Standard recursive Quick Sort implementation.

    Uses the last element as the pivot and
    Lomuto partitioning to sort the array
    in ascending order.
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif

// Partition the array around a pivot
static int partition(float *arr, int low, int high)
{
    // Select the last element as the pivot
    float pivot = arr[high];

    // Index of the smaller element
    int i = low - 1;

    // Compare elements against the pivot
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;

            // Swap elements
            float temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place pivot into its correct position
    float temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Recursive Quick Sort
static void quick_sort(float *arr, int low, int high)
{
    // Base case
    if (low >= high)
    {
        return;
    }

    // Partition array and obtain pivot index
    int pivot_index = partition(arr, low, high);

    // Sort elements before pivot
    quick_sort(arr, low, pivot_index - 1);

    // Sort elements after pivot
    quick_sort(arr, pivot_index + 1, high);
}

// Main function used by testing framework
void COMPUTE_NAME(int m0, float *x, float *y)
{
    // Copy input array into output array
    for (int i = 0; i < m0; i++)
    {
        y[i] = x[i];
    }

    // Handle empty or single-element arrays
    if (m0 <= 1)
    {
        return;
    }

    // Perform Quick Sort
    quick_sort(y, 0, m0 - 1);
}