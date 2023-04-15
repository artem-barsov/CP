#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n == 4) {
        cout << "2 1 3 4" << '\n';
        return;
    }

    if (((n+1) % 3) == 0) {
        for (int i = 1; i <= n; i++)
            cout << i << ' ';
        cout << '\n';
    }
    else if ((n-2) % 2 == 0) {
        for (int i = n-2; i >= 1; i--)
            cout << i << ' ';
        cout << n-1 << ' ' << n << '\n';
    }
    else {
        cout << n-1 << ' ';
        for (int i = n-3; i >= 1; i--)
            cout << i << ' ';
        cout << n-2 << ' ' << n << '\n';
    }
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    std::cin >> t;
    while (t--) solve();
}