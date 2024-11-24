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

int n, Mo, pw[N];
vector<pair<int, int> > ar[N];

int POW(int x, int y)
{
    int res = 1;
    for (; y; y >>= 1, x = 1LL * x * x % Mo)
        if (y & 1) res = 1LL * res * x % Mo;
    return res;
}

void Input(void) 
{
    cin >> n >> Mo;
    for (int i = 1; i <= n; i ++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ar[u].push_back({v, w});
        ar[v].push_back({u, w});
    }
    pw[0] = 1;
    for (int i = 1; i <= n; i ++) pw[i] = 1LL * pw[i - 1] * 10 % Mo;
    for (int i = 1; i <= n; i ++) pw[i] = POW(pw[i], Mo - 2);
}

void centroid(int u, int p) 
{
    
}

void solve(void) 
{
    centroid(1, 0);
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
