/**
 * Production compile command
 * clang -O3 -g0 -o C_program main.c
 * gcc -O3 -o C_program main.c
 * ./C_program 100
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

unsigned long long int factorial(unsigned long long int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }
    unsigned long long int result = 1;
    for (int i = 2; i <= num; i++)
    {
        result *= i;
    }
    return result;
}

int main(int argc, char *argv[])
{
    unsigned long long int n;

        unsigned long long int iteration = strtoull(argv[1], NULL, 10);
    unsigned long long int factorial_input = 20;

    unsigned long long int count = 0;
    unsigned long long int final_value = (iteration - 2) * (iteration - 2) * (iteration - 2) * (iteration - 2);

    // Start timer
    clock_t start = clock();

    for (int i = 2; i < iteration; i++)
    {
        for (int j = 2; j < iteration; j++)
        {
            for (int k = 2; k < iteration; k++)
            {
                for (int m = 2; m < iteration; m++)
                {
                    unsigned long long int result = factorial(factorial_input);

                    count += 1;
                    if (count == final_value)
                    {
                        printf("==================================================\n");
                        printf("Result count: %lld\n", count);
                    }
                }
            }
        }
    }

    // End timer
    clock_t end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Expected count: %lld\n", final_value);
    printf("==================================================\n");
    
    printf("C Runtime: %f seconds\n", elapsed_time);
    printf("==================================================\n");

    return 0;
}
