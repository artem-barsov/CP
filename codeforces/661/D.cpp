#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<int> zeros, ones, a(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (ones.empty()) {
                zeros.push_back(zeros.size()+1);
            }
            else {
                zeros.push_back(ones.back());
                ones.pop_back();
            }
            a[i] = zeros.back();
        }
        else {
            if (zeros.empty()) {
                ones.push_back(ones.size()+1);
            }
            else {
                ones.push_back(zeros.back());
                zeros.pop_back();
            }
            a[i] = ones.back();
        }
    }
    std::cout << zeros.size() + ones.size() << '\n';
    for (auto ai : a) std::cout << ai << ' ';
    std::cout << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
