#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> v(m, 0);
    std::vector<std::vector<unsigned short>> dp(n+1, std::vector<unsigned short>(m+1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = (dp[i][j] + dp[max(i-1, 0)][j] + dp[i][max(j-1, 0)]) % 1000000007;
        }
    }
    std::cout << dp[n][m]/3 << '\n';
}
