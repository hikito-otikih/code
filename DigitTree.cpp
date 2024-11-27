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

int n, Mo, pw[N], iv[N];
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
    for (int i = 1; i < n; i ++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u ++, v ++;
        ar[u].push_back({v, w});
        ar[v].push_back({u, w});
    }
}

int subtree[N];
bool used[N];

int DFS(int u, int pa)
{
    subtree[u] = 1;
    for (auto v : ar[u])
        if (v.F != pa && !used[v.F])
            subtree[u] += DFS(v.F, u);
    return subtree[u];
}

int findCentroid(int u, int p, int lim)
{
    for (auto v : ar[u])
        if (v.F != p && !used[v.F] && subtree[v.F] > lim)
            return findCentroid(v.F, u, lim);
    return u;
}

map<int, int> cnt[2];
long long ans = 0;

void DFS2(int u, int p, int depth, int sumFromLeaf, int sumFromRoot, bool add)
{
    if (add) 
    {
        cnt[0][sumFromLeaf] ++;
        cnt[1][1LL * (Mo - sumFromRoot) * iv[depth] % Mo] ++;   
    }
    else
    {
        ans += cnt[0][1LL * (Mo - sumFromRoot) * iv[depth] % Mo];
        ans += cnt[1][sumFromLeaf];
    }
    for (auto v : ar[u])
        if (v.F != p && !used[v.F])
        {
            int w = v.S;
            int SumFromLeaf = (1LL * pw[depth] * w + sumFromLeaf) % Mo;
            int SumFromRoot = (1LL * sumFromRoot * 10 + w) % Mo;
            DFS2(v.F, u, depth + 1, SumFromLeaf, SumFromRoot, add);
        }
}

void centroid(int u) 
{
    DFS(u, 0);
    int c = findCentroid(u, 0, subtree[u] >> 1);
    used[c] = 1;
    cnt[0][0] = 1;
    cnt[1][0] = 1;
    for (auto v : ar[c])
        if (!used[v.F])
        {
            int w = v.S;
            DFS2(v.F, c, 1, w % Mo, w % Mo, 0);
            DFS2(v.F, c, 1, w % Mo, w % Mo, 1);
        }
    cnt[0].clear();
    cnt[1].clear();
    for (auto v : ar[c])
        if (!used[v.F])
            centroid(v.F);
}

void solve(void) 
{
    if (Mo == 1)
    {
        cout << 1LL * n * (n - 1);
        return;
    }
    int phi = Mo, x = Mo;
    for (int i = 2; 1LL * i * i <= x; i ++)
        if (x % i == 0)
        {
            phi -= phi / i;
            while (x % i == 0) x /= i;
        }
    if (x > 1) phi -= phi / x;
    
    pw[0] = 1;
    for (int i = 1; i <= n; i ++) pw[i] = 1LL * pw[i - 1] * 10 % Mo;
    iv[n] = POW(pw[n], phi - 1);
    for (int i = n; i >= 1; i --) iv[i - 1] = 1LL * iv[i] * 10 % Mo;
    centroid(1);
    cout << ans;
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
