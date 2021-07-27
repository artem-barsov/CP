#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main(int argc, char const *argv[]) {
    int n, k;
    std::cin >> n >> k;
    std::vector<char> a(n+1, '0');
    int x = 0;
    for (size_t i = 1; i <= k; i++) {
        char c; int k;
        std::cin >> c >> k;
        a[k] = c;
        x += c == 'R';
    }
    unsigned long long ans = 1;
    for (size_t i = 1; i <= n; i++) {
        if (a[i] == '0')
            ans = (ans *1ull* x) % MOD;
        else
            x += ((a[i] == 'L') ? +1 : -1);
    }
    std::cout << ans << '\n';
}
