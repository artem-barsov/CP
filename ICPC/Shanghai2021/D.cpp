#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned ll;
using Graph = vector<vector<int>>;

#define NO_SOLUTION      \
    do {                 \
        cout << "0 0\n"; \
        return;          \
    } while (0);

void solve() {
    ll p, q;
    cin >> p >> q;
    ll g = gcd(p, q);
    p /= g;
    q /= g;
    ll d = p * p - 4 * q * q;
    if (d < 0) {
        NO_SOLUTION;
    }
    if (d == 0) {
        if (p & 1) NO_SOLUTION;
        ll z = p / 2;
        ll a = sqrt(z);
        if (a * a != z) NO_SOLUTION;
        ll b = q / a;
        if (a * b != q) NO_SOLUTION;
        cout << a << ' ' << b << '\n';
        return;
    }
    ll sd = sqrt(d);
    if (sd * sd != d) {
        NO_SOLUTION;
    }
    if ((p + sd) & 1) NO_SOLUTION;
    ll z = (p + sd) / 2;
    ll a = sqrt(z);
    if (a * a != z) {
        z = (p - sd) / 2;
        a = sqrt(z);
    }
    if (a * a != z) NO_SOLUTION;
    ll b = q / a;
    if (a * b != q) NO_SOLUTION;
    if (a <= 0 || b <= 0) b = 1 / 0;
    cout << a << ' ' << b << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
