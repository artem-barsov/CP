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
    double a, b;
    cin >> a >> b;
    if (a == 0 && b == 0 || a == 1 && b == 1)
        cout << 0 << '\n';
    else
        cout << 0.5 << '\n';
}