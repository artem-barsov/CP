#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned ll;
using Graph = vector<vector<int>>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<set<int>> a(n);
    vector<int> ans(n, 0);
    vector<bool> equal(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            a[i].insert(x);
        }
    }
    for (int i = 0; i < 2 * n + 1; i++) {
        bool ok = true;
        for (auto v : a[(i - 1 + n) % n]) {
            if (!a[i % n ].count(v)) {
                ok = false;
                ans[(i - 1 + n) % n] = v;
            }
        }
        equal[(i - 1 + n) % n] = ok;
        if (ok)
            a[i % n] = a[(i - 1 + n) % n];
    }
    int cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (equal[i]) {
            ++cnt;
            ans[i] = ans[(i + 1) % n];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (equal[i]) {
            ans[i] = ans[(i + 1) % n];
        }
    }
    if (cnt == equal.size()) {
        for (auto i = 0; i < n; ++i) {
            cout << *a[0].begin() << ' ';
        }
        cout << '\n';
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
