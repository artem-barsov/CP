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
    dp.push_back(std::vector<unsigned short>(1, 1));
    std::vector<unsigned short> prev_even(1);
    std::vector<unsigned short> next_even(2);
    next_even[1] = 1;
    while (z--) {
        std::cin >> p >> k;
        if (p/2 >= dp.size()) {
            for (int i = dp.size(); i <= p/2; i++) {
                std::vector<unsigned short> v(i+1);
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
        }
        int res = 0, koef = 1;
        for (int i = 0; i < dp[p/2].size(); i++) {
            res = (res + dp[p/2][i] * koef) % p;
            koef = (koef*k*k) % p;
        }
        std::cout << res % p << '\n';
    }
}
