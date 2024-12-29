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

int n, x, y;
struct Point
{
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    ll dist(Point p)
    {
        return 1LL * (x - p.x) * (x - p.x) + 1LL * (y - p.y) * (y - p.y);
    }
    double realDist(Point p)
    {
        return sqrt(dist(p));
    }
};

Point p, a[N];

ll ccw(Point a, Point b, Point c)
{
    return 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (b.y - a.y) * (c.x - a.x);
}

void Input(void) 
{
    cin >> n;
    cin >> x >> y;
    p = Point(x, y);
    for (int i = 1; i <= n; i ++)
    {
        cin >> x >> y;
        a[i] = Point(x, y);
    }
}

void solve(void) 
{
    double mx = p.realDist(a[1]), mn = p.realDist(a[1]);
    for (int i = 2; i <= n; i ++)
    {
        double d = p.realDist(a[i]);
        maximize(mx, d);
        minimize(mn, d);
    }
    a[0] = a[n];
    for (int i = 1; i <= n; i ++)
    {
        ///
        ll AB = a[i].dist(a[i - 1]);
        ll AP = p.dist(a[i]);
        ll BP = p.dist(a[i - 1]);
        // 
        if ((AB > AP + BP) || (AP > AB + BP) || (BP > AB + AP)) 
        {
            if (AB > AP + BP)
            {
                ll S = abs(ccw(a[i], a[i - 1], p));
                double d = 1.0 * S / sqrt(AB);
                maximize(mx, d);   
                minimize(mn, d);
            }
        }
        else
        {
            ll S = abs(ccw(a[i], a[i - 1], p));
            double d = 1.0 * S / sqrt(AB);
            maximize(mx, d);   
            minimize(mn, d);
        }
        //
    }
    cout << setprecision(10) << fixed << (mx * mx - mn * mn) * 3.14159265359;
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
