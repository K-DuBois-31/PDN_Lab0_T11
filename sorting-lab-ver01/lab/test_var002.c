
/*
    Objective A - Unoptimized Insertion Sort

    Sorts an array of floating-point numbers
    in ascending order using Insertion Sort.
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

    // Insertion Sort
    for (int i = 1; i < m0; i++)
    {
        float key = y[i];

        int j = i - 1;

        // Shift larger elements one position to the right
        while (j >= 0 && y[j] > key)
        {
            y[j + 1] = y[j];

            j--;
        }

        // Insert the key into its correct position
        y[j + 1] = key;
    }
}