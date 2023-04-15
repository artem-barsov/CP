#include <bits/stdc++.h>

using namespace std;
using ll = long long;
// using ull = unsigned ll;
using Graph = vector<vector<int>>;

const int MNOGO = INT_MAX / 10;

auto main() -> signed {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
#ifdef DEBUG
    freopen("test", "r", stdin);
#endif

    freopen("k.in", "r", stdin);
    freopen("k.out", "w", stdout);

    int N, K, S;
    cin >> N >> K >> S;

    vector<int> q(N);
    for (auto& v : q) cin >> v;

    const int MAXW = 150 * 150;
    vector<vector<vector<int>>> dp(
        2, vector<vector<int>>(151, vector<int>(MAXW + 1, MNOGO)));

    dp[0][0][0] = 0;

    for (int n = 0; n < N; ++n) {
        for (int p = 0; p <= n; ++p) {
            for (int w = 0; w <= MAXW; ++w) {
                if (dp[0][p][w] == MNOGO) continue;
                dp[1][p][w] = min(dp[1][p][w], dp[0][p][w]);

                ll c = n - p;
                if (w + c <= MAXW)
                    dp[1][p + 1][w + c] =
                        min(dp[1][p + 1][w + c], dp[0][p][w] + q[n]);
            }
        }

        swap(dp[0], dp[1]);
    }

    int ans = MNOGO;
    for (int w = 0; w <= min(MAXW, S); ++w) ans = min(ans, dp[0][K][w]);

    cout << ans << '\n';

    return 0;
}