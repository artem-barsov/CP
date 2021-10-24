#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &g, set<int> &used, int i, int t, vector<int> &teams) {
    if (used.count(i) != 0) {return;}
    used.insert(i);
    teams[i] = t;
    for (auto &it : g[i]) {
        dfs(g, used, it, t, teams);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a('z' - 'a' + 1, 0);
    vector<int> b('z' - 'a' + 1, 0);
    vector<vector<int> > g(26);
    vector<int> teams(26, -1);
    int j;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int f = s[0] - 'a';
        int l = s[s.size() - 1] - 'a';
        j = f;
        g[f].push_back(l);
        g[l].push_back(f);
        a[f]++;
        b[l]++;
    }
    set<int> st;
    dfs(g, st, j, 1, teams);
    for (int i = 0; i < ('z' - 'a' + 1); i++) {
        if (a[i] != b[i] || (teams[i] == -1 && a[i] != 0)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
}
