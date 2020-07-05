#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<std::vector<bool> > columns(n, std::vector<bool>(n));
    int trace = 0, r = 0, c = 0;
    for (int i = 0; i < n; i++) {
        std::vector<bool> row(n);
        for (int j = 0; j < n; j++) {
            int x;
            std::cin >> x;
            if (i == j) trace += x;
            row[x-1] = true;
            columns[j][x-1] = true;
        }
        for (int j = 0; j < n; j++) {
            if (!row[j]) {
                r++;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!columns[i][j]) {
                c++;
                break;
            }
        }
    }
    std::cout << trace << ' ' << r << ' ' << c << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}
