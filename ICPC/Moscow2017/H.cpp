#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned ll;

ll sum(ll a, ll b) {
    if (a > b) {
        swap(a, b);
    }
    ll n = (b - a) + 1;
    return (a + b) * n / 2;
}

ll hill(ll x1, ll y1, ll x2, ll y2) {
    ll ymax = max(y1, y2) + (x2 - x1 - abs(y1 - y2)) / 2;
    return (x2 - x1 + 1) * ymax - (ymax - y1) * (ymax - y1 + 1) / 2 -
           (ymax - y2) * (ymax - y2 + 1) / 2;
}

ll huill(ll x1, ll y1, ll x2, ll y2) {
    ll ymin = max(0ll, min(y1, y2) - (x2 - x1 - abs(y1 - y2)) / 2);
    return ymin * (x2 - x1 + 1) + (y1 - ymin) * (y1 - ymin + 1) / 2 +
           (y2 - ymin) * (y2 - ymin + 1) / 2;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll T, n, m;
    cin >> T >> n >> m;
    if (m == 0) {
        cout << "Yes" << endl;
        return 0;
    }
    ll low = 0, high = 0;
    ll prev_x = 0, prev_v = 0;
    for (int j = 0; j < m; ++j) {
        ll x, v;
        cin >> x >> v;
        if (prev_x == 0) {
            high = sum(v + x - 1, v) - v;
            low = sum(max(0ll, v - (x - 1)), v) - v;
            prev_x = x;
            prev_v = v;
            continue;
        }
        if (x - prev_x < abs(prev_v - v)) {
            cout << "No" << endl;
            return 0;
        }
        high += hill(prev_x, prev_v, x, v) - v;
        low += huill(prev_x, prev_v, x, v) - v;
        prev_x = x;
        prev_v = v;
    }
    high += sum(prev_v, prev_v + (n - prev_x));
    low += sum(prev_v, max(0ll, prev_v - (n - prev_x)));
    if (T >= low && T <= high) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
