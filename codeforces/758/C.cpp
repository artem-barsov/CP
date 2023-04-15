#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void dfs(vector<vector<int>>& g, vector<char>& used, int u) {
    used[u] = true;
    for (int v : g[u])
        if (!used[v]) dfs(g, used, v);
}

void solve() {
    int n;
    cin >> n;    
    vector<pair<int,int>> a(n), b(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = {x, i};
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b[i] = {x, i};
    }
    int maxa = distance(a.begin(), max_element(a.begin(), a.end()));
    int maxb = distance(b.begin(), max_element(b.begin(), b.end()));
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; i++) {
        g[a[i].second].push_back(a[i+1].second);
        g[b[i].second].push_back(b[i+1].second);
    }
    vector<char> used(n);
    dfs(g, used, maxa);
    dfs(g, used, maxb);
    for (bool f : used)
        cout << "01"[f];
    cout << '\n';
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    cin >> t;
    while (t--) solve();
}