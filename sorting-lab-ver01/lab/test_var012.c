
/*
    Objective C - Top-Level Dispatch

    Selects a sorting algorithm based on
    the input array size.
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif

#ifndef THRESHOLD
#define THRESHOLD 32
#endif

// Insertion Sort
static void insertion_sort(float *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
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

// Recursive Merge Sort
static void merge_sort(float *arr, float *temp,
                       int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;

    merge_sort(arr, temp, left, mid);
    merge_sort(arr, temp, mid + 1, right);

    merge(arr, temp, left, mid, right);
}

// Top-level dispatcher
void COMPUTE_NAME(int m0, float *x, float *y)
{
    // Copy input into output
    for (int i = 0; i < m0; i++)
    {
        y[i] = x[i];
    }

    if (m0 <= 1)
    {
        return;
    }

    // Small arrays
    if (m0 <= THRESHOLD)
    {
        insertion_sort(y, m0);
    }

    // Large arrays
    else
    {
        float *temp = malloc(m0 * sizeof(float));

        if (temp == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        merge_sort(y, temp, 0, m0 - 1);

        free(temp);
    }
}