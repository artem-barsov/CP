#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int y;
bool found = false;

void dfs(vector<vector<int>>& gra, vector<int>& path, int u, int from) {
    path.push_back(u);
    if (u == y) {
        found = true;
        return;
    }
    for (int v : gra[u]) {
        if (v != from && !found) dfs(gra, path, v, u);
    }
    if (!found) path.pop_back();
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, x;
    cin >> n >> x >> y;
    x--; y--;
    vector<vector<int> > gra(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        gra[u].push_back(v);
        gra[v].push_back(u);
    }
    vector<int> path;
    dfs(gra, path, x, -1);
    for (auto &&u : path)
        cout << u + 1 << ' ';
    cout << '\n';
}