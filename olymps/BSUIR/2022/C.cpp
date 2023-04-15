#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll calc (ll a, ll b, ll x) {
    // cout << x << ' ';
    if (x > a) {
        return x - b + 1;
    } else {
        return calc(a, b, calc(a, b, x + b));
    }
}

void solve() {
    ll a, b, x;
    cin >> a >> b >> x;

    if (x > a) {
        cout << x - b + 1 << endl;
    } else {
        cout << a - b + 2 << endl;
    }
    // cout << "ans = " << calc(a, b, x) << endl;
    // cout << "a - b + 2 = " << a - b + 2 << endl << endl;

}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll t;
    cin >> t;
    while (t--)
        solve();


    return 0;
}
