#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    ull n;
    while (cin >> n) {
        ll l = -1, r = 1ll<<32;
        while (l + 1 < r) {
            ull m = midpoint(l, r);
            if (m*m > n) r = m;
            else         l = m;
        }
        cout << r-1 << '\n';
    }
}