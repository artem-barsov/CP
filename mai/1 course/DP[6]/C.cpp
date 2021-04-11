#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, k, m;
    std::cin >> n >> k >> m;
    std::vector<int> gefahr(n, 0);
    for (size_t i = 0; i < m; i++) {
        int idx;
        std::cin >> idx;
        gefahr[idx] = 1;
    }
    std::vector<int> dp(n+1, 0);
    dp[0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = max(0, i-k); j < i; j++) {
            if (!gefahr[j])
                dp[i] = (dp[i] + dp[j]) % 1000000007;
        }
    }
    std::cout << dp[n];
}
