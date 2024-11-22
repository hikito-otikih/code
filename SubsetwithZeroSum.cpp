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

int n, a[N];
vector<int> ar[N];
bool vs[N];

void Input(void) 
{
    cin >> n;
    for (int i = 1; i <= n; i ++) ar[i].clear(), vs[i] = 0;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        ar[i].push_back(i - a[i]);
    }
}

vector<int> res, ans;

void DFS(int u)
{
    vs[u] = 1;
    res.push_back(u);
    for (int v : ar[u])
        if (vs[v] == 0) DFS(v);
        else
        {
            if (sz(ans) != 0) continue;
            for (int i = sz(res) - 1; i >= 0; i --)
            {
                ans.push_back(res[i]);
                if (res[i] == v) break;
            }
        }
    res.pop_back();
}


void solve(void) 
{
    ans.clear();
    for (int i = 1; i <= n; i ++)
        if (vs[i] == 0) DFS(i);
    cout << sz(ans) << '\n';
    for (int i : ans) cout << i << ' ';
    cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task ".INP", "r"))
        freopen(task ".INP", "r", stdin),
            freopen(task ".OUT", "w", stdout);
    int test = 1;
    cin >> test;
    while (test --) {
        Input();
        solve();
    }
    return 0;
}