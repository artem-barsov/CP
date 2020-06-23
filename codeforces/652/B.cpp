#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    int pref = 0, postf = 0;
    while (s[pref] == '0') pref++;
    while (s[n-postf-1] == '1') postf++;
    std::cout << std::string(pref, '0') + std::string(n-pref-postf>0, '0') + std::string(postf, '1') << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
