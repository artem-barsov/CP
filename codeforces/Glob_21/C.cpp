#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

using namespace std;
using ll = long long;

void solve() {
    ll n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int> > ca;
    for (ll i = 0; i < n; i++) {
        ll a;
        std::cin >> a;
        ll t = 1;
        while (a % (t*1ll*m) == 0) t *= m;
        if (!ca.empty() && ca.back().first == a / t)
            ca.back().second += t;
        else
            ca.emplace_back(a / t, t);
    }
    int k;
    std::cin >> k;
    std::vector<std::pair<int, int> > cb;
    for (ll i = 0; i < k; i++) {
        ll a;
        std::cin >> a;
        ll t = 1;
        while (a % (t*1ll*m) == 0) t *= m;
        if (!cb.empty() && cb.back().first == a / t)
            cb.back().second += t;
        else
            cb.emplace_back(a / t, t);
    }
    std::cout << (ca == cb ? "YES" : "NO") << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    ll t;
    std::cin >> t;
    while (t--) solve();
}