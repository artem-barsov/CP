#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    if (t != "abc") {
        sort(s.begin(), s.end());
        std::cout << s << '\n';
    }
    else {
        std::map<char, int> let;
        for (char ch : s) let[ch]++;
        if (let['a'] == 0) {
            sort(s.begin(), s.end());
            std::cout << s << '\n';
            return;
        }
        std::string ans;
        ans += std::string(let['a'], 'a');
        ans += std::string(let['c'], 'c');
        ans += std::string(let['b'], 'b');
        for (auto& [ch, cnt] : let) {
            if (ch <= 'c') continue;
            ans += std::string(let[ch], ch);
        }
        std::cout << ans << '\n';
    }
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
