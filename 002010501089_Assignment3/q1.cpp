
#include <iostream>
using namespace std;
#define max(x, y) ((x > y) ? x : y) 

int main(int argc, const char *argv[])
{

    int a, b;
    a = 6;
    b = 9;
    int max_val1 = max(a, b);

    cout << "Maximum Value of Integer : " << max_val1 << endl;

    char const *var1 = "asdfg";
    char const *var2 = "vbnmv";

    char const *max_val2 = max(var1, var2);

    cout << "Maximum Value of character : " << max_val2 << endl;

    return 0;
}