#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;
    ll nn = n;
    int c10 = 0;
    while (n % 10 == 0) {
        c10++;
        n /= 10;
    }
    int c2 = 0;
    while (n % 2 == 0) {
        c2++;
        n /= 2;
    }
    int c5 = 0;
    while (n % 5 == 0) {
        c5++;
        n /= 5;
    }
    ll k = 1;
    if (c2)
        for (int i = 0; i < c2 && 5*k <= m; i++)
            k *= 5;
    if (c5)
        for (int i = 0; i < c5 && 2*k <= m; i++)
            k *= 2;
    while (10 * k <= m) k *= 10;
    cout << nn * k * (m / k) << '\n';
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    cin >> t;
    while (t--) solve();
}