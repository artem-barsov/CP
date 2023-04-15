#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

const int MOD = 1'000'000'007;

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n, vector<int>(k+1));
    for (int i = 1; i <= min(k, 15); i++)
        dp[0][i] = 1;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < k; j++) {
            if (i == 0 && j == 0) continue;
            for (int l = 0; l <= 15; l++) {
                if (j + l <= k) {
                    dp[i+1][j+l] = (dp[i+1][j+l] + dp[i][j]) % MOD;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans = (ans + dp[i][k]) % MOD;
    cout << ans << '\n';
}