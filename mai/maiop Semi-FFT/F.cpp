#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int t; std::cin >> t;
    for (int i = 0; i < t; ++i) {
        int s = 0;
        std::string s1, s2, c1, c2;
        std::cin >> s >> s1 >> s2;
        c1.reserve(s);
        c2.reserve(s);
        for (int k = 0; k < s; ++k) {
            if (s1[k] != s2[k]) {
                c1.push_back(s1[k]);
                c2.push_back(s2[k]);
            }
        }
        if (c1.empty()
        || (std::equal(c1.begin() + 1, c1.end(), c2.begin()) && (c1.front() == c2.back()))) {
            std::cout << "YES\n";
        }
        else {
            std::cout << "NO\n";
        }
    }
}
