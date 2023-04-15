#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

ll myceil(ll n, ll d) { return (n+d-1)/d; }

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto&& x : a) cin >> x;
    ll cnt = 0;
    ll bl = 2 * a[0] - 1;
    for (auto&& x : a) {
        if (x > bl) cnt += myceil(x, bl) - 1;
    }
    cout << cnt << '\n';
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