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
vector <int> v;

bool check(int x)
{
    while (x > 0)
    {
        if (x % 10 != 4 && x % 10 != 7) return 0;
        x /= 10;
    }
    return 1;
}

void Input(void) 
{
    cin >> n;
    for (int i = 1; i <= n; i ++) 
    {
        cin >> a[i];
        if (check(a[i])) v.push_back(a[i]);
    }
}

ll choose2(ll x) {return x * (x + 1) / 2;}
int nxt[N];

void solve(void) 
{
    uni(v);
    for (int i = 1; i <= n; i ++)
        if (binary_search(all(v), a[i])) a[i] = lower_bound(all(v), a[i]) - v.begin() + 1;
        else a[i] = 0;
    nxt[n + 1] = n + 1;
    for (int i = n; i >= 1; i --)
    {
        nxt[i] = nxt[i + 1];
        if (a[i]) nxt[i] = i;
    }

    ll res = 0;

    for (int i = 1; i <= n; i ++)   
        if (a[i])
        {
            
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
