#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using Graph = vector<vector<int>>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll base, n;
    cin >> base >> n;

    vector<ll> a(n);
    for (auto& v : a) {
        cin >> v;
    }

    ll even_sum = 0, odd_sum = 0;
    for (int i = 0; i < n; ++i) {
        if ((n - i) & 1)
            odd_sum += a[i];
        else
            even_sum += a[i];
    }

    if ((odd_sum - even_sum + base + 1) % (base + 1) == 0) {
        cout << "0 0\n";
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        if ((n - i) & 1) {
            ll w = (odd_sum - even_sum + base + 1) % (base + 1);
            if (w <= a[i]) {
                cout << i + 1 << ' ' << a[i] - w << endl;
                return 0;
            }
        } else {
            ll w = (even_sum - odd_sum + base + 1) % (base + 1);
            if (w <= a[i]) {
                cout << i + 1 << ' ' << a[i] - w << endl;
                return 0;
            }
        }
    }

    cout << "-1 -1\n";
    return 0;
}
