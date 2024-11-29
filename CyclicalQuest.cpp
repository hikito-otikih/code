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
 
struct state {
    int len, link;
    map<char, int> next;
    bool isClone;
    int cnt;
};
 
const int MAXLEN = 100000;
state st[MAXLEN * 4];
int dd[MAXLEN * 4];
int Size, last;
 
void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    Size++;
    last = 0;
}
 
void sa_extend(char c) {
    int cur = Size++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = Size++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            st[clone].isClone = 1;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
 
int n;
string s, newS;
 
void Input(void) 
{
    cin >> s;
    n = s.size();
    s = ' ' + s;
}

int repetend(string s) 
{
        int n = sz(s);
        int *nxt = new int[n + 1];
        nxt[0] = -1;
        for (int i = 1; i <= n; i++) 
        {
            int j = nxt[i - 1];
            while (j >= 0 && s[j] != s[i - 1])
                j = nxt[j];
            nxt[i] = j + 1;
        }
        int a = n - nxt[n];
        if (n % a == 0)
            return a;
        return n;
}

void solve(void) 
{
    sa_init();
    for (int i = 1; i <= n; i ++) sa_extend(s[i]);
    for (int i = 1; i < Size; i ++) 
    {
        if (st[i].isClone == 0) st[i].cnt = 1;
        dd[st[i].link] ++;
    }
 
    queue<int> pq;
 
    for (int i = 1; i < Size; i ++) 
    {
        if (dd[i] == 0) pq.push(i);
    }
 
    while (!pq.empty()) 
    {
        int u = pq.front();
        pq.pop();
        if (st[u].link == -1) continue;
        st[st[u].link].cnt += st[u].cnt;
        dd[st[u].link] --;
        if (dd[st[u].link] == 0) pq.push(st[u].link);
    }
    
    int Q;
    cin >> Q;
    while (Q --)
    {
        string S;
        cin >> S;
        int k = repetend(S);
        newS = S;
        for (int i = 1; i < k; i ++) newS += S[i - 1];
        int m = newS.size();
        newS = ' ' + newS;
        int cur = 0, len = 0;
        ll res = 0;
        for (int i = 1; i <= m; i ++)
        {   
            if (len == sz(S)) 
            {
                len --;
                if (len <= st[st[cur].link].len) cur = st[cur].link;
            }
            while (cur != -1 && !st[cur].next.count(newS[i])) cur = st[cur].link, len = st[cur].len;
            if (cur == -1) cur = len = 0;
            else cur = st[cur].next[newS[i]], len ++;
            if (len == sz(S)) res += st[cur].cnt;
        }
        cout << res << '\n';
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