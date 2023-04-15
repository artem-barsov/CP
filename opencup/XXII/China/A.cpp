#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using Graph = vector<vector<int> >;

int dfs(Graph& gra, vector<int>& deps, 
        vector<int>& subsize, int u, int dep) {
    int sum = 1;
    deps[u] = dep;
    for (int v : gra[u])
        sum += dfs(gra, deps, subsize, v, dep + 1);
    return subsize[u] = sum;
}

void solve() {
    int n;
    cin >> n;
    Graph gra(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        gra[u].push_back(v);
    }
    vector<int> deps(n), subsize(n);
    dfs(gra, deps, subsize, 0, 1);
    for (int i = 0; i < n; i++)
    {
        cout << deps[i] << ' ' << n - subsize[i] + 1 << '\n';
    }
    
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    std::cin >> t;
    while (t--) solve();
}