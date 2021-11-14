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
    int n;
    std::cin >> n;
    std::map<int, int> d;
    for (int i = 0; i < n; i++) {
        int di;
        std::cin >> di;
        d[di]++;
    }
    int ans = 0;
    for (auto& x : d) ans = max(ans, x.second);
    std::cout << ans << '\n';
}
