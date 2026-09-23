
/*
    Objective D - Recursive Dispatch

    Uses Merge Sort for large sections and
    Insertion Sort for small sections.
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif

#ifndef THRESHOLD
#define THRESHOLD 16
#endif

// Insertion Sort for small sections
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

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (int p = left; p <= right; p++)
    {
        arr[p] = temp[p];
    }
}

// Recursive dispatcher
static void recursive_dispatch(float *arr, float *temp,
                               int left, int right)
{
    int size = right - left + 1;

    // Base case
    if (size <= 1)
    {
        return;
    }

    // Small sections use Insertion Sort
    if (size <= THRESHOLD)
    {
        insertion_sort(arr, left, right);
        return;
    }

    // Large sections use Merge Sort
    int mid = left + (right - left) / 2;

    recursive_dispatch(arr, temp, left, mid);

    recursive_dispatch(arr, temp, mid + 1, right);

    // Skip merging if sections are already ordered
    if (arr[mid] <= arr[mid + 1])
    {
        return;
    }

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

    // Perform recursive dispatch
    recursive_dispatch(y, temp, 0, m0 - 1);

    free(temp);
}