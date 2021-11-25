#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int a, b;
    std::cin >> a >> b;
    if (a > b) swap(a, b);
    int ans = 0;
    int k = (b - a) / 2;
    ans += min(a, k);
    a -= ans;
    b -= 3 * ans;
    ans += min(a, b) / 2;
    std::cout << ans << '\n';
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
