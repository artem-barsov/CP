#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using Graph = vector<vector<int> >;

int ans;
vector<int> used, red, need;
Graph gra;

void dfs(int u) {
    for (int v : gra[u]) {
        dfs(v);
        red[u] += red[v];
    }
    if (need[u]) {
        if (red[u] == 0) ans++;
        red[u]++;
    }
    else if (red[u]) {
        if (red[u] == 1) ans++;
    }
}

void solve() {
    int n;
    cin >> n;
    gra.assign(n+1, vector<int>{});
    used.assign(n+1, 0);
    red.assign(n+1, 0);
    need.assign(n+1, 0);
    ans = 0;
    string need_str;
    cin >> need_str;
    for (int i = 1; i <= n; ++i) {
        need[i] = need_str[i-1] - '0';
    }
    vector<char> used_gr(n+1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!used_gr[i] && i + (i & (-i)) <= n)
            gra[i + (i & (-i))].push_back(i);
            // gra[i].push_back(i + (i & (-i)));
        used_gr[i] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!used[i]) dfs(i);
    }
    cout << ans << '\n';
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