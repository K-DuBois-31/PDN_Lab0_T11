#include <stdio.h>
#include <stdlib.h>

#define N 16
#define RANDOM_TESTS 100000

void compute_tst(int m0, float *x, float *y);

static int tests = 0;
static int failures = 0;

static void check(float *x)
{
    float y[N];

    compute_tst(N, x, y);
    tests++;

    for (int i = 1; i < N; i++)
    {
        if (y[i - 1] > y[i])
        {
            failures++;

            if (failures <= 5)
            {
                printf("FAIL on test %d\n", tests);
            }

            return;
        }
    }

    // Check that output preserves the input values.
    // All test values are integers, so sums can be compared exactly.
    float input_sum = 0.0f;
    float output_sum = 0.0f;

    for (int i = 0; i < N; i++)
    {
        input_sum += x[i];
        output_sum += y[i];
    }

    if (input_sum != output_sum)
    {
        failures++;

        if (failures <= 5)
        {
            printf("FAIL: values changed on test %d\n", tests);
        }
    }
}

int main(void)
{
    float x[N];

    // Already sorted.
    for (int i = 0; i < N; i++)
        x[i] = (float)i;
    check(x);

    // Reverse sorted.
    for (int i = 0; i < N; i++)
        x[i] = (float)(N - i);
    check(x);

    // All equal.
    for (int i = 0; i < N; i++)
        x[i] = 5.0f;
    check(x);

    // Alternating high and low values.
    for (int i = 0; i < N; i++)
        x[i] = (i % 2 == 0) ? 100.0f : -100.0f;
    check(x);

    // Randomized tests, including duplicates and negative values.
    srand(12345);

    for (int t = 0; t < RANDOM_TESTS; t++)
    {
        for (int i = 0; i < N; i++)
        {
            x[i] = (float)((rand() % 201) - 100);
        }

        check(x);
    }

    printf("Tests: %d\n", tests);
    printf("Failures: %d\n", failures);

    return failures == 0 ? 0 : 1;
}