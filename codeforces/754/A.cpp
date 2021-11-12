#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int a1, a2, a3;
    std::cin >> a1 >> a2 >> a3;
    int s = abs((a1 + a3) - (2 * a2));
    std::cout << (s % 3 == 0 ? 0 : 1) << '\n';
}
// cerr delete
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
