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

int n, m, a[N];

void Input(void) 
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> a[i];
}

struct seg
{
    vector <int> st;
    vector <ll> sum;
    seg(int _n = 0)
    {
        st.resize(4 * _n + 5, 0);
        sum.resize(4 * _n + 5, 0);
    }
    void update(int id, int l, int r, int i, int val)
    {
        if (i < l || i > r) return;
        if (l == r)
        {
            st[id] = i;
            sum[id] = val;
            return;
        }
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, i, val);
        update(id << 1 | 1, mid + 1, r, i, val);
        st[id] = a[st[id << 1]] > a[st[id << 1 | 1]] ? st[id << 1] : st[id << 1 | 1];
        sum[id] = sum[id << 1] + sum[id << 1 | 1];
    }
    int get(int id, int l, int r, int u, int v)
    {
        if (v < l || r < u) return 0;
        if (u <= l && r <= v) return st[id];
        int mid = (l + r) >> 1;
        int x = get(id << 1, l, mid, u, v);
        int y = get(id << 1 | 1, mid + 1, r, u, v);
        return a[x] > a[y] ? x : y;
    }
    ll getSum(int id, int l, int r, int u, int v)
    {
        if (v < l || r < u) return 0;
        if (u <= l && r <= v) return sum[id];
        int mid = (l + r) >> 1;
        ll x = getSum(id << 1, l, mid, u, v);
        ll y = getSum(id << 1 | 1, mid + 1, r, u, v);
        return x + y;
    }
    void update(int i, int val) {update(1, 1, n, i, val);}
    int get(int u, int v) {return get(1, 1, n, u, v);}
    ll getSum(int u, int v) {return getSum(1, 1, n, u, v);}
};

void solve(void) 
{   
    seg t(n);
    for (int i = 1; i <= n; i ++) t.update(i, a[i]);
    for (int i = 1; i <= m; i ++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << t.getSum(l, r) << '\n';
        }
        else
            if (type == 2)
            {
                int l, r, x;
                cin >> l >> r >> x;
                while (true)
                {
                    int k = t.get(l, r);
                    if (a[k] < x) break;
                    a[k] = a[k] % x;
                    t.update(k, a[k]);
                }
            }
            else
            {
                int i, x;
                cin >> i >> x;
                a[i] = x;
                t.update(i, x);
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
