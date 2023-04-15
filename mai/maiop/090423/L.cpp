#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

const ll mod = 999983;

void solve() {
    int n, k, l;
    cin >> n >> k >> l;

    set<int> ss;
    for (int i = 0; i < l; ++i) {
        int v;
        cin >> v;
        ss.insert(v);
    }

    if (ss.size() > k) {
        cout << 0 << '\n';
        return;
    }

    vector<ll> c(l + 1), s(ss.begin(), ss.end());

    c[0] = 1;
    for (int i = 0; i < s.size(); ++i) {
        // c * (x - s[i])
        vector<ll> prod(l + 1);

        for (int j = 0; j < prod.size(); ++j) {
            prod[j] = (c[j] * (-s[i]) + mod * mod) % mod;
            if (j > 0) prod[j] = (prod[j] + c[j - 1] + mod) % mod;
        }
        swap(c, prod);
    }

    c[c.size() - 1] = 1;
    // if (c[c.size() - 1] == 0) c[c.size() - 1] = mod;

    cout << n << '\n';
    for (int i = 1; i <= n; ++i) {
        cout << c.size() - 1 << ' ';
        for (int j = 0; j < c.size(); ++j) {
            cout << i * c[c.size() - 1 - j] << " \n"[j == c.size() - 1];
        }
    }

    // for (auto v : c) cout << v << ' ';
    // cout << '\n';
}

auto main() -> signed {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
#ifdef DEBUG
    freopen("test", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}