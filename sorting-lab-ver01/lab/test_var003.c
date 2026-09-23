
/*
    Objective A - Optimized Insertion Sort

    Binary Insertion Sort

    Uses binary search to determine the correct
    insertion position for each element.
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif

void COMPUTE_NAME(int m0, float *x, float *y)
{
    // Copy input array into output array
    for (int i = 0; i < m0; i++)
    {
        y[i] = x[i];
    }

    // Binary Insertion Sort
    for (int i = 1; i < m0; i++)
    {
        float key = y[i];

        int left = 0;
        int right = i;

        // Find insertion position using binary search
        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (y[mid] <= key)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        // Shift elements to make room for key
        for (int j = i; j > left; j--)
        {
            y[j] = y[j - 1];
        }

        // Insert key into its correct position
        y[left] = key;
    }
}