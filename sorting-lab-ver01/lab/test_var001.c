
/*
    Objective A - Optimized Bubble Sort

    Optimizations:
    1. Reduce comparisons after each pass.
    2. Terminate early if no swaps occur.
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

    // Optimized Bubble Sort
    for (int i = 0; i < m0 - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < m0 - i - 1; j++)
        {
            if (y[j] > y[j + 1])
            {
                float temp = y[j];

                y[j] = y[j + 1];

                y[j + 1] = temp;

                swapped = 1;
            }
        }

        // Stop if the array is already sorted
        if (swapped == 0)
        {
            break;
        }
    }
}