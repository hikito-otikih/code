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
const int N = 666666 + 5;
const int M = 1e5;
const int MOD = 998244353;
const int INF = 1e9 + 7;
const ll oo = 2e18;
const double eps = 1e-9;

int n, q, a[N], pre[N];
int f[N], cnt[N], sum[N];
map<int, int> mp;

void compress()
{
    mp.clear();
    for (int i = 1; i <= n; i ++) 
    {
        int x = a[i];
        a[i] = max(a[i - 1], mp[x]);
        mp[x] = i;
    }
}

void Input(void) 
{
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) cin >> a[i];
}

void add(int &x, int y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

void sub(int &x, int y)
{
    x -= y;
    if (x < 0) x += MOD;
}

pair<int, int> solve(int x)
{
    for (int i = 0; i <= n; i ++) f[i] = cnt[i] = sum[i] = 0;
    cnt[0] = 1;
    for (int i = 1; i <= n; i ++)
    {
        int j = a[i - 1];
        while (j < a[i]) 
        {
            if (j <= i - 1 - x) sub(sum[f[j]], cnt[j]);
            j ++;
        }
        f[i] = f[i - 1];
        cnt[i] = cnt[i - 1];
        if (a[i] <= i - x)
        {
            add(sum[f[i - x]], cnt[i - x]);
            if (f[i] < f[i - x] + 1)
            {
                f[i] = f[i - x] + 1;
                cnt[i] = sum[f[i - x]];
            }
            else
                if (f[i] == f[i - x] + 1) add(cnt[i], sum[f[i - x]]);
        }
    }    
    return {f[n], cnt[n]};
}

void solve(void) 
{
    compress();
    while (q--)
    {
        int x;
        cin >> x;
        auto k = solve(x);
        cout << k.first << ' ' << k.second << '\n';
    }
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
