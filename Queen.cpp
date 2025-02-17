#include <iostream>

using namespace std;

const int N = 8;

int n, b[100], c[100], d[N], e[N], ans = 0;

void rec(int num)
{
    ans = max(ans, num);
    if (num >= n) exit(0);
    for (int i = 0; i < n; i ++)
        if (!d[i])
            for (int j = 0; j < n; j ++)
                if (!e[j] && !b[i + j] && !c[i - j + N])
                {
                    b[i + j] = c[i - j + N] = 1;
                    d[i] = e[j] = 1;
                    rec(num + 1);
                    b[i + j] = c[i - j + N] = 0;
                    d[i] = e[j] = 0;
                }
}

int main()
{
    cin >> n;
    rec(0);
    cout << ans;
    return 0;
}