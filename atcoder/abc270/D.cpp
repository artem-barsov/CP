#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    ll n, k;
    cin >> n >> k;
    vector<ll> a(k);
    for (auto&& x : a) cin >> x;
    sort(a.begin(), a.end(), greater<ll>());
    vector<pair<ll, ll>> takes;
    for (ll x : a) {
        ll cnt = n / x;
        if (cnt > 0) {
            takes.emplace_back(x, cnt);
            n -= cnt * x;
        }
    }
    ll ans = 0;
    bool t = true;
    for (auto &&[x, cnt] : takes)
    {
        if (cnt&1) {
            if (t) ans += (cnt+1) / 2 * x;
            else   ans += (cnt-1) / 2 * x;
            t = !t;
        }
        else {
            ans += cnt / 2 * x;
        }
    }
    cout << ans << '\n';
}