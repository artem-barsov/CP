#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int matchings(int n, std::vector<std::pair<int, int> >& edges) {
    std::vector<char> dp(1 << n, false);
    dp[0] = true;
    int ret = 0;
    for (unsigned int mask = 1; mask < (1<<n); mask++) {
        for (auto [u, v] : edges) {
            if (((mask>>u)&1) && ((mask>>v)&1)) {
                if (dp[mask] |= dp[mask - (1<<u) - (1<<v)])
                    ret = max(ret, popcount(mask));
            }
        }
    }
    return ret;
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int> > edges;
    std::vector<std::string> input{std::istream_iterator<std::string>(cin),
                                   std::istream_iterator<std::string>()};
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (input[i][j] == 'Y') edges.emplace_back(i, j);
        }
    }
    std::cout << matchings(n, edges) << '\n';
}
