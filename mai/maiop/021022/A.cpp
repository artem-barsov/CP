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
    ll a, b;
    cin >> a >> b;
    if (a == 1 && b == 1) {
        cout << 1 << '\n';
        return 0;
    }
    int ans = 0;
    for (ll x = 1; x*x <= b; x++) {
        if (b % x == 0) {
            if (lcm(x, a) == b) ans++;
            if (lcm(b/x, a) == b) ans++;
        }
    }
    cout << ans << '\n';
}