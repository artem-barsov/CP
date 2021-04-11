#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> dp(n+1, 0);
    dp[0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = max(0, i-k); j < i; j++) {
            dp[i] = (dp[i] + dp[j]) % 1000000007;
        }
    }
    std::cout << dp[n];
}
