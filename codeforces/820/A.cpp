#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a - 1 < abs(b-c) + c-1) 
        cout << 1 << '\n';
    else if (a - 1 > abs(b-c) + c-1) 
        cout << 2 << '\n';
    else cout << 3 << '\n';
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