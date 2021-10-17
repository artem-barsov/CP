#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned ll;

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int k;
    cin >> k;
    ull x = 0, pow = 1;
    for (int j = 0; j < k; ++j) {
        ll b;
        cin >> b;
        ull mask = (1u << 7) - 1;
        ull sig = (b >> 7u) & 1u;
        x += (b & mask) * pow;
        if (sig) {
            pow <<= 7u;
        } else {
            ll t;
            if (x & 1) {
                t = x >> 1;
                t = -t - 1;
            } else {
                t = x >> 1;
            }
            cout << t << '\n';
            x = 0;
            pow = 1;
        }
    }
}
