#include <stdio.h>
#include <stdlib.h>

/**
 * Compares two numbers and returns a positive integer, 0 or
 * a negative integer if the first number is greater than, equal to
 * or less than the second number.
 * Assumes the numbers are of the type int.
 * Used when invoking the quicksort function.
 */
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

/**
 * Takes in an array of integers and the number of elements in the array
 * as arguments.
 * Then it will sort and return the median of the sorted array.
 * To keep things simple, it always returns
 * the element at index arr_size/2 even though the
 * array size is even.
 */
int return_median(int *arr, int size)
{
    qsort(arr, size, sizeof(int), compare);
    return arr[size / 2];
}

/**
 * Takes in a random number and maps it to the
 * range [100000 - 120000)
 */
int get_iteration_count(int rand)
{
    return (rand % 20000) + 100000;
}

/**
 * Takes in a random number and maps it to the
 * range [1000 - 1500)
 */
int get_arr_size(int rand)
{
    return (rand % 500) + 1000;
}

/**
 * This is the method that you need to implement.
 * Implement the following steps in the given order.
 *
 *  1. Generate the number of iterations
 *      - Generate a random number. Map it to the range [100000 - 120000) using the
 *      utility function 'get_iteration_count'.
 *
 * 2. For each iteration:
 *      2.a Generate an array size - Generate a random number and map it to the range [1000 - 1500) using
 *          the utility function 'get_arr_size'.
 *
 *      2.b Allocate memory for the array in the heap.
 *
 *      2.c Populate the array with random numbers.
 *
 *      2.d Get the median of the array using the function 'return_median'.
 *
 *      2.e Check if the median is divisible by 13.
 *
 *      2.f Return the number of medians that were divisible by 13.
 *
 */
int get_running_count(int running_count)
{
    // TODO: Implement this method.
    int *arr;
    int iterations = get_iteration_count(rand());
    int arrSize;
    int mediansDivisible = 0; // Divisible by 13, specifically

    // For each iteration
    for (int i = 0; i < iterations; i++)
    {
        arrSize = get_arr_size(rand());
        // Allocate memory on the heap for the given size of the array
        arr = (int *)malloc(arrSize * sizeof(int));

        // For every entry in the array assign a random number
        for (int n = 0; n < arrSize; n++)
        {
            arr[n] = rand();
        }

        // If the median number in the array is divisble, increment the count
        if ((return_median(arr, arrSize) % 13) == 0)
        {
            mediansDivisible++;
        }
        free(arr);
    }
    printf("[MemoryManager] Number of Iterations: %d\n", iterations);
    return mediansDivisible;
}
