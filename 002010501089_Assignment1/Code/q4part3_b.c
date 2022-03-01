//4. Implement the programs in Q.2 and 3 breaking it into functions for i) getting the dimensions from user, ii) dynamic memory allocation, iii) accepting the values and iv) printing the values.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void getDim(int *n, int *r) // function to input dimensions of array
{
    printf("Enter the no. of columns = ");
    scanf("%d", n);
    printf("Enter the no. of rows = ");
    scanf("%d", r);
}

void memA(int **p, int r, int n) // function for memory allocation
{
    for (int i = 0; i < r; i++)
    {
        *(p + i) = (int *)malloc(n * sizeof(int));
    }
}

void inVal(int **temp, int n, int r) // function to take input values 
{
    int i, j;
    printf("Enter the values row-wise:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", (*(temp + i) + j));
    }
}

void outVal(int **temp, int n, int r) // function to print values using array of pointers
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < n; j++)
            printf("arr[%d][%d] = %d\t|\t", i, j, *(*(temp + i) + j));
        printf("\n");
    }
}

void memD(int **x, int r) // deallocation of memory
{
    for (int i = 0; i < r; i++)
    {
        free(*(x + i));
    }
}

int main(int argc, char **argv) // main function with all the other other functions being called
{
    int n, r;

    getDim(&n, &r); 

    int *p[r];
    memA(p, r, n); 

    inVal(p, n, r); 

    outVal(p, n, r); 

    memD(p, r);

    return 0;
}