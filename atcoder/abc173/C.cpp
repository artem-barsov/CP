#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int h, w, k;
    std::cin >> h >> w >> k;
    std::vector<std::string> field(h);
    for (size_t i = 0; i < h; i++) {
        std::cin >> field[i];
    }
    int bf = 0;
    int nVars = h + w;
    int nChoices = 0;
    while (bf <= ((1 << nVars) - 1)) {
        bitset<12> bs = bf;
        int nBlack = 0;
        for (size_t i = 0; i < h; i++) {
            if (!bs[i]) continue;
            for (size_t j = 0; j < w; j++) {
                if (!bs[h+j]) continue;
                if (field[i][j] == '#') nBlack++;
            }
        }
        if (nBlack == k) nChoices++;
        bf++;
    }
    std::cout << nChoices << '\n';
}
