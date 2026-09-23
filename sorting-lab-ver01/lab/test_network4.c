#include <stdio.h>

void compute_tst(int m0, float *x, float *y);

static int tests = 0;
static int failures = 0;

static void test_permutations(float *x, int pos)
{
    if (pos == 4)
    {
        float y[4];

        compute_tst(4, x, y);
        tests++;

        for (int i = 0; i < 4; i++)
        {
            if (y[i] != (float)(i + 1))
            {
                failures++;
                printf("FAIL: ");

                for (int j = 0; j < 4; j++)
                    printf("%.0f ", x[j]);

                printf("\n");
                break;
            }
        }

        return;
    }

    for (int i = pos; i < 4; i++)
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
    float x[4] = {1, 2, 3, 4};

    test_permutations(x, 0);

    printf("Tests: %d\n", tests);
    printf("Failures: %d\n", failures);

    return failures == 0 ? 0 : 1;
}