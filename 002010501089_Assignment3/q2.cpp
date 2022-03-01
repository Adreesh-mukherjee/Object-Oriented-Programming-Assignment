#include <iostream>
#include <chrono>

using namespace std::chrono;
//INLINE FUNCTION
inline int product(int a, int b)
{
    return a * b;
}

//NORMAL FUNCTION
int prod(int a, int b)
{
    return a * b;
}

//MAIN FUNCTION
int main(int argc, char const *argv[])
{
    auto start1 = high_resolution_clock::now();     //TIME COUNT STARTS

    /*TOTAL ITERATIONS =50*/
    for (size_t i = 0; i < 50; i++)
    {
        std::cout << product(12, 10) << '\n';
    }

    auto stop1 = high_resolution_clock::now();      
    auto duration1 = duration_cast<microseconds>(stop1 - start1);       //calculating the time 
    std::cout << "Time taken by inline function: " << duration1.count() << " microseconds" << '\n';


    auto start2 = high_resolution_clock::now();     //TIME COUNT STARTS
    
    /*TOTAL ITERATIONS =50*/
    for (size_t i = 0; i < 50; i++)
    {
        std::cout << prod(12, 10) << '\n';
    }
    
    
    auto stop2 = high_resolution_clock::now();      
    auto duration2 = duration_cast<microseconds>(stop2 - start2);       //calculating the time
    std::cout << "Time taken by normal function: " << duration2.count() << " microseconds" << '\n';
    
    
    


    return 0;
}