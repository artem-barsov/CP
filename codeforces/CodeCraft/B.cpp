#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::string minsub = s;
    for (int i = 0; i < n; i++) {
        minsub = min(minsub, s.substr(i));
    }
    int k = n - minsub.length() + 1;
    if ((n+k)&1) {
        std::cout << minsub + s.substr(0, k-1) << '\n';
    }
    else {
        std::string revsuf = s.substr(0, k-1);
        reverse(revsuf.begin(), revsuf.end());
        std::cout << minsub + revsuf << '\n';
    }
    std::cout << k << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) solve();
}
// std::string a = "abab";
// std::string s = "ab";
// std::cout << min(a, s) << '\n';
// std::cout << a.substr(5) << '\n';
// reverse(s.begin()+1, s.end()-1);
// std::cout << s << '\n';
