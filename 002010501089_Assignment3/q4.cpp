#include<iostream>
using namespace std;

int* max(int a,int b)
{
    return &((a>b)?a:b);
}
int main()
{
    int *x; //POINTER VARIABLE TO STORE REFERENCE OF LARGER NUMBER
    

    int a,b;
    x=max(a,b);

    cout<<"Enter the values a and b : ";
    cin>>a>>b;

    cout<<"Value of a = "<<a<<endl<<"Value of b = "<<b<<endl<<"Value of max(a,b) when return type is int* : "<<x<<endl;
}