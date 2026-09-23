
/*
    Objective A - Optimized Quick Sort

    Hybrid Quick Sort

    Optimizations:
    1. Median-of-three pivot selection.
    2. Insertion Sort for small partitions.
    3. Tail-recursion optimization.
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif

#define THRESHOLD 16

// Swap two elements
static void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Insertion Sort for small partitions
static void insertion_sort(float *arr, int low, int high)
{
    for (int i = low + 1; i <= high; i++)
    {
        float key = arr[i];

        int j = i - 1;

        while (j >= low && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Select pivot using median-of-three
static int median_of_three(float *arr, int low, int high)
{
    int mid = low + (high - low) / 2;

    if (arr[low] > arr[mid])
    {
        swap(&arr[low], &arr[mid]);
    }

    if (arr[low] > arr[high])
    {
        swap(&arr[low], &arr[high]);
    }

    if (arr[mid] > arr[high])
    {
        swap(&arr[mid], &arr[high]);
    }

    // Move median element to the last position
    swap(&arr[mid], &arr[high]);

    return high;
}

// Partition array around pivot
static int partition(float *arr, int low, int high)
{
    // Select median-of-three pivot
    median_of_three(arr, low, high);

    float pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;

            swap(&arr[i], &arr[j]);
        }
    }

    // Place pivot in its final position
    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

// Optimized Quick Sort
static void quick_sort(float *arr, int low, int high)
{
    while (low < high)
    {
        // Use Insertion Sort for small partitions
        if (high - low + 1 <= THRESHOLD)
        {
            insertion_sort(arr, low, high);
            return;
        }

        // Partition array
        int pivot_index = partition(arr, low, high);

        // Recursively process the smaller partition
        if (pivot_index - low < high - pivot_index)
        {
            quick_sort(arr, low, pivot_index - 1);

            // Process larger partition iteratively
            low = pivot_index + 1;
        }
        else
        {
            quick_sort(arr, pivot_index + 1, high);

            // Process larger partition iteratively
            high = pivot_index - 1;
        }
    }
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

    // Perform optimized Quick Sort
    quick_sort(y, 0, m0 - 1);
}