#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

struct DSU {
    vector<int> parent, rank;
    int count;
    DSU(int n)
    : parent(vector<int>(n))
    , rank(vector<int>(n, 0))
    , count(n) {
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
            count--;
        }
    }
};

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    cin >> n;
    DSU dsu(n);
    int cnt2 = 0;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (a[i][j] == 1) {
                for (int k = i; k < j; k++)
                    dsu.join(k, k + 1);
            }
            if (a[i][j] == 2) {
                if (dsu.find(i) == dsu.find(j)) {
                    cout << 0 << '\n';
                    return 0;
                }
                cnt2++;
            }
        }
    }
    cout << "dsu.count = " << dsu.count << '\n';
    cout << "cnt2 = " << cnt2 << '\n';
    cout << (1 << dsu.count) - 2*cnt2 << '\n';
};