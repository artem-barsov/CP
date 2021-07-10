#include <bits/stdc++.h>

using namespace std;

const unsigned long long MOD = 1e9+7;

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] < i+1) {
            std::cout << 0 << '\n';
            return 0;
        }
        ans = (ans *1ul* (a[i]-i)) % MOD;
    }
    std::cout << ans << '\n';
}
