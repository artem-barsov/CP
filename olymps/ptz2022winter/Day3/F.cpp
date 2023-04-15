#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

using Graph = std::vector<std::set<int> >;

void do_leaf(Graph& gra, std::vector<char>& is_leaf, int u, int from) {
    is_leaf[u] = true;
    printf("made %d to leaf ", u+1);
    for (int v : gra[u]) {
        if (v == from) continue;
        if (gra[v].size() == 2)
            do_leaf(gra, is_leaf, v, u);
    }
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    std::cin >> n;
    Graph gra(n);
    for (int i = 1; i < n; i++) {
        int u;
        std::cin >> u;
        u--;
        gra[u].insert(i);
        gra[i].insert(u);
    }
    std::vector<char> is_leaf(n, false);
    for (int i = 0; i < n; i++) {
        if (gra[i].size() == 1) do_leaf(gra, is_leaf, i, -1);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
printf("\n%d: ", i+1);
        if (is_leaf[i]) continue;
        int leafs = 0;
        for (int v : gra[i]) {
            if (is_leaf[v]) leafs++;
        }
printf("has %d leafs, ", leafs);
        if (leafs >= 2) {
            ans++;
printf("deleted %d, ", i+1);
            for (int v : gra[i]) {
                if (!is_leaf[v] && gra[v].size() == 3) {
                    int c = 0, leaf_idx = -1;
                    if (is_leaf[*gra[v].begin()]) {
                        leaf_idx = 0;
                        c++;
                    }
                    if (is_leaf[*std::next(gra[v].begin(), 1)]) {
                        leaf_idx = 1;
                        c++;
                    }
                    if (is_leaf[*std::next(gra[v].begin(), 2)]) {
                        leaf_idx = 2;
                        c++;
                    }
                    if (c == 1) {
                        gra[v].erase(i);
                        do_leaf(gra, is_leaf, v, leaf_idx);
                    }
                }
                if (!is_leaf[v] && gra[v].size() == 2) {
                    gra[v].erase(i);
                    do_leaf(gra, is_leaf, v, -1);
                }
            }
        }
    }
    printf("\n");
    std::cout << (ans ? ans : 1) << '\n';
}
