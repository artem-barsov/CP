#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    cin >> n;
    ll ans = 0;
    for (size_t bf = 0; bf < (1ull << n); bf++) {
        bitset<20> bs(bf); // A - 0, BC - 1
        bool ok = true;
        for (int i = 0; i < n-1; i++) {
            if (!bs[i] && !bs[i+1]) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        ans += (1ll << bs.count());
    }
    cout << ans << '\n';
}