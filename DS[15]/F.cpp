#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, l;
    std::cin >> n >> l;
    int fernste = 0;
    for (int i = 0; i < n; i++) {
        int pos;
        char dir;
        std::cin >> pos >> dir;
        fernste = max(fernste, (dir=='L') ? pos : l-pos);
    }
    std::cout << fernste << '\n';
}
