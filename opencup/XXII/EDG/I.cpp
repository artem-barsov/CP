#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    s = '$' + s;
    long long c = 0, ans = 0;
    for (int i = n; i >= 1; i--) {
        if (s[i] == '0' || !c) c++;
        else {
            ans += i;
            c--;
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
