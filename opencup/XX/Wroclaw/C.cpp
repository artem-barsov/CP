#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int z, p, k;
    std::cin >> z;
    std::vector<std::vector<unsigned short> > dp;
    dp.push_back(std::vector<unsigned short>(1));
    dp.push_back(std::vector<unsigned short>(1));
    dp[1][0] = 1;
    while (z--) {
        std::cin >> p >> k;
        if (p > dp.size()-1) {
            for (int i = dp.size(); i <= p; i++) {
                std::vector<unsigned short> v((i+1)/2);
                for (int j = 0; j < (i+1)/2; j++) {
                    // v[j] = dp[i-2][j] + dp[i-1][j-1];
                    if (i&1) {
                        if (j != (i+1)/2-1) {
                            v[j] = dp[i-2][j];
                            if (j != 0) v[j] += dp[i-1][j-1];
                        }
                        else v[j] = 1;
                    }
                    else {
                        v[j] = dp[i-1][j];
                        if (j != (i+1)/2-1) v[j] += dp[i-2][j];
                    }
                }
                dp.push_back(v);
            }
        }
        int res = 0, koef = 1;
        for (int i = 0; i < dp[p].size(); i++) {
            res = (res + dp[p][i] * koef) % p;
            koef = (koef*k*k) % p;
        }
        std::cout << res << '\n';
    }
}
