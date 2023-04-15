#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int x, y, z;
    cin >> x >> y >> z;
    if (x < 0) {
        x = -x;
        y = -y;
        z = -z;
    }
    if (y < 0 || x < y || (0 < z && z < y && y < x))
        cout << x << '\n';
    else if (z < 0)
        cout << -2*z + x << '\n';
    else
        cout << -1 << '\n';
}