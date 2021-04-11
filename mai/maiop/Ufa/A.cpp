#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<int> dp(n+1, INT_MAX);
    dp[0] = INT_MIN;
    std::vector<int> p(n+1, -1);
    std::vector<int> pred(n);
    for (size_t i = 0; i < n; i++) {
        int j = std::distance(dp.begin(), upper_bound(dp.begin(), dp.end(), a[i]));
        if (dp[j-1] < a[i] && a[i] < dp[j]) {
            dp[j] = a[i];
            p[j] = i;
            pred[i] = p[j-1];
        }
    }
    int idx;
    for (int i = dp.size()-1; i >= 0; i--) {
        if (dp[i] != INT_MAX) {
            idx = i;
            break;
        }
    }
    int s1_len = idx;
    std::vector<bool> is_s1(n, false);
    idx = p[idx];
    while (idx != -1) {
        is_s1[idx] = true;
        idx = pred[idx];
    }
    int last = -1;
    for (size_t i = 0; i < a.size(); i++) {
        if (!is_s1[i]) {
            if (a[i] < last) {
                std::cout << -1 << '\n';
                return 0;
            } else {
                last = a[i];
            }
        }
    }
    std::cout << 2*s1_len - n << '\n';
}
