#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

using ull = unsigned long long;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<ull> a(n);
    ull sum = 0;
    for (auto& x : a) {
        std::cin >> x;
        sum += x;
    }
    sort(a.begin(), a.end());
    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        ull x, y;
        std::cin >> x >> y;
        auto it2 = lower_bound(a.begin(), a.end(), x);
        bool ok1 = false, ok2 = false;
        ull att1, att2;
        if (it2 != a.end()) {
            att2 = *it2;
            ok2 = true;
        }
        if (it2 != a.begin()) {
            att1 = *(--it2);
            ok1 = true;
        }
        ull m1, m2;
        if (ok1)
            m1 = max(0ll, (long long)(x - att1)) + max(0ll, (long long)y - (long long)(sum-att1));
        if (ok2)
            m2 = max(0ll, (long long)y - (long long)(sum-att2));
        if (ok1 && ok2)
            std::cout << min(m1, m2) << '\n';
        else if (ok1)
            std::cout << m1 << '\n';
        else
            std::cout << m2 << '\n';
    }
}
