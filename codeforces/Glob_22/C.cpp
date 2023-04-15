#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

enum RES { WIN, LOS, UND };

RES res_all_win(RES r1, RES r2) {
    if (r1 == LOS || r2 == LOS) return LOS;
    if (r1 == WIN || r2 == WIN) return WIN;
    return UND;
}

RES res_any_win(RES r1, RES r2) {
    if (r1 == WIN || r2 == WIN) return WIN;
    if (r1 == LOS || r2 == LOS) return LOS;
    return UND;
}

RES dfs(vector<vector<vector<RES>>>& dp, int e, int o, bool h) {
    if (e < 0 || o < 0)     return UND;
    if (dp[e][o][h] != UND) return dp[e][o][h];
    RES res_ee = dfs(dp, e-2, o  ,  h);
    RES res_eo = dfs(dp, e-1, o-1,  h);
    RES res_oe = dfs(dp, e-1, o-1, !h);
    RES res_oo = dfs(dp, e  , o-2, !h);
    return dp[e][o][h] = res_any_win(res_all_win(res_ee, res_eo),
                                     res_all_win(res_oe, res_oo));
}

void solve() {
    int n;
    cin >> n;
    int even = 0, odd = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a&1) odd++;
        else even++;
    }
    if (even == 0) {
        cout << (((odd-1)/2)&1 ? "Alice" : "Bob") << '\n';
        return;
    }
    if (odd == 0) {
        cout << "Alice" << '\n';
        return;
    }
    vector<vector<vector<RES>>> dp(even+1, vector<vector<RES>>
                                  (odd+1, vector<RES>
                                  (2, UND)));
    dp[0][0][0] = WIN;
    dp[0][0][1] = LOS;
    dp[0][1][0] = LOS;
    dp[0][1][1] = WIN;
    dp[1][0][0] = WIN;
    dp[1][0][1] = LOS;
    RES res = dfs(dp, even, odd, false);
    cout << (res == WIN ? "Alice" : res == LOS ? "Bob" : "Error") << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    cin >> t;
    while (t--) solve();
}