#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

vector<int> nxt;
vector<int> dist_to_cycle;
vector<int> used;
vector<int> in_cycle_of_num;
vector<vector<int>> cycles;
vector<int> to_vertex;
vector<int> idx_in_cycle;

int cur_cycle_num = 0;

pair<int, bool> dfs_find_cycles(int u) {
    used[u] = cur_cycle_num;
    if (used[nxt[u]] != -1) {
        if (in_cycle_of_num[nxt[u]] == -1) {
            in_cycle_of_num[u] = cur_cycle_num;
            cur_cycle_num++;
            cycles.emplace_back();
            cycles.back().push_back(u);
            idx_in_cycle[u] = cycles.back().size() - 1;
            to_vertex[u] = u;
            dist_to_cycle[u] = 0;
            return {nxt[u], u != nxt[u]};
        }
        else {
            in_cycle_of_num[u] = in_cycle_of_num[nxt[u]];
            to_vertex[u] = to_vertex[nxt[u]];
            dist_to_cycle[u] = dist_to_cycle[nxt[u]] + 1;
            return {nxt[u], false};
        }
    }
    auto [end_of_cycle, is_cycle] = dfs_find_cycles(nxt[u]);
    in_cycle_of_num[u] = in_cycle_of_num[nxt[u]];
    if (is_cycle) {
        cycles.back().push_back(u);
        idx_in_cycle[u] = cycles.back().size() - 1;
        to_vertex[u] = u;
        dist_to_cycle[u] = 0;
        if (end_of_cycle == u)
            return {end_of_cycle, false};
        return {end_of_cycle, true};
    }
    else {
        to_vertex[u] = end_of_cycle;
        dist_to_cycle[u] = dist_to_cycle[nxt[u]] + 1;
        return {end_of_cycle, false};
    }
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, q;
    cin >> n >> q;
    nxt.resize(n);
    vector<char> is_leaf(n, true);
    for (int i = 0; i < n; i++) {
        cin >> nxt[i];
        nxt[i]--;
        is_leaf[nxt[i]] = false;
    }
    dist_to_cycle.assign(n, 0);
    used.assign(n, -1);
    in_cycle_of_num.assign(n, -1);
    to_vertex.assign(n, -1);
    idx_in_cycle.assign(n, -1);
    for (int i = 0; i < n; i++) {
        if (used[i] == -1)
            dfs_find_cycles(i);
    }
    // for (auto &&cycle : cycles) {
    //     cout << "cycle : ";
    //     for (auto &&x : cycle)
    //         cout << x+1 << ' ';
    //     cout << '\n';
    // }
    // for (int i = 0; i < n; i++) {
    //     cout << i+1 << " : " << '\n';
    //     cout << "    in_cycle_of_num " << in_cycle_of_num[i] << '\n';
    //     cout << "    to_vertex " << to_vertex[i]+1 << '\n';
    //     cout << "    dist_to_cycle " << dist_to_cycle[i] << '\n';
    // }
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (in_cycle_of_num[a] != in_cycle_of_num[b]) {
            cout << "NO" << '\n';
        }
        else {
            if (dist_to_cycle[a] > dist_to_cycle[b])
                swap(a, b);
            
            int idx = idx_in_cycle[to_vertex[a]] - (dist_to_cycle[b] - dist_to_cycle[a]) % cycles[in_cycle_of_num[a]].size();
            if (idx < 0) idx += cycles[in_cycle_of_num[a]].size();
            cout << (cycles[in_cycle_of_num[a]][idx] == to_vertex[b] ? "YES" : "NO") << '\n';
        }
    }
}