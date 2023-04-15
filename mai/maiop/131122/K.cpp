#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    cin >> n;
    if (!(n&1)) {
        cout << "No" << '\n';
        return 0;
    }
    cout << "Yes" << '\n';
    for (int i = 0; i < n-1; i++) {
        int j = 0;
        for (; j < n/2 && j < n-i-1; j++)
            cout << 1 << ' ';
        for (; j < n-i-1; j++)
            cout << 0 << ' ';
        cout << '\n';
    }
}