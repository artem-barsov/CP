#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::vector<tuple<int, int, int> > seq(n);
    for (auto& [a, l, r] : seq) {
        std::cin >> a >> l >> r;
    }
    sort(seq.begin(), seq.end(),
    [&](const tuple<int, int, int>& lhs, const tuple<int, int, int>& rhs) {
        if (get<0>(lhs) != get<0>(rhs))
            return get<0>(lhs) < get<0>(rhs);
        if (get<1>(lhs) != get<1>(rhs))
            return get<1>(lhs) > get<1>(rhs);
        return get<2>(lhs) < get<2>(rhs);
    });
    std::vector<int> ans;
    int last = -1, rep = 0;
    for (auto& [a, l, r] : seq) {
        if (a == last) rep++;
        else           rep = 0;
        last = a;
        if (l + r + rep != ans.size()) {
            std::cout << "No" << '\n';
            return;
        }
        ans.insert(ans.begin() + l, a);
    }
    std::cout << "Yes" << '\n';
    for (auto& x : ans)
        std::cout << x << ' ';
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
