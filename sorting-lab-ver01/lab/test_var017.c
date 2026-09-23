/*
    Objective E - 32-element odd-even sorting network

    32 fixed stages.
    496 compare-and-swap operations.
    Up to 16 independent comparisons per stage.
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

/*
    Even stage: 16 independent comparisons.
    Each comparison operates on a separate pair.
*/
#define EVEN_STAGE()                 \
    do {                             \
        COMPARE_SWAP(0, 1);          \
        COMPARE_SWAP(2, 3);          \
        COMPARE_SWAP(4, 5);          \
        COMPARE_SWAP(6, 7);          \
        COMPARE_SWAP(8, 9);          \
        COMPARE_SWAP(10, 11);        \
        COMPARE_SWAP(12, 13);        \
        COMPARE_SWAP(14, 15);        \
        COMPARE_SWAP(16, 17);        \
        COMPARE_SWAP(18, 19);        \
        COMPARE_SWAP(20, 21);        \
        COMPARE_SWAP(22, 23);        \
        COMPARE_SWAP(24, 25);        \
        COMPARE_SWAP(26, 27);        \
        COMPARE_SWAP(28, 29);        \
        COMPARE_SWAP(30, 31);        \
    } while (0)

/*
    Odd stage: 15 independent comparisons.
*/
#define ODD_STAGE()                  \
    do {                             \
        COMPARE_SWAP(1, 2);          \
        COMPARE_SWAP(3, 4);          \
        COMPARE_SWAP(5, 6);          \
        COMPARE_SWAP(7, 8);          \
        COMPARE_SWAP(9, 10);         \
        COMPARE_SWAP(11, 12);        \
        COMPARE_SWAP(13, 14);        \
        COMPARE_SWAP(15, 16);        \
        COMPARE_SWAP(17, 18);        \
        COMPARE_SWAP(19, 20);        \
        COMPARE_SWAP(21, 22);        \
        COMPARE_SWAP(23, 24);        \
        COMPARE_SWAP(25, 26);        \
        COMPARE_SWAP(27, 28);        \
        COMPARE_SWAP(29, 30);        \
    } while (0)

void COMPUTE_NAME(int m0, float *x, float *y)
{
    // Copy input to output.
    for (int i = 0; i < m0; i++)
    {
        y[i] = x[i];
    }

    if (m0 == 32)
    {
        // Stages 1-8
        EVEN_STAGE();  // Stage 1
        ODD_STAGE();   // Stage 2
        EVEN_STAGE();  // Stage 3
        ODD_STAGE();   // Stage 4
        EVEN_STAGE();  // Stage 5
        ODD_STAGE();   // Stage 6
        EVEN_STAGE();  // Stage 7
        ODD_STAGE();   // Stage 8

        // Stages 9-16
        EVEN_STAGE();  // Stage 9
        ODD_STAGE();   // Stage 10
        EVEN_STAGE();  // Stage 11
        ODD_STAGE();   // Stage 12
        EVEN_STAGE();  // Stage 13
        ODD_STAGE();   // Stage 14
        EVEN_STAGE();  // Stage 15
        ODD_STAGE();   // Stage 16

        // Stages 17-24
        EVEN_STAGE();  // Stage 17
        ODD_STAGE();   // Stage 18
        EVEN_STAGE();  // Stage 19
        ODD_STAGE();   // Stage 20
        EVEN_STAGE();  // Stage 21
        ODD_STAGE();   // Stage 22
        EVEN_STAGE();  // Stage 23
        ODD_STAGE();   // Stage 24

        // Stages 25-32
        EVEN_STAGE();  // Stage 25
        ODD_STAGE();   // Stage 26
        EVEN_STAGE();  // Stage 27
        ODD_STAGE();   // Stage 28
        EVEN_STAGE();  // Stage 29
        ODD_STAGE();   // Stage 30
        EVEN_STAGE();  // Stage 31
        ODD_STAGE();   // Stage 32

        return;
    }

    // Fallback for sizes other than 32.
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