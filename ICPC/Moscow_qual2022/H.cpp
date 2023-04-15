#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

const int MOD = 998244353;

struct DSU {
    vector<int> parent, rank;
    int size;
    DSU(int n)
    : parent(vector<int>(n)), rank(vector<int>(n, 0)), size(n) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }
    void join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b]) ++rank[a];
            size--;
        }
    }
};

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int k;
    cin >> k;
    DSU dsu(k);
    map<pair<int, int>, int> xy;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        xy[{x, y}] = i;
        if (xy.contains({x-1, y})) dsu.join(xy[{x-1, y}], i);
        if (xy.contains({x, y-1})) dsu.join(xy[{x, y-1}], i);
        if (xy.contains({x+1, y})) dsu.join(xy[{x+1, y}], i);
        if (xy.contains({x, y+1})) dsu.join(xy[{x, y+1}], i);
    }
    int ans = 1;
    for (int i = 0; i < dsu.size; i++)
        ans = (ans * 2ull) % MOD;
    cout << ans << '\n';
}