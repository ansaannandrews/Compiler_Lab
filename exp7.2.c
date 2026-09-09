#include <stdio.h>
#include <time.h>

/* Original program - Without Constant Propagation */
void originalProgram()
{
    int a = 5;
    int b = 10;
    int c = a + b;

    printf("Original Program Output:\n");
    printf("Sum: %d\n", c);
}

/* Optimized program - With Constant Propagation */
void optimizedProgram()
{
    int c = 5 + 10;

    printf("Optimized Program Output:\n");
    printf("Sum: %d\n", c);
}

int main()
{
    clock_t start, end;
    double original_time, optimized_time;

    /* Execute Original Program */
    start = clock();

    originalProgram();

    end = clock();

    original_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Original Program Time: %f seconds\n\n", original_time);


    /* Execute Optimized Program */
    start = clock();

    optimizedProgram();

    end = clock();

    optimized_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Optimized Program Time: %f seconds\n\n", optimized_time);


    /* Compare execution times */
    printf("Execution Time Comparison:\n");

    if (original_time < optimized_time)
    {
        printf("Original program is faster.\n");
    }
    else if (optimized_time < original_time)
    {
        printf("Optimized program is faster.\n");
    }
    else
    {
        printf("Both programs have approximately the same execution time.\n");
    }

    return 0;
}

