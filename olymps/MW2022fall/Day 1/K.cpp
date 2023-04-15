#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;


int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    ll n, ax, bx, cx, ay, by, cy;
    cin >> n >> ax >> bx >> cx >> ay >> by >> cy;
    ll x = 0, y = 0;
    set<pair<ll, ll>> p;
    x = (x * ax + bx) % cx;
    y = (y * ay + by) % cy;
    p.insert({x, y});
    x = (x * ax + bx) % cx;
    y = (y * ay + by) % cy;
    ll d2 = (x-p.begin()->first)*(x-p.begin()->first) + (y-p.begin()->second)*(y-p.begin()->second);
    double d = sqrt(d2);
    ll ans = d2;
    p.insert({x, y});
    for (int i = 0; i < n - 2; i++) {
        x = (x * ax + bx) % cx;
        y = (y * ay + by) % cy;
        auto l = p.lower_bound({x - d, -1});
        auto r = p.upper_bound({x + d, 1e7});
        if (l != r) {
            for (auto it = l; it != r; it++) {
                ll new_d2 = (x-it->first)*(x-it->first)+(y-it->second)*(y-it->second);
                if (d2 > new_d2) {
                    d2 = new_d2;
                    d = sqrt(d2);
                }
            }
        }
        ans += d2;
        p.insert({x, y});
    }
    cout << ans << '\n';
}