#include <iostream>

using namespace std;

int main()
{
    int *x = new int;
    *x = 10;
    int *y = x;
    x = NULL;
    cout << *y<< endl;
    return 0;
}