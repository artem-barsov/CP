#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n;
    std::cin >> n;
    map<int, int> abils;
    int max_n = 0, max_ab = 0;
    for (int i = 0; i < n; i++) {
        int inp;
        std::cin >> inp;
        if (++abils[inp] > max_n) {
            max_n = abils[inp];
            max_ab = inp;
        }
    }
    if (max_n == abils.size()-1) return max_n;
    if ((max_n-1 == abils.size()) || (max_n-1 == abils.size()-1)) return max_n-1;
    return min(max_n, int(abils.size()));
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) std::cout << solve() << '\n';
}
