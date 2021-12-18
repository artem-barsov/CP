#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned ll;
using Graph = vector<vector<int>>;

ll mod = 998244353;

ll modPow(ll a, ll n) {
    ll result = 1;
    while (n != 0) {
        if (n % 2 == 1) {
            result = result * a % mod;
        }
        a = a * a % mod;
        n /= 2;
    }
    return result;
}

ll modInverse(ll a) {
    return modPow(a, mod - 2);
}

ll C(ll n) {
    return (n * (n - 1) % mod) * modInverse(2) % mod;
}

vector<ll> memo(1'000'001, -1);

ll fac(ll n) {
    if (n == 0) {
        return 1;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    return memo[n] = (fac(n - 1) * n) % mod;
}

ll fuck(ll n) {
    return (fac(n) * modInverse(modPow(2, n / 2)) % mod) *
           modInverse(fac(n / 2)) % mod;
}

int dfs(Graph& g, vector<ll>& dp, int u, int p) {
    dp[u] = 1;
    if (g[u].size() == 1 && g[u][0] == p) {
        return 1;
    }
    ll can_use = 0;
    for (auto v : g[u]) {
        if (v == p) continue;
        can_use += dfs(g, dp, v, u);
    }
    if (can_use & 1) {
        ll n = can_use + 1;
        dp[u] = fuck(n);
        return 0;
    } else {
        ll n = can_use;
        dp[u] = fuck(n);
        return 1;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    Graph g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> dp(n, -1);
    dfs(g, dp, 0, -1);
    ll ans = 1;
    for (auto v : dp) {
        ans = (v * ans) % mod;
    }
    cout << ans << '\n';
}
