#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ull = unsigned long long;

void solve() {
    ull a, b, c, d;
    cin >> a >> b >> c >> d;
    ull ab = a*b;
    for (ull x = a+1; x <= c; x++) {
        ull dop = ab / gcd(ab, x);
        ull y = b + dop - (b % dop);
        if (b < y && y <= d) {
            cout << x << ' ' << y << '\n';
            return;
        }
    }
    cout << -1 << ' ' << -1 << '\n';
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