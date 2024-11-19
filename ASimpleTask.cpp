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

int n, q;
string s;

void Input(void) 
{
    cin >> n >> q >> s;
    s = ' ' + s;
}

struct seg
{
    vector<vector<int> > st;
    vector<int> lz;
    seg(int _n = 0)
    {
        st.resize(4 * _n + 5, vector<int> (26, 0));
        lz.resize(4 * _n + 5, -1);
    }
    void down(int id, int l, int r)
    {
        if (lz[id] == -1) return;
        for (int i = 0; i < 26; i ++) st[id][i] = (r - l + 1) * (lz[id] == i);
        if (l < r)
        {
            lz[id << 1] = lz[id];
            lz[id << 1 | 1] = lz[id];
        }
        lz[id] = -1;
    }
    void update(int id, int l, int r, int u, int v, int c)
    {
        if (v < l || r < u) return;
        down(id, l, r);
        if (u <= l && r <= v)
        {
            lz[id] = c;
            down(id, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, c);
        update(id << 1 | 1, mid + 1, r, u, v, c);
        for (int i = 0; i < 26; i ++) st[id][i] = st[id << 1][i] + st[id << 1 | 1][i];
    }
    vector<int> get(int id, int l, int r, int u, int v)
    {
        if (v < l || r < u) return vector<int> (26, 0);
        down(id, l, r);
        if (u <= l && r <= v) return st[id];
        int mid = (l + r) >> 1;
        vector<int> x = get(id << 1, l, mid, u, v);
        vector<int> y = get(id << 1 | 1, mid + 1, r, u, v);
        vector<int> res(26, 0);
        for (int i = 0; i < 26; i ++) res[i] = x[i] + y[i];
        return res;
    }
};

void solve(void) 
{
    seg t(n);
    for (int i = 1; i <= n; i ++) t.update(1, 1, n, i, i, s[i] - 'a');
    while (q --)
    {
        int l, r, k;
        cin >> l >> r >> k;
        vector<int> x = t.get(1, 1, n, l, r);
        int cnt = 0;
        if (k == 1)
        {
            for (int i = 0; i < 26; i ++) t.update(1, 1, n, l + cnt, l + cnt + x[i] - 1, i), cnt += x[i];
        }
        else
        {
            for (int i = 25; i >= 0; i --) t.update(1, 1, n, l + cnt, l + cnt + x[i] - 1, i), cnt += x[i];
        }
    }
    for (int i = 1; i <= n; i ++) 
    {
        vector<int> x = t.get(1, 1, n, i, i);
        cout << (char) (find(all(x), 1) - x.begin() + 'a');
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
