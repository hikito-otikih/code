#include <bits/stdc++.h>
using namespace std;

int a[] = {74, 12, 217, 36, 61, 77, 286, 153, 337, 93, 121, 47, 463, 248, 146};

int b[100];

int main()
{
    int n = 15;
    memset(b, -1, sizeof b);
    //quadric probing
    for (int i = 1; i < n; i ++) 
    {
        int x = a[i] % 23;
        int y = a[i] % 22 + 1;
        int j = 0;
        while (b[(x + j * y) % 23] != -1) j ++;

        b[x] = a[i];
    }
    for (int i = 0; i < 23; i ++) cout << i << '\t';
    cout << '\n';
    for (int i = 0; i < 23; i ++) cout << b[i] << '\t';
    return 0;
}