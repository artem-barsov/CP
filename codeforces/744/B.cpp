#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    std::queue<tuple<int, int, int>> qout;
    for (int r = n; r > 0; r--) {
        int maxel = a[0], maxpos = 0;
        for (int i = 0; i < r; i++) {
            if (maxel < a[i]) {
                maxel = a[i];
                maxpos = i;
            }
        }
        a.push_back(maxel);
        a.erase(a.begin() + maxpos);
        if (maxpos + 1 != r)
            qout.push({maxpos+1, r, 1});
    }
    std::cout << qout.size() << '\n';
    while (!qout.empty()) {
        auto [l, r, d] = qout.front();
        std::cout << l << ' ' << r << ' ' << d << '\n';
        qout.pop();
    }
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) solve();
}
