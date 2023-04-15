#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void sh_r(std::vector<std::string>& txt) {
    for (auto& l : txt) {
        char last = l.back();
        for (int i = l.length() - 1; i >= 1; i--)
            l[i] = l[i-1];
        l[0] = last;
    }
}

void sh_d(std::vector<std::string>& txt) {
    std::string last = txt.back();
    for (int i = txt.size() - 1; i >= 1; i--)
        txt[i] = txt[i-1];
    txt[0] = last;
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    std::vector<std::string> pat = {
        {"####...###..#...#.###.####."},
        {"#...#.#.....#...#..#..#...#"},
        {"#...#.#.....#...#..#..#...#"},
        {"####...###..#...#..#..####."},
        {"#...#.....#.#...#..#..#.#.."},
        {"#...#.....#.#...#..#..#..#."},
        {"####...###...###..###.#...#"} };
    std::vector<std::string> inp{std::istream_iterator<std::string>(cin),
                                 std::istream_iterator<std::string>()};
    swap(inp, pat);
    for (int x = 1; x <= 27; x++) {
        sh_r(inp);
        for (int y = 1; y <= 7; y++) {
            sh_d(inp);
            if (inp == pat) {
                std::cout << y%7 << ' ' << x%27 << '\n';
                return 0;
            }
        }
    }
}
