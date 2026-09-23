
/*
    Objective A - Selection Sort

    Standard implementation of Selection Sort.

    Finds the minimum element in the unsorted
    portion and swaps it into its correct position.
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

    // Selection Sort
    for (int i = 0; i < m0 - 1; i++)
    {
        // Assume the current position contains the minimum
        int min_index = i;

        // Search the remaining unsorted elements
        for (int j = i + 1; j < m0; j++)
        {
            if (y[j] < y[min_index])
            {
                min_index = j;
            }
        }

        // Swap the minimum into its correct position
        float temp = y[i];

        y[i] = y[min_index];

        y[min_index] = temp;
    }
}