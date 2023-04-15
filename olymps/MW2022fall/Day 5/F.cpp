#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        cout << 2*i << ' ';
    for (int i = 0; i < k; i++)
        cout << 2*i+1 << ' ';
    for (int i = 2*k+1; i <= n; i++)
        cout << i << ' ';
    cout << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}