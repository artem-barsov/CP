#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

int n, m, k;

int cntStars(std::vector<std::string>& a) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ret += a[i][j] == '*';
        }
    }
    return ret;
}

int go(std::vector<std::string>& a, int si, int sj) {
    int ret = 0;
    int l = 1;
    for (; si-l>=0 && sj-l>=0 && sj+l<m; l++) {
        if (a[si-l][sj-l] == '.' || a[si-l][sj+l] == '.')
            break;
    }
    if (l <= k) return 0;
    a[si][sj] = '#';
    ret++;
    for (int i = 0; si-i>=0 && sj-i>=0 && sj+i<m; i++) {
        if (a[si-i][sj-i] != '.' && a[si-i][sj+i] != '.') {
            if (a[si-i][sj-i] == '*') {
                ret++;
                a[si-i][sj-i] = '#';
            }
            if (a[si-i][sj+i] == '*') {
                ret++;
                a[si-i][sj+i] = '#';
            }
        }
        else break;
    }
    return ret;
}

void solve() {
    std::cin >> n >> m >> k;
    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int stars = cntStars(a);
    for (int i = k; i < n; i++) {
        for (int j = k; j < m-k; j++) {
            if (a[i][j] == '*') {
                stars -= go(a, i, j);
            }
        }
    }
    std::cout << (stars ? "NO" : "YES") << '\n';
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) solve();
}
