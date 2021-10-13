#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    std::string s;
    std::cin >> s;
    if (stoll(s) % 25 == 0) {
        std::cout << 0 << '\n';
        return;
    }
    reverse(s.begin(), s.end());
    std::vector<std::string> ff = {"00", "25", "50", "75"};
    int ans = INT_MAX;
    for (int i = 0; i < ff.size(); i++) {
        int p = 1;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == ff[i][p]) {
                if (p) p--;
                else {
                    ans = min(ans, j - 1);
                }
            }
        }
    }
    std::cout << ans << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    std::cin >> t;
    while (t--) solve();
}
