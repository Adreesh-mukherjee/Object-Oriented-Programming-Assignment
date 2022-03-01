//4. Implement the programs in Q.2 and 3 breaking it into functions for i) getting the dimensions from user, ii) dynamic memory allocation, iii) accepting the values and iv) printing the values.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int getDim(int *p) //function to get the dimensions of array as input
{
    printf("Enter the no. of elements = ");
    scanf("%d", p);
    return *p;
}

int *getPtr(int *arr, int n) //function for memory alloation
{
    arr = (int *)malloc(n * sizeof(int));
    return arr;
}

void inputVal(int *arr, int n) //function to enter values
{
    int i;
    printf("Enter the values:\n");
    for (i = 0; i < n; i++)
        scanf("%d", (arr + i));
}

void outputVal(int *arr, int n) //function to print values
{
    int i;
    printf("Values:\n");
    for (i = 0; i < n; i++)
        printf("arr[%d] = %d  |  ", i, *(arr + i));
    printf("\n");
}

int main(int argc, char **argv)
{
    int n, i;
    n = getDim(&n);
    int *arr;
    arr = getPtr(arr, n);
    inputVal(arr, n);
    outputVal(arr, n);
    return 0;
}