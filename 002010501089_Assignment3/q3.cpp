#include<iostream>
using namespace std;


void swap(int x,int y) //FUNTION TO SWAP VALUES
{
    int temp; //TEMP VARIABLE FOR SWAPPING

    temp = x;
    x = y;
    y = temp;

    cout<<"The values after swappping are : "<<x<<"  "<<y; 
}
int main()
{
    int x,y;

    cout<<"Enter two numbers : ";
    cin>>x>>y;
    swap(x,y);
    return 0;
}