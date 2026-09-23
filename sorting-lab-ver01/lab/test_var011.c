
/*
    Objective B - Tuned Insertion Sort

    Skips the insertion process when the current
    element is already in the correct position.
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

    // Optimized Insertion Sort
    for (int i = 1; i < m0; i++)
    {
        // Skip elements already in the correct position
        if (y[i] >= y[i - 1])
        {
            continue;
        }

        float key = y[i];

        int j = i - 1;

        // Shift larger elements to the right
        while (j >= 0 && y[j] > key)
        {
            y[j + 1] = y[j];
            j--;
        }

        // Insert element into its correct position
        y[j + 1] = key;
    }
}