#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int l, r;
    std::cin >> l >> r;
    std::vector<int> dp(r+1, 0);
    dp[1] = 1;
    for (int i = 1; i <= r; i++) {
        for (int j = i*2; j <= r; j += i) {
            dp[j] += dp[i] % 1000000007;
        }
    }
    int sum = 0;
    for (size_t i = l; i <= r; i++)
        sum = (sum + dp[i]) % 1000000007;
    std::cout << sum;
}
