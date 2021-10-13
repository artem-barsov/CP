#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << max(0, max(b, c) - a + 1) << ' ';
    std::cout << max(0, max(a, c) - b + 1) << ' ';
    std::cout << max(0, max(a, b) - c + 1) << '\n';
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
