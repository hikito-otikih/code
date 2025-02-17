#include <iostream>

using namespace std;

const int N = 20;

int dd[N], n;

void permu(int i, int mask)
{
    if (i > n)
    {
        for (int j = 1; j <= n; j ++) cout << dd[j] << ' ';
        cout << '\n';
        return ;
    }
    for (int k = mask; k; k -= (k & -k))
    {
        int j = __builtin_ctz(k);
        dd[i] = j + 1;
        permu(i + 1, mask ^ ((1 << j)));
    }
}

int main()
{
    cin >> n;
    permu(1, (1 << n) - 1);
    return 0;
}
