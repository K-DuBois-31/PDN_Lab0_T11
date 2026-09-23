
/*
    Objective A - Merge Sort

    Standard recursive Merge Sort implementation.

    Divides the array into smaller sections,
    recursively sorts them, and merges the
    sections back together in ascending order.
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif

// Merge two sorted sections of the array
void merge(float *arr, float *temp,
           int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    // Compare elements from both sections
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements from left section
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements from right section
    while (j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy merged elements back into original array
    for (int p = left; p <= right; p++)
    {
        arr[p] = temp[p];
    }
}

// Recursively divide and sort the array
void merge_sort(float *arr, float *temp,
                int left, int right)
{
    // Base case: section contains one or zero elements
    if (left >= right)
    {
        return;
    }

    // Find midpoint
    int mid = left + (right - left) / 2;

    // Sort left half
    merge_sort(arr, temp, left, mid);

    // Sort right half
    merge_sort(arr, temp, mid + 1, right);

    // Merge sorted halves
    merge(arr, temp, left, mid, right);
}

// Main sorting function used by the testing framework
void COMPUTE_NAME(int m0, float *x, float *y)
{
    // Copy input array into output array
    for (int i = 0; i < m0; i++)
    {
        y[i] = x[i];
    }

    // Handle empty and single-element arrays
    if (m0 <= 1)
    {
        return;
    }

    // Allocate temporary storage
    float *temp = malloc(m0 * sizeof(float));

    if (temp == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Perform Merge Sort
    merge_sort(y, temp, 0, m0 - 1);

    // Release temporary storage
    free(temp);
}