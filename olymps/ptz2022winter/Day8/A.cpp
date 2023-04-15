#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<long long, long long> > lh(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> lh[i].first >> lh[i].second;
        sum += lh[i].second;
        lh[i].second = -lh[i].second;
    }
    if (n == 2) {
        std::cout << "Yes" << '\n';
        return;
    }
    sort(lh.begin(), lh.end());
    for (int i = 0; i < n - 1; i++) {
        if (lh[i].first + lh[i].second + sum > lh[i+1].first) {
            std::cout << "No" << '\n';
            return;
        }
    }
    std::cout << "Yes" << '\n';
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
