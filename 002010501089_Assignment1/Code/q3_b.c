//3. Implement a two dimensional array of integers using a) pointer to an array and b) array of pointers. Accept the value for the elements and print those.

#include <stdio.h>
int main()
{
    int r , c;
    printf("Enter the number of rows:");
    scanf("%d",&r);
    printf("Enter the number of columns:");
    scanf("%d",&c);
    int arr[r][c];
    printf("Enter the elements of array: \n");
    for(int i=0; i<r; i++) //scanning entries in array
    {
        for(int j=0; j<c; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int *p[r][c]; //declaring pointer array
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            p[i][j] = &arr[i][j];
        }
    }
    printf("The elements are: \n");
     for(int i=0; i<r; i++) //printing elements using array of pointers
     {
        for(int j=0; j<c; j++)
        {
            printf("%d ", *p[i][j]);
        }
        printf("\n");
        
     }
     return 0;
}
