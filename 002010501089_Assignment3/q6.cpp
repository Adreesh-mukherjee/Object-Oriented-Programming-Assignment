#include<iostream>

void f(int)        
{
    std::cout << "Inside f(int)" << '\n';    
}
void f(float)       
{
    std::cout << "Inside f(float)" << '\n';   
}

int main(int argc, char const *argv[])     
{
    int i1;
    float f1;
    double d1;
    char c1;

    f(i1);      

    f(f1);     

    f(c1);    

    //f(d1); 


    f(i1);     

    f(f1);     

    f(c1);

    
    return 0;
}
