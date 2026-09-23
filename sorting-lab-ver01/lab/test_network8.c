#include <stdio.h>

#define N 8

void compute_tst(int m0, float *x, float *y);

static int tests = 0;
static int failures = 0;

static void test_permutations(float *x, int pos)
{
    if (pos == N)
    {
        float y[N];

        compute_tst(N, x, y);
        tests++;

        for (int i = 0; i < N; i++)
        {
            if (y[i] != (float)(i + 1))
            {
                failures++;

                printf("FAIL: ");

                for (int j = 0; j < N; j++)
                    printf("%.0f ", x[j]);

                printf("\n");

                break;
            }
        }

        return;
    }

    for (int i = pos; i < N; i++)
    {
        float temp = x[pos];
        x[pos] = x[i];
        x[i] = temp;

        test_permutations(x, pos + 1);

        temp = x[pos];
        x[pos] = x[i];
        x[i] = temp;
    }
}

int main(void)
{
    float x[N] = {1, 2, 3, 4, 5, 6, 7, 8};

    test_permutations(x, 0);

    printf("Tests: %d\n", tests);
    printf("Failures: %d\n", failures);

    return failures == 0 ? 0 : 1;
}