/*
    Objective E - 8-element odd-even sorting network

    8 fixed stages, 28 compare-and-swap operations.
    Comparisons within each stage are independent.
*/

#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif

#define COMPARE_SWAP(a, b)           \
    do {                             \
        float va = y[a];             \
        float vb = y[b];             \
        y[a] = va < vb ? va : vb;     \
        y[b] = va < vb ? vb : va;     \
    } while (0)

void COMPUTE_NAME(int m0, float *x, float *y)
{
    for (int i = 0; i < m0; i++)
    {
        y[i] = x[i];
    }

    if (m0 == 8)
    {
        // Stage 1: four independent comparisons
        COMPARE_SWAP(0, 1);
        COMPARE_SWAP(2, 3);
        COMPARE_SWAP(4, 5);
        COMPARE_SWAP(6, 7);

        // Stage 2: three independent comparisons
        COMPARE_SWAP(1, 2);
        COMPARE_SWAP(3, 4);
        COMPARE_SWAP(5, 6);

        // Stage 3
        COMPARE_SWAP(0, 1);
        COMPARE_SWAP(2, 3);
        COMPARE_SWAP(4, 5);
        COMPARE_SWAP(6, 7);

        // Stage 4
        COMPARE_SWAP(1, 2);
        COMPARE_SWAP(3, 4);
        COMPARE_SWAP(5, 6);

        // Stage 5
        COMPARE_SWAP(0, 1);
        COMPARE_SWAP(2, 3);
        COMPARE_SWAP(4, 5);
        COMPARE_SWAP(6, 7);

        // Stage 6
        COMPARE_SWAP(1, 2);
        COMPARE_SWAP(3, 4);
        COMPARE_SWAP(5, 6);

        // Stage 7
        COMPARE_SWAP(0, 1);
        COMPARE_SWAP(2, 3);
        COMPARE_SWAP(4, 5);
        COMPARE_SWAP(6, 7);

        // Stage 8
        COMPARE_SWAP(1, 2);
        COMPARE_SWAP(3, 4);
        COMPARE_SWAP(5, 6);

        return;
    }

    // Fallback for sizes other than 8.
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