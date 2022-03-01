//4. Implement the programs in Q.2 and 3 breaking it into functions for i) getting the dimensions from user, ii) dynamic memory allocation, iii) accepting the values and iv) printing the values.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void getDim(int *n, int *r) //function to get dimensions as input
{
    printf("Enter the no. of columns = ");
    scanf("%d", n);
    printf("Enter the no. of rows = ");
    scanf("%d", r);
}

int *memD(int n, int r) //function for memory llocation
{
    int *p = (int *)malloc(r * n * sizeof(int));
    return p;
}

void inVal(int *temp, int n, int r) //function to accept values row-wise into the array
{
    int i, j;
    int(*arr)[n] = (int(*)[n])temp;
    printf("Enter the values row-wise:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", (*(arr + i) + j));
    }
}

void outVal(int *temp, int n, int r) //function to print the values using pointer to array
{
    int i, j;
    int(*arr)[n] = (int(*)[n])temp;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < n; j++)
            printf("arr[%d][%d] = %d\t|\t", i, j, *(*(arr + i) + j));
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    int n, r;

    getDim(&n, &r);

    int *p = memD(n, r);

    inVal(p, n, r); 

    outVal(p, n, r); 

    free(p);
    return 0;
}