#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n & 1) {
        if (n == 3) {
            cout << -1 << '\n';
            return;
        }
        cout << n-1 << ' ' << n << ' ';
        for (int i = 1; i <= n-2; i++)
            cout << i << ' ';
        cout << '\n';
    }
    else {
        for (int i = n; i >= 1; i--)
            cout << i << ' ';
        cout << '\n';
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