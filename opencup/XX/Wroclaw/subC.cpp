#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int z, p, k;
    std::vector<std::vector<unsigned short> > dp;
    dp.push_back(std::vector<unsigned short>(1));
    dp.push_back(std::vector<unsigned short>(1));
    dp[1][0] = 1;
    std::cin >> p >> k;
    for (int i = 2; i <= p; i++) {
        std::vector<unsigned short> v((i+1)/2);
        for (int j = 0; j < (i+1)/2; j++) {
            if (i&1) {
                if (j != (i+1)/2-1) {
                    v[j] = dp[i-2][j];
                    if (j != 0) v[j] += dp[i-1][j-1];
                }
                else v[j] = dp[i-1][j-1]; // = 1
            }
            else {
                v[j] = dp[i-1][j];
                if (j != (i+1)/2-1) v[j] += dp[i-2][j];
            }
        }
        dp.push_back(v);
    }
    for (size_t i = 0; i < dp.size(); i++) {
        std::cout << i << ":\t";
        for (size_t j = 0; j < dp[i].size(); j++) {
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
