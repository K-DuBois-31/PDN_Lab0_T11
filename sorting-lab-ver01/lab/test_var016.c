
/*
    Objective E - 16-element odd-even sorting network

    16 fixed stages.
    120 compare-and-swap operations.
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

    if (m0 == 16)
    {
        // Stage 1
        COMPARE_SWAP(0, 1);
        COMPARE_SWAP(2, 3);
        COMPARE_SWAP(4, 5);
        COMPARE_SWAP(6, 7);
        COMPARE_SWAP(8, 9);
        COMPARE_SWAP(10, 11);
        COMPARE_SWAP(12, 13);
        COMPARE_SWAP(14, 15);

        // Stage 2
        COMPARE_SWAP(1, 2);
        COMPARE_SWAP(3, 4);
        COMPARE_SWAP(5, 6);
        COMPARE_SWAP(7, 8);
        COMPARE_SWAP(9, 10);
        COMPARE_SWAP(11, 12);
        COMPARE_SWAP(13, 14);

        // Stage 3
        COMPARE_SWAP(0, 1);
        COMPARE_SWAP(2, 3);
        COMPARE_SWAP(4, 5);
        COMPARE_SWAP(6, 7);
        COMPARE_SWAP(8, 9);
        COMPARE_SWAP(10, 11);
        COMPARE_SWAP(12, 13);
        COMPARE_SWAP(14, 15);

        // Stage 4
        COMPARE_SWAP(1, 2);
        COMPARE_SWAP(3, 4);
        COMPARE_SWAP(5, 6);
        COMPARE_SWAP(7, 8);
        COMPARE_SWAP(9, 10);
        COMPARE_SWAP(11, 12);
        COMPARE_SWAP(13, 14);

        // Stage 5
        COMPARE_SWAP(0, 1);
        COMPARE_SWAP(2, 3);
        COMPARE_SWAP(4, 5);
        COMPARE_SWAP(6, 7);
        COMPARE_SWAP(8, 9);
        COMPARE_SWAP(10, 11);
        COMPARE_SWAP(12, 13);
        COMPARE_SWAP(14, 15);

        // Stage 6
        COMPARE_SWAP(1, 2);
        COMPARE_SWAP(3, 4);
        COMPARE_SWAP(5, 6);
        COMPARE_SWAP(7, 8);
        COMPARE_SWAP(9, 10);
        COMPARE_SWAP(11, 12);
        COMPARE_SWAP(13, 14);

        // Stage 7
        COMPARE_SWAP(0, 1);
        COMPARE_SWAP(2, 3);
        COMPARE_SWAP(4, 5);
        COMPARE_SWAP(6, 7);
        COMPARE_SWAP(8, 9);
        COMPARE_SWAP(10, 11);
        COMPARE_SWAP(12, 13);
        COMPARE_SWAP(14, 15);

        // Stage 8
        COMPARE_SWAP(1, 2);
        COMPARE_SWAP(3, 4);
        COMPARE_SWAP(5, 6);
        COMPARE_SWAP(7, 8);
        COMPARE_SWAP(9, 10);
        COMPARE_SWAP(11, 12);
        COMPARE_SWAP(13, 14);

        // Stage 9
        COMPARE_SWAP(0, 1);
        COMPARE_SWAP(2, 3);
        COMPARE_SWAP(4, 5);
        COMPARE_SWAP(6, 7);
        COMPARE_SWAP(8, 9);
        COMPARE_SWAP(10, 11);
        COMPARE_SWAP(12, 13);
        COMPARE_SWAP(14, 15);

        // Stage 10
        COMPARE_SWAP(1, 2);
        COMPARE_SWAP(3, 4);
        COMPARE_SWAP(5, 6);
        COMPARE_SWAP(7, 8);
        COMPARE_SWAP(9, 10);
        COMPARE_SWAP(11, 12);
        COMPARE_SWAP(13, 14);

        // Stage 11
        COMPARE_SWAP(0, 1);
        COMPARE_SWAP(2, 3);
        COMPARE_SWAP(4, 5);
        COMPARE_SWAP(6, 7);
        COMPARE_SWAP(8, 9);
        COMPARE_SWAP(10, 11);
        COMPARE_SWAP(12, 13);
        COMPARE_SWAP(14, 15);

        // Stage 12
        COMPARE_SWAP(1, 2);
        COMPARE_SWAP(3, 4);
        COMPARE_SWAP(5, 6);
        COMPARE_SWAP(7, 8);
        COMPARE_SWAP(9, 10);
        COMPARE_SWAP(11, 12);
        COMPARE_SWAP(13, 14);

        // Stage 13
        COMPARE_SWAP(0, 1);
        COMPARE_SWAP(2, 3);
        COMPARE_SWAP(4, 5);
        COMPARE_SWAP(6, 7);
        COMPARE_SWAP(8, 9);
        COMPARE_SWAP(10, 11);
        COMPARE_SWAP(12, 13);
        COMPARE_SWAP(14, 15);

        // Stage 14
        COMPARE_SWAP(1, 2);
        COMPARE_SWAP(3, 4);
        COMPARE_SWAP(5, 6);
        COMPARE_SWAP(7, 8);
        COMPARE_SWAP(9, 10);
        COMPARE_SWAP(11, 12);
        COMPARE_SWAP(13, 14);

        // Stage 15
        COMPARE_SWAP(0, 1);
        COMPARE_SWAP(2, 3);
        COMPARE_SWAP(4, 5);
        COMPARE_SWAP(6, 7);
        COMPARE_SWAP(8, 9);
        COMPARE_SWAP(10, 11);
        COMPARE_SWAP(12, 13);
        COMPARE_SWAP(14, 15);

        // Stage 16
        COMPARE_SWAP(1, 2);
        COMPARE_SWAP(3, 4);
        COMPARE_SWAP(5, 6);
        COMPARE_SWAP(7, 8);
        COMPARE_SWAP(9, 10);
        COMPARE_SWAP(11, 12);
        COMPARE_SWAP(13, 14);

        return;
    }

    // Fallback for sizes other than 16.
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