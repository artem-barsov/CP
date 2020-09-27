#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int r, c, v, h;
    std::cin >> r >> c >> v >> h;
    std::vector<int> heights(v), widths(h);
    for (int i = 0; i < v; i++) {
        std::cin >> heights[i];
        if (i > 0) heights[i] += heights[i-1];
    }
    for (int i = 0; i < h; i++) {
        std::cin >> widths[i];
        if (i > 0) widths[i] += widths[i-1];
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            std::cout << (((upper_bound(widths.begin(), widths.end(), j)-widths.begin()) + (upper_bound(heights.begin(), heights.end(), i)-heights.begin())) & 1 ? 'W' : 'B');
        }
        std::cout << '\n';
    }
}
