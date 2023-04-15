#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n+1);
    for (auto&& x : a) cin >> x;
    b[0] = a[0];
    for (int i = 1; i < n; i++) {
        b[i] = gcd(b[i-1], a[i-1]);
        b[i] = lcm(b[i], a[i]);
        if (a[i-1] != gcd(b[i-1], b[i])) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    cin >> t;
    while (t--) solve();
}