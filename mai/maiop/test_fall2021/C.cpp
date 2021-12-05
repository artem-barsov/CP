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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    std::vector<int> bx(101);
    for (int i = 0; i < m; i++) {
        int bi;
        std::cin >> bi;
        bx[bi]++;
    }
    std::vector<int> ax(101);
    for (int i = 0; i < m; i++) ax[a[i]]++;
    std::vector<int> ans;
    if (ax == bx) ans.push_back(0);
    for (int l = 0, r = m; r < n; l++, r++) {
        ax[a[l]]--;
        ax[a[r]]++;
        if (ax == bx) ans.push_back(l + 1);
    }
    std::cout << ans.size() << '\n';
    for (auto x : ans) std::cout << x + 1 << ' ';
    std::cout << '\n';
}
