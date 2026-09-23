
/*
    Objective A - Optimized Selection Sort

    Bidirectional Selection Sort

    Finds both the minimum and maximum elements
    during each pass and moves them into their
    correct positions.
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

    int left = 0;
    int right = m0 - 1;

    // Bidirectional Selection Sort
    while (left < right)
    {
        int min_index = left;
        int max_index = left;

        // Find minimum and maximum elements
        for (int j = left + 1; j <= right; j++)
        {
            if (y[j] < y[min_index])
            {
                min_index = j;
            }

            if (y[j] > y[max_index])
            {
                max_index = j;
            }
        }

        // Move minimum element to the left
        float temp = y[left];

        y[left] = y[min_index];

        y[min_index] = temp;

        // Correct maximum index if it was moved
        // during the minimum swap
        if (max_index == left)
        {
            max_index = min_index;
        }

        // Move maximum element to the right
        temp = y[right];

        y[right] = y[max_index];

        y[max_index] = temp;

        // Shrink the unsorted portion
        left++;
        right--;
    }
}