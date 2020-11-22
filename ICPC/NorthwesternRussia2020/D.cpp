#include <bits/stdc++.h>

using namespace std;

int get_sw(std::string& line) {
    char state = '.';
    int c = 0;
    line += '.';
    for (int i = 0; i < line.length(); i++) {
        if (line[i] != state) {
            state = line[i];
            ++c;
        }
    }
    return c;
}

int main(int argc, char const *argv[]) {
    int n, w, h, s;
    std::cin >> n >> w >> h >> s;
    char max_ch;
    int max_sw = 0;
    for (int let = 0; let < n; let++) {
        char ch;
        std::cin >> ch;
        for (int i = 0; i < h; i++) {
            std::string line;
            std::cin >> line;
            int sw = get_sw(line);
            if (max_sw < sw) {
                max_sw = sw;
                max_ch = ch;
            }
        }
    }
    std::cout << std::string((s+max_sw-1)/max_sw, max_ch) << '\n';
}
