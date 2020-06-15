#include <bits/stdc++.h>

using namespace std;

void solve() {
    std::vector<std::string> sud(9);
    for (size_t i = 0; i < 9; i++) {
        std::cin >> sud[i];
    }
    std::cout << '\n';
    for (size_t i = 0; i < 8; i++) {
        sud[(i%3)*3 + i/3][i] = sud[(i%3)*3 + i/3 + 1][i];
        // std::cout << (i%3)*3 + i/3<< ',' << i << '=' << (i%3)*3 + i/3 + 1 << ',' << i << '\n';
    }
    // sud[0][0] = sud[1][0];
    // sud[3][1] = sud[4][1];
    sud[8][8] = sud[0][8];
    for (size_t i = 0; i < 9; i++) {
        std::cout << sud[i] << '\n';
    }
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
// 1
//
// 3! 5 4 | 8 7 3 | 2 9 6
// 3! 8 6 | 5! 9 2 | 7 1 4
// 7 2 9 | 6! 4 1 | 8! 3 5
// ---------------------
// 8 7! 3 | 7 2 5 | 1! 4 9
// 9 7! 5 | 3 1! 4 | 6 2 8
// 4 1 2 | 9 6! 8 | 3 5! 7
// ---------------------
// 6 3 1! | 4 5 7 | 9 8! 2
// 5 9 8! | 2 3 6! | 4 7 1
// 2 4 7 | 1 8 9! | 5 6 3
// +
