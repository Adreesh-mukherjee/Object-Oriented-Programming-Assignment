//1. Write a program that will have an integer variable and a pointer (say, p) pointing to it. Also have a pointer to pointer pointing to p. Take the value for the integer variable and print it using p, and pp.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
    int n;

    int *p; //pointer to a variable
    p = &n; 

    int **pp; //pointer to a pointer
    pp = &p; 

    printf("Enter the value of n = "); 

    scanf("%d", &n); 
   

    printf("Value of n = %d\n", n);
    printf("Value of n using first pointer p = %d\n", *p); //printing the value using pointer
    printf("Value of n using second pointer pp = %d\n", **pp); //printing the value using pointer to pointer
}
