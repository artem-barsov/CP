#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

vector<int> prime_div;

void solve() {
    int x, y;
    cin >> x >> y;
    if (gcd(x, y) != 1) {
        cout << 0 << '\n';
        return;
    }
    int z = y - x;
    if (z == 1) {
        cout << -1 << '\n';
        return;
    }
    vector<int> factors;
    while (prime_div[z]) {
        factors.push_back(prime_div[z]);
        z /= prime_div[z];
    }
    if (z > 1) factors.push_back(z);
    int ans = factors.empty() ? -1 : INT_MAX;
    for (int factor : factors)
        ans = min(ans, factor - (x % factor));
    cout << ans << '\n';
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n = 1e7;
    prime_div.assign(n+1, 0);
    for (int i = 2; i <= n; i++)
        if (!prime_div[i])
            for (int j = 2; i * j <= n; j++)
                prime_div[i * j] = i;

    int t;
    cin >> t;
    while (t--) solve();
}