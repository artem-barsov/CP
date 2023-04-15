#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned ll;
using Graph = vector<vector<int>>;

const ll mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    map<pair<ll, ll>, ll> d;
    map<ll, ll> by_x, by_y;

    for (int i = 0; i < n; ++i) {
        ll x, y, v;
        cin >> x >> y >> v;

        d[{x, y}] = v;

        by_x[x] += v;
        by_y[y] += v;
    }

    struct V {
        ll x = -1, y = -1;
        ll v = 0;
    };

    vector<V> vs;

    for (auto [x, v] : by_x) {
        vs.push_back({x, -1, v});
    }
    for (auto [y, v] : by_y) {
        vs.push_back({-1, y, v});
    }

    sort(vs.begin(), vs.end(),
         [](const V& l, const V& r) { return l.v > r.v; });

    ll ans = 0;

    n = min<int>(vs.size(), 200);
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            for (int k = j; k < n; ++k) {
                ll cnt = 0;

                cnt += by_y[vs[i].y];
                cnt += by_x[vs[i].x];

                cnt += by_y[vs[j].y];
                cnt += by_x[vs[j].x];

                if (vs[j].y == vs[i].y) {
                    cnt -= by_y[vs[j].y];
                }
                if (vs[j].x == vs[i].x) {
                    cnt -= by_x[vs[j].x];
                }
                cnt -= d[{vs[i].x, vs[j].y}];
                cnt -= d[{vs[j].x, vs[i].y}];

                cnt += by_y[vs[k].y];
                cnt += by_x[vs[k].x];

                if (vs[k].y == vs[i].y || vs[k].y == vs[j].y) {
                    cnt -= by_y[vs[k].y];
                }
                if (vs[k].x == vs[i].x || vs[k].x == vs[j].x) {
                    cnt -= by_x[vs[k].x];
                }

                cnt -= d[{vs[k].x, vs[i].y}];
                cnt -= d[{vs[i].x, vs[k].y}];
                cnt -= d[{vs[j].x, vs[k].y}];
                cnt -= d[{vs[k].x, vs[j].y}];

                ans = max(ans, cnt);
            }
        }
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
#ifdef DEBUG
    freopen("test", "r", stdin);
#endif

    // int t
    // cin >> t;

    // while (t--) {
    solve();
    // }

    return 0;
}
