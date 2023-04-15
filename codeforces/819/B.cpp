#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    if (m < n) {
        cout << "NO" << '\n';
        return;
    }
    
    if (n&1) {
        cout << "YES" << '\n';
        for (int i = 0; i < n-1; i++)
            cout << 1 << ' ';
        cout << m - n + 1 << '\n';
    }
    else if (!(n&1) && !(m&1)) {
        cout << "YES" << '\n';
        for (int i = 0; i < n-2; i++)
            cout << 1 << ' ';
        cout << (m-n+2)/2 << ' ' << (m-n+2)/2 << '\n';
    }
    else {
        cout << "NO" << '\n';
        return;
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