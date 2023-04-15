#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;
using ull = unsigned long long;

ull a(ull i) { return ((i+1)/3)*((i/3) + 1) +  ((i+2)/3); }

ull bs_l(ull x) {
    ull l = 0, r = 2999999999;
    while (l + 1 < r) {
        ull m = midpoint(l, r);
        if (a(m) >= x) r = m;
        else           l = m;
    }
    return r;
}

ull bs_r(ull x) {
    ull l = 0, r = 2999999999;
    while (l + 1 < r) {
        ull m = midpoint(l, r);
        if (a(m) > x) r = m;
        else          l = m;
    }
    return r-1;
}

void solve() {
    ull ls, rs;
    cin >> ls >> rs;
    ull cnt_l = bs_l(ls);
    ull cnt_r = bs_r(rs);
    cout << cnt_r - cnt_l + 1 << '\n';
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