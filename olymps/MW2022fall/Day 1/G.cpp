#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    ll n_2 = n / 2;
    ll maxlcm = 0;
    for (ll a = max(1ll, n_2 - 5'000); a <= n_2; a++) {
        maxlcm = max(maxlcm, lcm(a, n - a));
    }
    cout << maxlcm << '\n';
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