#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ull = unsigned long long;

void solve() {
    int n, q;
    cin >> n >> q;
    int odd = 0, even = 0;
    ull sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a&1) odd++;
        else even++;
        sum += a;
    }
    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t == 0) {
            sum += even *1ull* x;
            if (x&1) {
                odd += even;
                even = 0;
            }
        }
        else if (t == 1) {
            sum += odd *1ull* x;
            if (x&1) {
                even += odd;
                odd = 0;
            }
        }
        cout << sum << '\n';
    }
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