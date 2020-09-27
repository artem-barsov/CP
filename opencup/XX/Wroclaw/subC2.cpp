#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int z, p, k;
    std::cin >> p >> k;
    std::vector<std::vector<int> > dp;
    dp.push_back(std::vector<int>(1, 1));
    std::vector<int> prev_even(1);
    std::vector<int> next_even(2);
    next_even[1] = 1;
    for (int i = 1; i <= p/2; i++) {
        std::vector<int> v(i+1);
        for (int j = 0; j < i+1; j++) {
            if (j < i) v[j] = next_even[j] + dp[i-1][j];
            else v[j] = 1;
            if (j > 0) {
                if (j < i) prev_even[j] = next_even[j] + v[j-1];
                else prev_even.push_back(next_even[j] + v[j-1]);
            }
            else prev_even[j] = 0;
        }
        prev_even.push_back(1);
        swap(prev_even, next_even);
        dp.push_back(v);
    }
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[i].size(); j++) {
            std::cout << dp[i][j] << ' ';
        }
        std::cout << '\n';
    }
    // int res = 0, koef = 1;
    // for (int i = 0; i < dp[p].size(); i++) {
    //     res = (res + dp[p][i] * koef) % p;
    //     koef = (koef*k*k) % p;
    // }
    // std::cout << res << ' ' << res % p << '\n';
}
