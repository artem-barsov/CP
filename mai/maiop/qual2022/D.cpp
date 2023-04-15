#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

void dfs(const vector<ll>& a, vector<vector<ll> >& dp, 
            ll i, ll sum, ll n, ll k) {
    if (dp[i][sum] != -1) return;
    ll rsum = (sum+a[i])%k;
    if (i == n-1) {
        dp[i+1][sum] = (sum == 0);
        dp[i+1][rsum] = (rsum == 0);
    }
    else {
        dfs(a, dp, i + 1, sum,  n, k);
        dfs(a, dp, i + 1, rsum, n, k);
    }
    dp[i][sum] = (dp[i+1][sum] + dp[i+1][rsum]) % MOD;
}


int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    ll n, k;
    cin >> n;
    vector<ll> a(n);
    for (auto&& x : a) cin >> x;
    cin >> k;
    vector<vector<ll> > dp(n+1, vector<ll>(k, -1));
    dfs(a, dp, 0, 0, n, k);
    cout << dp[0][0] << '\n';
}