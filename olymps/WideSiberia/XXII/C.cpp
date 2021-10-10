#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<long long> > a(n, std::vector<long long>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];
    std::vector<std::vector<long long> > dp(n, std::vector<long long>(m));
    dp[n-1][m-1] = a[n-1][m-1];
    for (int i = n-2; i >= 0; i--)
        dp[i][m-1] = dp[i+1][m-1] + a[i][m-1];
    for (int i = m-2; i >= 0; i--)
        dp[n-1][i] = dp[n-1][i+1] + a[n-1][i];
    for (int i = n-2; i >= 0; i--) {
        for (int j = m-2; j >= 0; j--) {
            dp[i][j] = a[i][j] + (((i + j) & 1)
                ? min(dp[i][j+1], dp[i+1][j])
                : max(dp[i][j+1], dp[i+1][j]));
        }
    }

    int pi = 0, pj = 0;
    long long sum = 0;
    for (int i = 0; i < n + m - 2; i++) {
        if (i & 1) {
            char resp;
            std::cin >> resp;
            sum += a[pi][pj];
            if (resp == 'R') pj++;
            else             pi++;
        }
        else {
            std::cout << sum + dp[pi][pj] << ' ';
            sum += a[pi][pj];
            if (pi == n-1) {
                std::cout << 'R' << endl;
                pj++;
            }
            else if (pj == m-1) {
                std::cout << 'D' << endl;
                pi++;
            }
            else if (dp[pi][pj+1] > dp[pi+1][pj]) {
                std::cout << 'R' << endl;
                pj++;
            }
            else {
                std::cout << 'D' << endl;
                pi++;
            }
        }
    }
}
