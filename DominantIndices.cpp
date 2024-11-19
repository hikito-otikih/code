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

int n, res[N];
vector<int> ar[N];
map<int, int> f[N];

void Input(void) 
{
    cin >> n;
    for (int i = 1; i < n; i ++)
    {
        int u, v;
        cin >> u >> v;
        ar[u].push_back(v);
        ar[v].push_back(u);
    }
}

void DFS(int u, int p)
{
    map<int, int> tmp;
    for (int v: ar[u])
        if (v != p)
        {
            DFS(v, u);
            if (sz(f[v]) > sz(tmp)) swap(f[v], tmp);
            for (auto x: f[v]) tmp[x.F] += x.S;
        }
    f[u][0] = 1;
    res[u] = 0;
    int save = 1;
    for (auto x: tmp) 
    {
        f[u][x.F + 1] = x.S;
        if (x.S > save) save = x.S, res[u] = x.F + 1;
        else 
            if (x.S == save) res[u] = min(res[u], x.F + 1);
    }
}

void solve(void) 
{
    DFS(1, 0);
    for (int i = 1; i <= n; i ++) cout << res[i] << ' ';
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
