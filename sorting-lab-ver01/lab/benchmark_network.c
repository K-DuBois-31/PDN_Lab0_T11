/*
    Objective E - Sorting network benchmark

    Compares a fixed-size sorting network against Insertion Sort.
    Input generation occurs outside the timed sections.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef NETWORK_SIZE
#define NETWORK_SIZE 4
#endif

#define INPUT_COUNT 1024
#define ITERATIONS 200000

void compute_tst(int m0, float *x, float *y);

static volatile float checksum_sink;

static void insertion_sort(int n, float *x, float *y)
{
    for (int i = 0; i < n; i++)
        y[i] = x[i];

    for (int i = 1; i < n; i++)
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

int main(void)
{
    float inputs[INPUT_COUNT][NETWORK_SIZE];
    float output[NETWORK_SIZE];

    float checksum = 0.0f;

    srand(12345);

    // Generate all inputs before timing.
    for (int t = 0; t < INPUT_COUNT; t++)
    {
        for (int i = 0; i < NETWORK_SIZE; i++)
        {
            inputs[t][i] = (float)((rand() % 2001) - 1000);
        }
    }

    // Benchmark the sorting network.
    clock_t start = clock();

    for (int t = 0; t < ITERATIONS; t++)
    {
        float *x = inputs[t % INPUT_COUNT];

        compute_tst(NETWORK_SIZE, x, output);

        checksum += output[t % NETWORK_SIZE];
    }

    clock_t end = clock();

    double network_seconds =
        (double)(end - start) / CLOCKS_PER_SEC;

    checksum_sink = checksum;

    // Benchmark Insertion Sort on the same inputs.
    checksum = 0.0f;

    start = clock();

    for (int t = 0; t < ITERATIONS; t++)
    {
        float *x = inputs[t % INPUT_COUNT];

        insertion_sort(NETWORK_SIZE, x, output);

        checksum += output[t % NETWORK_SIZE];
    }

    end = clock();

    double insertion_seconds =
        (double)(end - start) / CLOCKS_PER_SEC;

    checksum_sink = checksum;

    printf("%d,%.9f,%.9f\n",
           NETWORK_SIZE,
           network_seconds,
           insertion_seconds);

    return 0;
}