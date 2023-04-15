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
    int t, d, m;
    std::cin >> t >> d >> m;
    int prev = 0;
    bool ok = false;
    for (int i = 0; i < m; i++) {
        int y;
        std::cin >> y;
        ok |= (y - prev >= t);
        prev = y;
    }
    ok |= (d - prev >= t);
    std::cout << (ok ? 'Y' : 'N') << '\n';
}
