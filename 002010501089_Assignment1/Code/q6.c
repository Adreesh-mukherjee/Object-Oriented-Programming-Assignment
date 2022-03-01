//6. Implement Q.5 using structure.

#include <stdio.h>
#include <stdlib.h>

int size;
struct person
{

    char name[30];
    int age;
};

void memalloc(struct person *a) //declaring array of struct data type
{
    a = (struct person *)realloc(a, size * sizeof(struct person));
}

void sortdata(struct person *a) //function for selection sort
{
    int i, j;
    struct person temp;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (a[i].age > a[j].age)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void displayData(struct person *a) //function for printing sorted data
{
    int i;
    printf("------------------------------------------\n");
    printf("After sorting in ascending order :\n\nName \t Age\n");
    for (i = 0; i < size; i++)
    {
        printf("\n%s \t %d", a[i].name, a[i].age);
    }
}

int main()
{

    int i;
    struct person *p;
    p = (struct person *)malloc(sizeof(struct person));
    memalloc(p);

    printf("Enter how many person : ");
    scanf("%d", &size);

    for (i = 0; i < size; i++)
    {
        printf("Enter the name of the %d-th person : ", i + 1);
        scanf("%s", &p[i].name);
        printf("Enter the age of the %d-th person : ", i + 1);
        scanf("%d", &p[i].age);
    }
    sortdata(p);
    displayData(p);

    free(p);
    return 0;
}