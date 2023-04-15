#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned ll
#define endl '\n'

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> types(n);
    for (auto &it : types) {
        cin >> it;
    }

    vector<vector<int>> dp(n + 1, vector<int>(31));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 31; j++) {
            dp[i][j] = dp[i - 1][j];
        }

        dp[i][types[i - 1]]++;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r, mask;
        cin >> l >> r >> mask;

        int ans = 0;
        for (int j = 0; j < 31; j++) {
            if ((mask >> j) & 1) {
                ans += (dp[r][j] - dp[l][j]) * j;
            }
        }

        cout << ans << endl;
    }
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // signed t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}