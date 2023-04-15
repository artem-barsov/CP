#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using Graph = vector<vector<int> >;

void dfs(Graph& gra, vector<char>& used, int u) {
    used[u] = true;
    for (int v : gra[u])
        if (!used[v]) dfs(gra, used, v);
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    Graph gra(2*n);
    int lvl = -1;
    vector<vector<int> > layers;
    for (int i = 0; i < 2*n; i++)
    {
        bool todec = false;
        if (s[i] == '(') {
            lvl++;
        }
        else {
            todec = true;
        }

        if (layers.size() == lvl) {
            layers.emplace_back();
        }
        layers[lvl].push_back(i);
        if (todec) lvl--;
    }
    for (int i = 0; i < layers.size(); i++)
    {
        for (int j = 0; j < layers[i].size(); j++)
        {
            if (!(j&1)) {
                gra[layers[i][j]].push_back(layers[i][j+1]);
            }
            else if (j+1 < layers[i].size() && layers[i][j+1] - layers[i][j] == 1) {
                gra[layers[i][j]].push_back(layers[i][j+1]);
            }
        }
    }

    vector<char> used(2*n, false);
    int cnt = 0;
    for (int i = 0; i < 2*n; i++)
    {
        if (!used[i]) {
            dfs(gra, used, i);
            cnt++;
        }
    }
    cout << cnt << '\n';
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

    for (size_t bf = 0; bf < (1ull << vars_cnt); bf++) {
        bitset<MAX_CNT> bs(bf);
        for (int i = 0; i < vars_cnt; i++) {
            // bs[i]
        }
    }
}