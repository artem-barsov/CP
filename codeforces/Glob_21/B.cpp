#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    bool tocnt = true;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        if (a != 0) {
            if (tocnt) {
                cnt++;
                tocnt = false;
            }
        }
        else tocnt = true;
    }
    std::cout << min(2, cnt) << '\n';
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
