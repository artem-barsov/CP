#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;
using graph = std::vector<std::vector<int> >;

void dfs(int u, graph& gr, std::vector<bool>& used, std::vector<int>& topSort) {
    used[u] = true;
    for (int v : gr[u]) {
        if (!used[v]) dfs(v, gr, used, topSort);
    }
    topSort.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    graph gr(n), rev_gr(n);
    vector<bool> used(n, false);
    vector<int> dp(n), parent(n), topSort;
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        gr[u].push_back(v);
        rev_gr[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) dfs(i, gr, used, topSort);
    }
    reverse(topSort.begin(), topSort.end());
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        parent[i] = i;
    }
    for (int i = topSort.size() - 1; i >= 0; i--) {
        for (int j = 0; j < rev_gr[topSort[i]].size(); j++) {
            if (dp[rev_gr[topSort[i]][j]] < dp[topSort[i]] + 1) {
                dp[rev_gr[topSort[i]][j]] = dp[topSort[i]] + 1;
                parent[rev_gr[topSort[i]][j]] = topSort[i];
            }
        }
    }
    int max = -1, idx = -1;
    for (int i = 0; i < n; i++) {
        if (dp[i] > max) {
            max = dp[i];
            idx = i;
        }
    }
    std::cout << max << '\n';
    while (idx != parent[idx]) {
        std::cout << idx + 1 << ' ';
        idx = parent[idx];
    }
    std::cout << parent[idx] + 1 << '\n';
}
