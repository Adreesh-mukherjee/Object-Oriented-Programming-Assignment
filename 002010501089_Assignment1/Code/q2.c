//2. Implement a one dimensional array of integers where array size of the array will be provided during runtime. Accept the value for the elements and print those using pointers.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
    int n, i, *ar;
    printf("Enter the size of the array : ");
    scanf("%d", &n);

    ar = (int *)malloc(n * sizeof(int)); 

    printf("Enter the elements of the array : ");
    for (i = 0; i < n; i++) //scan and enter elemeents in the array
        scanf("%d", (ar + i));

    for (i = 0; i < n; i++) //print the values using pointers
        printf("ar[%d] = %d\n", i, *(ar + i));

    
    return 0;
}
