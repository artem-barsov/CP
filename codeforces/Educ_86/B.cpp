#include <bits/stdc++.h>

using namespace std;

void solve() {
    std::string t;
    std::cin >> t;
    for (int i = 0; i < t.length()-1; i++) {
        if (t[i] != t[i+1]) {
            for (int j = 0; j < t.length(); j++)
                std::cout << "01";
            std::cout << '\n';
            return;
        }
    }
    std::cout << t << '\n';
}

int main(int argc, char const *argv[]) {
    int T;
    std::cin >> T;
    while (T--) solve();
}
