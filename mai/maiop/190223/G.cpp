#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void dfs(vector<vector<int>>& gra, vector<char>& used, int u) {
    used[u] = true;
    for (int v : gra[u])
        if (!used[v]) dfs(gra, used, v);
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gra(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        gra[u].push_back(v);
        gra[v].push_back(u);
    }
    vector<char> used(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i] && gra[i].size() > 0) {
            dfs(gra, used, i);
            ans++;
        }
    }
    cout << ans << '\n';
}