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
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<int> digs(10);
    for (char ch : s) digs[ch - '0']++;
    std::string ans;
    char c = 0;
    for (int i = 9; i >= 1; i--) {
        ans += std::string(digs[i] / 2, '0' + i);
        if (!c && (digs[i] & 1)) c = '0' + i;
    }
    std::cout << ans;
    if (c) std::cout << c;
    std::reverse(ans.begin(), ans.end());
    std::cout << ans << '\n';
}
