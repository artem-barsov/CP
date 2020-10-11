#include <bits/stdc++.h>

#define WIN 1
#define UNKNOWN 0
#define LOSE -1

using namespace std;

int n, m, k;
vector<vector<int> > g;
vector<int> dp;
vector<int> dist;

void dfs(int idx) {
    if (g[idx].size() == 0) {
        dp[idx] = LOSE;
        dist[idx] = 0;
        return;
    }
    int minDist = INT_MAX;
    for (auto &x : g[idx]) {
        if (dp[x] == UNKNOWN) dfs(x);
        minDist = min(dist[x] + 1, minDist);
        if (minDist <= k) dp[idx] = WIN;
        if (dp[x] == LOSE) dp[idx] = WIN;
    }
    if (dp[idx] == UNKNOWN) dp[idx] = LOSE;
    dist[idx] = minDist;
}

int main(int argc, char const *argv[]) {
    cin >> n >> m >> k;
    g.resize(n);
    dp.assign(n, UNKNOWN);
    dist.assign(n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
    }
    dfs(0);
    std::cout << ((dp[0]==WIN) ? "Dasha" : "Denis") << '\n';
}
