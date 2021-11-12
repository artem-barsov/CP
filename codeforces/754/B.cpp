#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<int> ans1;
    std::deque<int> ans2;
    for (int l = 0, r = n-1;; l++, r--) {
        while (l < n && s[l] != '1') l++;
        while (0 <= r && s[r] != '0') r--;
        if (l > r) break;
        ans1.push_back(l);
        ans2.push_front(r);
    }
    if (ans1.empty()) {
        std::cout << 0 << '\n';
        return;
    }
    std::cout << 1 << '\n';
    std::cout << 2 * ans1.size() << ' ';
    for (auto& x : ans1) std::cout << x + 1 << ' ';
    for (auto& x : ans2) std::cout << x + 1 << ' ';
    std::cout << '\n';
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
