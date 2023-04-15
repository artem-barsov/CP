#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

ll x(ll n) { return n * (n + 1ll) / 2ll; }
ll y(ll n) { return (n&1 ? 1ll : -1ll) * (n+1ll)/2ll; }
ll n_of_y(ll y) {
    if (y > 0) return 2ll*y - 1ll; 
    else return -2ll * y;
}

void solve() {
    ll lx, ly, rx, ry;
    cin >> lx >> ly >> rx >> ry;
    ll l = 1, r = 5'000'000'000ll;
    while (l < r) {
        ll m = midpoint(l, r);
        if (x(m) > lx) r = m;
        else           l = m+1;
    }
    ll l_num = l;

    l = 1, r = 5'000'000'000ll;
    while (l < r) {
        ll m = (l + r + 1) / 2;
        if (x(m) >= rx) r = m-1;
        else            l = m;
    }
    ll r_num = l;
    // cout << l_num << ' ' << r_num << '\n';
    ll up_l = l_num, up_r = r_num;
    ll down_l = l_num, down_r = r_num;
    if (y(l_num) > 0) down_l++;
    else up_l++;
    if (y(r_num) > 0) down_r--;
    else up_r--;

    if (ry > 0) {
        up_r = min(up_r, n_of_y(ry)-2);
    }
    else {
        down_l = max(down_l, n_of_y(ry)+2);
        up_r = -42; up_l = -24;
    }
    if (ly > 0) {
        up_l = max(up_l, n_of_y(ly)+2);
        down_r = -42; down_l = -24;
    }
    else {
        down_r = min(down_r, n_of_y(ly)-2);
    }
    ll ans = 0;
    if (!(up_l&1)) up_l++;
    if (!(up_r&1)) up_r--;
    
    if (down_l&1) down_l++;
    if (down_r&1) down_r--;

    if (up_l <= up_r) ans += (up_r+1)/2-(up_l+1)/2+1;
    if (down_l <= down_r) ans += down_r/2-down_l/2+1;
    // printf("up_l = %d, ", up_l);
    // printf("up_r = %d, ", up_r);
    // printf("down_l = %d, ", down_l);
    // printf("down_r = %d, ", down_r);
    // printf("%d + %d = %d\n", (up_r+1)/2-(up_l+1)/2+1, down_r/2-down_l/2+1, ans);
    cout << ans << '\n';
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