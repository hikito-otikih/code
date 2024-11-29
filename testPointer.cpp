#include<iostream>

using namespace std;

int main() 
{
    int x = 1, y = 2;
    int *a[] = {&x, &y};
    cout << a[1];
    return 0;
}