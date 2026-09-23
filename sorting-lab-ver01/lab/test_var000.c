
/*
    Objective A - Unoptimized Bubble Sort

    This implementation sorts an array of floating-point
    numbers in ascending order using Bubble Sort.

    The input array x is copied into the output array y
    before sorting.
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif

void COMPUTE_NAME(int m0, float *x, float *y)
{
    // Step 1: Copy the input array into the output array
    for (int i = 0; i < m0; i++)
    {
        y[i] = x[i];
    }

    // Step 2: Perform unoptimized Bubble Sort
    for (int i = 0; i < m0; i++)
    {
        for (int j = 0; j < m0 - 1; j++)
        {
            // Compare adjacent elements
            if (y[j] > y[j + 1])
            {
                // Swap elements if they are out of order
                float temp = y[j];

                y[j] = y[j + 1];

                y[j + 1] = temp;
            }
        }
    }
}