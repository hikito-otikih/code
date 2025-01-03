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

int n, res[N], ans[N];
vector<int> ar[N];
vector<int> f[N];

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
    for (int v: ar[u])
        if (v != p)
        {
            DFS(v, u);
            if (sz(f[v]) > sz(f[u])) 
            {
                swap(f[u], f[v]);
                swap(res[u], res[v]);
            }
            for (int i = 0; i < sz(f[v]); i ++) 
            {
                f[u][sz(f[u]) - sz(f[v]) + i] += f[v][i];
                if (f[u][res[u]] < f[u][sz(f[u]) - sz(f[v]) + i]
                || (f[u][res[u]] == f[u][sz(f[u]) - sz(f[v]) + i] && res[u] < sz(f[u]) - sz(f[v]) + i)) 
                    res[u] = sz(f[u]) - sz(f[v]) + i;
            }
            f[v].clear();
        }
    f[u].push_back(1);
    if (f[u][res[u]] < f[u][sz(f[u]) - 1] 
    || (f[u][res[u]] == f[u][sz(f[u]) - 1] && res[u] < sz(f[u]) - 1)) 
        res[u] = sz(f[u]) - 1;
    ans[u] = sz(f[u]) - res[u] - 1;
}

void solve(void) 
{
    DFS(1, 0);
    for (int i = 1; i <= n; i ++) cout << ans[i] << ' ';
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
