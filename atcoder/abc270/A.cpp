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
    int a, b;
    cin >> a >> b;
    int c = 0;
    if (a&1) {
        a -= 1;
        c += 1;
    }
    else if (b&1) {
        b -= 1;
        c += 1;
    }

    if (a >= 4) {
        a -= 4;
        c += 4;
    }
    else if (b >= 4) {
        b -= 4;
        c += 4;
    }

    if (a >= 2) {
        a -= 2;
        c += 2;
    }
    else if (b >= 2) {
        b -= 2;
        c += 2;
    }
    cout << c << '\n';
}