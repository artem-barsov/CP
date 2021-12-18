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
    int n, k;
    std::cin >> n >> k;
    std::set<int> sa;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        sa.insert(a);
    }
    if (k == 0) {
        std::cout << n << '\n';
        return 0;
    }
    auto cur = sa.begin();
    int cnt = 1;
    for (auto nxt = std::next(cur); nxt != sa.end();) {
        if ((*nxt - *cur) < k) {
            nxt++;
        }
        else {
            cur = nxt;
            nxt++;
            cnt++;
        }
    }
    std::cout << cnt << '\n';
}
