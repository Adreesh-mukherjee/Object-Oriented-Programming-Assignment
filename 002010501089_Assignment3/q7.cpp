#include<iostream>

void f(int, int)        
{
    std::cout << "Inside f(int, int)" << '\n';
}
void f(char, int)        
{
    std::cout << "Inside f(char, int)" << '\n';
}
int main(int argc, char const *argv[])     
{
    int i;
    float f0, f1;
    char c, ch;

    f(i,c);// INPUT AS INT, CHAR
    f(c,ch);// INPUT AS CHAR, CHAR
    
   
    return 0;
}