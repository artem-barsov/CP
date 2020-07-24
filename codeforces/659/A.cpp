#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::vector<std::string> s;
    s.push_back(std::string(max(1, a[0]), 'a'));
    std::cout << s.back() << '\n';
    for (int i = 0; i < n; i++) {
        if (a[i] > s.back().length()) {
            s.back() += std::string(a[i]-s.back().length(), 'a');
            s.push_back(s.back());
        }
        else if (a[i] < s.back().length()) {
            std::string new_s = s.back();
            new_s[a[i]]++;
            if (new_s[a[i]] > 'z') new_s[a[i]] = 'a';
            s.push_back(new_s);
        }
        else {
            s.push_back(s.back());
        }
    }
    for (int i = 1; i < s.size(); i++)
        std::cout << s[i] << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
