
/*
    Objective B - Sentinel Insertion Sort

    Moves the minimum element to the beginning
    of the array to eliminate boundary checks
    during insertion.
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

    if (m0 <= 1)
    {
        return;
    }

    // Find the minimum element
    int min_index = 0;

    for (int i = 1; i < m0; i++)
    {
        if (y[i] < y[min_index])
        {
            min_index = i;
        }
    }

    // Move minimum element to the beginning
    float temp = y[0];
    y[0] = y[min_index];
    y[min_index] = temp;

    // Insertion Sort without boundary checks
    for (int i = 2; i < m0; i++)
    {
        float key = y[i];

        int j = i - 1;

        while (y[j] > key)
        {
            y[j + 1] = y[j];
            j--;
        }

        y[j + 1] = key;
    }
}