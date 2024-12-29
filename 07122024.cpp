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

string s;
int n, nxt[N];

void Input(void) 
{
    cin >> s;
    n = sz(s);
    s = ' ' + s;
    for (int i = 1; i <= n; i ++)
    {
        nxt[i] = nxt[i - 1];
        if (s[i] == '1') nxt[i] = i;
    }

}

void solve(void) 
{
    ll ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        ll pw = 1, curNum = 0;
        int r = max(1, (i - 25 + 1));
        map<int, bool> dd;
        for (int j = i; j >= r; j --)
        {
            curNum += (s[j] - '0') * pw;
            ans += (curNum == (i - j + 1));
            if (i - nxt[j - 1] >= curNum && curNum > i - r + 1) 
            {
                ans += dd[i - curNum + 1] == 0;
                dd[i - curNum + 1] = 1;
            }
            pw *= 2;
        }
    }
    cout << ans << '\n';
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
