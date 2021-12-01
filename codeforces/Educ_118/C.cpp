#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

ll damage(std::vector<ll>& b, ll k) {
    ll ret = 0;
    for (auto& x : b) {
        ret += min(x, k);
    }
    return ret;
}

void solve() {
    int n;
    ll h;
    std::cin >> n >> h;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    std::vector<ll> b(n);
    for (int i = 0; i < n - 1; i++) {
        b[i] = a[i+1] - a[i];
    }
    b.back() = (ll)(1e18) + 1ll;
    ll l = 0;
    ll r = h + 1;
    while (l + 1 < r) {
        ll m = std::midpoint(l, r);
        if (damage(b, m) < h) l = m;
        else                  r = m;
    }
    std::cout << r << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    std::cin >> t;
    while (t--) solve();
}
