#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using Graph = vector<vector<int>>;

int dfs(Graph& g, int u) {
    int cnt = 0;
    for (int v : g[u]) cnt += dfs(g, v);
    return cnt + 1;
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    string s;
    cin >> n >> s;
    Graph g(1 << n), rev_g(1 << n);
    for (int i = 1; i <= n; i++) {
        if (s[i-1] == '1') {
            for (int j = 0, k = 0; j < (1<<(n-i)); j++, k += (1<<(i))) {
                g[k].push_back(k + (1<<(i-1)));
                rev_g[k + (1<<(i-1))].push_back(k);
            }
        }
        else {
            for (int j = 0, k = 0; j < (1<<(n-i)); j++, k += (1<<(i))) {
                g[k + (1<<(i-1))].push_back(k);
                rev_g[k].push_back(k + (1<<(i-1)));
            }
        }
    }
    int l = dfs(g, 0);
    int r = (1<<n) - dfs(rev_g, 0) + 1;
    for (int i = l; i <= r; i++) cout << i << ' ';
    cout << '\n';
}