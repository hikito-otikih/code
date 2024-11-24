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

struct Point
{
    int x, y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    void read(void) {cin >> x >> y;}
};

Point a[N], b[N];
int n, m;

void Input(void) 
{
    cin >> n;
    for (int i = 1; i <= n; i ++) a[i].read();
    cin >> m;
    for (int i = 1; i <= m; i ++) b[i].read();
}

long long ccw(Point A, Point B, Point C)
{
    return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (B.y - A.y) * (C.x - A.x);
}

int cnt[N];

void solve(void) 
{
    sort(b + 1, b + m + 1, [&](Point A, Point B) {
        return A.x < B.x || (A.x == B.x && A.y < B.y);
    });
    a[n + 1] = a[1];
    for (int i = 1; i <= n; i ++)
    {
        pair<Point, Point> line(a[i], a[i + 1]);
        if (line.F.x > line.S.x) swap(line.F, line.S);
        int l = 1, r = m, res = -1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (b[mid].x < line.F.x) l = mid + 1;
            else res = mid, r = mid - 1;
        }
        if (res == -1) continue;
        for (int j = res; j <= m; j ++)
        {
            if (b[j].x > line.S.x) break;
            long long val = ccw(line.F, line.S, b[j]);
            if (val == 0)
            {
                int s = min(line.F.y, line.S.y), e = max(line.F.y, line.S.y);
                if (s <= b[j].y && b[j].y <= e)
                {
                    cout << "NO\n";
                    return;
                }
                continue;
            }
            if (line.F.x <= b[j].x && b[j].x < line.S.x && val > 0) cnt[j] ++;
        }
    }
    for (int i = 1; i <= m; i ++)
        if (cnt[i] & 1) ;
        else
        {
            cout << "NO\n";
            return;
        }
    cout << "YES\n"; 
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
