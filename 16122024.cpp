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

int g[2005], n, m, target;

void Input(void) 
{
    //cin >> n >> m;
}

int dp(int x, int y)
{
    //cout << x << ' '<< y << '\n';
    if (x == 0) return 0;
    if (g[x] != -1) return g[x];
    g[x] = INF;
    for (int i = 1; i <= min(x, y); i ++) {
        if (x + y - i <= target) minimize(g[x], dp(x + y - i - i, y) + 1);
    }
    return g[x];
}

int solve(int x, int y)
{
    memset(g, -1, sizeof g);
    target = x;
    return dp(x, y);
}

void solve(void) 
{
    int k = solve(n, m);
    cout << (k >= INF ? -1 : k) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task ".INP", "r"))
        freopen(task ".INP", "r", stdin),
            freopen(task ".OUT", "w", stdout);
    int test = 1;
    //cin >> test;
    while (cin >> n >> m) {
        Input();
        solve();
    }
    return 0;
}
