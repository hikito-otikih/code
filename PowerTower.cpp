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
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const ll oo = 2e18;
const double eps = 1e-9;

int n, m, w[N], phi[N];

void Input(void) 
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> w[i];
}

int POW(int a, int b, int mod) 
{
    int res = 1;
    for (; b; b >>= 1, a = 1LL * a * a % mod)
        if (b & 1) res = 1LL * res * a % mod;
    return res;
}

void solve(void) 
{
    phi[0] = m;
    for (int i = 1; i <= 100; i ++)
    {
        int x = phi[i - 1];
        phi[i] = phi[i - 1];
        for (int j = 2; j * j <= x; j ++)
            if (x % j == 0)
            {
                phi[i] -= phi[i] / j;
                while (x % j == 0) x /= j;
            }
        if (x > 1) phi[i] -= phi[i] / x;
    }
    int lim = 0;
    while (lim < 100 && phi[lim + 1] > 1) lim ++;
    int Q;
    cin >> Q;
    while (Q --) 
    {
        int x, y;
        cin >> x >> y;
        if (y - x <= lim)
        {
            int res = w[y] % phi[y - x];
            for (int i = y - 1; i >= x; i --)
            {
                cout << i << ' ' << res<< ' '<< phi[i - x] << '\n';
                res = POW(w[i], res, phi[i - x]);
            }
            cout << res << '\n';
        }
        else
        {
            int res = 0;
            for (int i = x + lim; i >= x; i --)
            {
                res = POW(w[i], res, phi[i - x]);
            }
            cout << res << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task ".INP", "r"))
        freopen(task ".INP", "r", stdin),
            freopen(task ".OUT", "w", stdout);
    int test = 1;
//    cin >> test;
    while (test --) {
        Input();
        solve();
    }
    return 0;
}
