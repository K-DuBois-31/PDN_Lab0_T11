
/*
    Objective E - 4-element odd-even sorting network
    Fixed comparison schedule with O(n^2) complexity.
*/

#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif

#define COMPARE_SWAP(a, b)            \
    do {                              \
        float va = y[a];              \
        float vb = y[b];              \
        y[a] = va < vb ? va : vb;      \
        y[b] = va < vb ? vb : va;      \
    } while (0)

void COMPUTE_NAME(int m0, float *x, float *y)
{
    for (int i = 0; i < m0; i++)
    {
        y[i] = x[i];
    }

    if (m0 == 4)
    {
        // Stage 1: independent comparisons
        COMPARE_SWAP(0, 1);
        COMPARE_SWAP(2, 3);

        // Stage 2
        COMPARE_SWAP(1, 2);

        // Stage 3: independent comparisons
        COMPARE_SWAP(0, 1);
        COMPARE_SWAP(2, 3);

        // Stage 4
        COMPARE_SWAP(1, 2);

        return;
    }

    // Fallback for sizes other than 4.
    for (int i = 1; i < m0; i++)
    {
        float key = y[i];
        int j = i - 1;

        while (j >= 0 && y[j] > key)
        {
            y[j + 1] = y[j];
            j--;
        }

        y[j + 1] = key;
    }
}