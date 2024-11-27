#include <bits/stdc++.h>

#define MASK(i) (1LL << (i))
#define BIT(x, y) (((x) >> (y)) & 1)
#define sz(v) ((ll) (v).size())
#define all(v) (v).begin(), (v).end()
#define uni(v) sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define F first
#define S second
#define pii(x, y) make_pair(x, y)
#define __builtin_popcount __builtin_popcountll
#define __builtin_ctz __builtin_ctzll
#define __builtin_clz __builtin_clzll
#define lg(x) (63 - __builtin_clz(x))
#define task "test"

template <class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y) {x = y; return 1;}
        return 0;
    }

template <class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {x = y; return 1;}
        return 0;
    }

using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int M = 1e5;
const int MOD = 998244353;
const int INF = 1e9 + 7;
const ll oo = 2e18;
const double eps = 1e-9;

int n, f[N], g[N], h[N], c[N];

void prepare(void)
{
    f[2] = 1;
    f[3] = 2;
    ///
    f[4] = 5;
    c[4] = 3;
    h[4] = 1;
    g[4] = 0;

    for (int i = 5; i < N; i ++)
    {
        g[i] = (c[i - 1] - h[i - 1] + 1LL * g[i - 1] * (i - 2) % MOD + MOD) % MOD;
        h[i] = (h[i - 1] + g[i - 1] + 1) % MOD;
        c[i] = (c[i - 1] + 1LL * (g[i - 1] + 1) * (i - 1) % MOD) % MOD;
        f[i] = (2 + c[i] + 1LL * g[i] * i % MOD) % MOD;
    }
}

void Input(void) 
{
    cin >> n;
}

void solve(void) 
{
    cout << f[n] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task ".INP", "r"))
        freopen(task ".INP", "r", stdin),
            freopen(task ".OUT", "w", stdout);
    prepare();
    int test = 1;
    cin >> test;
    while (test --) {
        Input();
        solve();
    }
    return 0;
}
