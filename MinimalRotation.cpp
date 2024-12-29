#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

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

struct Node
{
    int len, link;
    int next[26];
    void assignNext(const Node &other) 
    {
        for (int i = 0; i < 26; i ++) next[i] = other.next[i];
    }
};

const int MAXLEN = 1000000;
Node st[MAXLEN * 4];
int Size = 0, last = 0;

void sa_init() 
{
    st[0].len = 0;
    st[0].link = -1;
    Size ++;
}

void sa_extend(char c)
{
    int cur = Size ++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next[c - 'a']) 
    {
        st[p].next[c - 'a'] = cur;
        p = st[p].link;
    }
    if (p == -1) st[cur].link = 0;
    else
    {
        int q = st[p].next[c - 'a'];
        if (st[q].len == st[q].len + 1)
        {
            st[cur].link = q;
        }
        else
        {
            int clone = Size ++;
            st[clone].len = st[p].len + 1;
            st[clone].assignNext(st[q]);
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c - 'a'] == q) 
            {
                st[p].next[c - 'a'] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

string s;

void Input(void) 
{
    cin >> s;
}

void solve(void) 
{
    sa_init();
    int n = sz(s);
    s = ' ' + s + s;
    for (int i = 1; i < sz(s); i ++) sa_extend(s[i]);
    int cur = 0;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 0; j < 26; j ++)
        {
            if (st[cur].next[j] != 0)
            {
                cout << char(j + 'a');
                cur = st[cur].next[j];
                break;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task ".INP", "r"))
        freopen(task ".txt", "r", stdin),
            freopen(task ".OUT", "w", stdout);
    int test = 1;
//    cin >> test;
    while (test --) {
        Input();
        solve();
    }
    return 0;
}
