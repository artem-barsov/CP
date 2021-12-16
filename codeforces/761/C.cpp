#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    std::vector<char> p(n + 1, false);
    std::map<int, int, std::greater<int> > news;
    for (auto& ai : a) {
        if (ai <= n && !p[ai])
            p[ai] = true;
        else
            news[(ai - 1) / 2]++;
    }
    int cnt = 0;
    for (int i = n; i >= 1; i--) {
        if (p[i]) continue;
        if (!news.empty() && news.begin()->first >= i) {
            cnt++;
            news.begin()->second--;
            if (news.begin()->second == 0)
                news.erase(news.begin());
        }
        else {
            std::cout << -1 << '\n';
            return;
        }
    }
    std::cout << cnt << '\n';
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
