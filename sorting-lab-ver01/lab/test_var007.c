
/*
    Objective A - Optimized Merge Sort

    Hybrid Merge Sort

    Uses Merge Sort for large sections and
    Insertion Sort for sections containing
    16 or fewer elements.
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif

#define THRESHOLD 16

// Sort small sections using Insertion Sort
static void insertion_sort(float *arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        float key = arr[i];

        int j = i - 1;

        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Merge two sorted sections
static void merge(float *arr, float *temp,
                  int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    // Merge elements in ascending order
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

    // Copy merged elements back into array
    for (int p = left; p <= right; p++)
    {
        arr[p] = temp[p];
    }
}

// Hybrid Merge Sort
static void merge_sort(float *arr, float *temp,
                       int left, int right)
{
    // Stop if section contains one or zero elements
    if (left >= right)
    {
        return;
    }

    // Use Insertion Sort for small sections
    if (right - left + 1 <= THRESHOLD)
    {
        insertion_sort(arr, left, right);
        return;
    }

    // Divide array into two sections
    int mid = left + (right - left) / 2;

    // Recursively sort both halves
    merge_sort(arr, temp, left, mid);

    merge_sort(arr, temp, mid + 1, right);

    // Skip merging if sections are already ordered
    if (arr[mid] <= arr[mid + 1])
    {
        return;
    }

    // Merge sorted sections
    merge(arr, temp, left, mid, right);
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

    // Allocate temporary storage
    float *temp = malloc(m0 * sizeof(float));

    if (temp == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Perform Hybrid Merge Sort
    merge_sort(y, temp, 0, m0 - 1);

    // Release allocated memory
    free(temp);
}