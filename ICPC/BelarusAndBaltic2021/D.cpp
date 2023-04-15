#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using Graph = vector<vector<int>>;

void solve() {
    int n;
    cin >> n;

    vector<int> l(n), r(n);
    for (int i = 0; i < n - 1; ++i) {
        cin >> l[i] >> r[i];
        --l[i], --r[i];
    }

    vector<int> acc(n + 1), dp(n);

    acc[0] = 1;
    acc[1] = -1;

    int v = 0;
    for (int u = 0; u < n; ++u) {
        v += acc[u];
        dp[u] = v;

        acc[l[u]] += dp[u];
        acc[r[u] + 1] -= dp[u];
    }

    // for (auto v : dp) {
    //     cout << v << ' ';
    // }

    int ans = count(dp.begin() + 1, dp.end() - 1, dp[n - 1]);

    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
