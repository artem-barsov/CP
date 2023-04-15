#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto&& x : a) cin >> x;
    int q;
    cin >> q;
    while (q--) {
        char op;
        cin >> op;
        if (op == '+') {
            int p, r;
            cin >> p >> r;
            p--;
            a[p] += r;
            cout << a[p] << '\n';
        }
        if (op == '-') {
            int p, r;
            cin >> p >> r;
            p--;
            if (a[p] - r >= 0)
                a[p] -= r;
            cout << a[p] << '\n';
        }
        if (op == 's') {
            int l, r, mod;
            cin >> l >> r >> mod;
            l--; r--;
            ll sum = 0;
            for (int i = l; i <= r; i++) {
                if (a[i] % m == mod)
                    sum += a[i];
            }
            cout << sum << '\n';
        }
    }
}