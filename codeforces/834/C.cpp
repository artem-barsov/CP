#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

void solve() {
    ll l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;
    if (a == b) {
        cout << 0 << '\n';
        return;
    }
    queue<pair<ll,ll>> bfs;
    bfs.emplace(a, 0);
    while (!bfs.empty()) {
        auto [t, step] = bfs.front();
        if (step == 3) break;
        bfs.pop();
        if (t < b && t+x <= b && t+x <= r
        ||  b < t && t-x >= b && t-x >= l) {
            cout << step + 1 << '\n';
            return;
        }
        if (t+x <= r) bfs.emplace(r, step+1);
        if (t-x >= l) bfs.emplace(l, step+1);
    }
    cout << -1 << '\n';
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    cin >> t;
    while (t--) solve();
}