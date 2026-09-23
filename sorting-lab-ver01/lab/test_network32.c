#include <stdio.h>
#include <stdlib.h>

#define N 32
#define RANDOM_TESTS 100000

void compute_tst(int m0, float *x, float *y);

static int tests = 0;
static int failures = 0;

static int compare_floats(const void *a, const void *b)
{
    float x = *(const float *)a;
    float y = *(const float *)b;

    return (x > y) - (x < y);
}

static void check(float *x)
{
    float y[N];
    float expected[N];

    for (int i = 0; i < N; i++)
    {
        expected[i] = x[i];
    }

    qsort(expected, N, sizeof(float), compare_floats);

    compute_tst(N, x, y);

    tests++;

    for (int i = 0; i < N; i++)
    {
        if (y[i] != expected[i])
        {
            failures++;

            if (failures <= 5)
            {
                printf("FAIL on test %d at index %d\n",
                       tests, i);
            }

            return;
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

    // Alternating high and low.
    for (int i = 0; i < N; i++)
        x[i] = (i % 2 == 0) ? 100.0f : -100.0f;
    check(x);

    // Randomized tests with duplicates and negative values.
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