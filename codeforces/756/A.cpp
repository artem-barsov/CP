#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    std::string s;
    std::cin >> s;
    if ((s.back() - '0') & 1) {
        if ((s.front() - '0') & 1) {
            for (int i = 0; i < s.length(); i++) {
                if (!((s[i] - '0') & 1)) {
                    std::cout << 2 << '\n';
                    return;
                }
            }
            std::cout << -1 << '\n';
        }
        else std::cout << 1 << '\n';
    }
    else std::cout << 0 << '\n';
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
