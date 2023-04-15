#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (auto&& x : b) cin >> x;
    vector<char> dp(n+1, false);
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        if (i-b[i-1]-1 >= 0 && dp[i-b[i-1]-1])
            dp[i] = true;
        if (dp[i-1] && i+b[i-1] <= n)
            dp[i+b[i-1]] = true;
    }
    cout << (dp[n] ? "YES" : "NO") << '\n';
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