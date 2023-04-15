#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ull = unsigned long long;

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    ull x, k;
    cin >> x >> k;
    ull m = 10;
    for (int i = 0; i < k; i++, m*=10) {
        if (x % m >= 5 * m / 10)
            x = x - (x % m) + m;
        else
            x = x - (x % m);
    }
    cout << x << '\n';
}