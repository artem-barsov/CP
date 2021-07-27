#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::vector<ull> a(n), b(n);
    for (auto& x : a) std::cin >> x;
    for (auto& x : b) std::cin >> x;
    sort(b.begin(), b.end());
    std::vector<ull> ans;
    for (int i = 0; i < n; i++) {
        if (i > 0 && b[i-1] == b[i]) continue;
        ull x = a[0] ^ b[i];
        std::vector<ull> c(n);
        for (size_t j = 0; j < n; j++)
            c[j] = a[j] ^ x;
        sort(c.begin(), c.end());
        if (b == c) ans.push_back(x);
    }
    sort(ans.begin(), ans.end());
    std::cout << ans.size() << '\n';
    for (auto& x : ans) std::cout << x << '\n';
}
