#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, greater<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

using ll = long long;
using ull = unsigned ll;
using Graph = vector<vector<int>>;

struct Deque {
    vector<int> d;
    int p = 0;
    void pop() {
        ++p;
    }
    void push(int v) {
        d.push_back(v);
    }
    int front() {
        return d[p];
    }
    bool empty() {
        return d.size() == p;
    }
};

int try_pick(Deque& d) {
    if (d.empty()) return INT_MAX;
    return d.front();
}

struct Positions {
    Deque odd, even;
    Deque& operator[](int i) {
        if (i & 1) {
            return odd;
        }
        return even;
    }
};

void solve() {
    int n;
    cin >> n;
    ordered_set t;
    vector<int> u(n), b(n);
    for (auto& v : u) cin >> v;
    for (auto& v : b) cin >> v;
    map<pair<int, int>, Positions> m;
    for (int i = 0; i < n; ++i) {
        auto p = make_pair(u[i], b[i]);
        m[p][i & 1].push(i);
    }
    for (auto& v : u) cin >> v;
    for (auto& v : b) cin >> v;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        auto p = make_pair(u[i], b[i]), rp = make_pair(b[i], u[i]);
        auto mp = m.find(p), mrp = m.find(rp);
        int best_p = INT_MAX;
        if (mp != m.end()) best_p = try_pick(mp->second[i & 1]);
        int best_rp = INT_MAX;
        if (mrp != m.end()) best_rp = try_pick(mrp->second[!(i & 1)]);
        if (best_p == INT_MAX && best_rp == INT_MAX) {
            cout << -1 << '\n';
            return;
        }
        if (best_p < best_rp) {
            t.insert(best_p);
            mp->second[best_p & 1].pop();
            ans += abs(best_p + (int)t.order_of_key(best_p) - i);
        } else {
            t.insert(best_rp);
            mrp->second[best_rp & 1].pop();
            ans += abs(best_rp + (int)t.order_of_key(best_rp) - i);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
