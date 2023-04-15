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
    int n, t;
    std::cin >> n;
    std::vector<int> s(n);
    for (auto& x : s) std::cin >> x;
    std::cin >> t;
    sort(s.begin(), s.end());
    int prev = -1, cnt = 0;
    for (int i = 0; i < n; i++) {
        int cur = s[i] / t;
        cnt += (prev != cur);
        prev = cur;
    }
    std::cout << cnt << '\n';
}
